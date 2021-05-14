/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 */

//-----------------------------------------------------------------------
// SDK Includes
//-----------------------------------------------------------------------
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

//-----------------------------------------------------------------------
// CMSIS Includes
//-----------------------------------------------------------------------
#include "Driver_I2C.h"

/* ISSDK Includes */
#include "issdk_hal.h"
#include "mma845x_drv.h"

//-----------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------
/*! @def    FIFO_SIZE
 *  @brief  The watermark value configured for MMA845x FIFO Buffer.
 */
#define FIFO_SIZE 4 // Must be between 1 - 32

//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------
/*! Prepare the register write list to configure MMA845x in FIFO mode. */
const registerwritelist_t mma845x_Config_Fifo[] = {
    /*! Configure the MMA845x CTRL_REG1 to set mode to STANDBY and odr to 12.5Hz. */
    {MMA845x_CTRL_REG1, MMA845x_CTRL_REG1_MODE_STANDBY | MMA845x_CTRL_REG1_DR_12DOT5HZ, 0},
    /*! Configure the MMA845x F_SETUP to set FIFO mode to STOP, set the watermark size to FIFO_SIZE. */
    {MMA845x_F_SETUP, MMA845x_F_SETUP_F_MODE_FIFOSTOP | FIFO_SIZE, 0},
    /*! Configure the MMA845x CTRL_REG2 to set the Oversampling mode to High Resolution. */
    {MMA845x_CTRL_REG2, MMA845x_CTRL_REG2_SMODS_HIGHRES, 0},
    __END_WRITE_DATA__};

/*! Prepare the register read list to read the FIFO event from MMA845x. */
const registerreadlist_t mma845x_Fifo_Status[] = {{.readFrom = MMA845x_F_STATUS, .numBytes = 1}, __END_READ_DATA__};

/*! Prepare the register read list to read the raw Accel data from MMA845x. */
const registerreadlist_t mma845x_Output_Values[] = {
    {.readFrom = MMA845x_OUT_X_MSB, .numBytes = MMA845x_ACCEL_DATA_SIZE * FIFO_SIZE}, __END_READ_DATA__};

//-----------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------
unsigned int loadValue = 62914560; //10485760*6 for ~six seconds initially
unsigned int numSwitch = 0;
unsigned int condition; //message sent by Python to know if image and board tilt correct
signed int OG_X;
signed int OG_Y;
signed int OG_Z;
signed int current_X;
signed int current_Y;
signed int current_Z;
unsigned int once_marker=0;


//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------


void delay(void){ //delay function taken from previous labs
	int j;
	for(j=0; j<1000000; j++);
}

/*
   PIT Interrupt Handler
*/
void PIT_IRQHandler(void) {
	//INTERRUPT OCCURRED (TEST)
	PRINTF("\r\n INTERRUPT HAPPENED!!!!!!!!!!! \r\n");

	//increment global switch count
	numSwitch=numSwitch+1;

	//check if 5 switches have occurred
	if((numSwitch==5)&&(loadValue>0)){
		loadValue=loadValue-10485760; //decrement it by ~one second to speed game up
		numSwitch=0;				  //reset switches back to 0
	}

	//SEND MESSAGE TO PORT FOR PYTHON TO READ, tell it to randomly choose image and send back int

	//SPECS FOR TURNS:
		//A SUCCESSFUL RIGHT TURN IS WHEN CURRENT X ~= OG_X-20
		//A SUCCESSFUL LEFT TURN IS WHEN CURRENT X ~=OG_X+20

	int testingRightLeft=1; //testing a successful right(1)/left(0) turn

	PRINTF("\r\n RIGHT OR LEFT = %d \r\n", testingRightLeft);
	delay();

	if(testingRightLeft==1){ //image will be of right turn
		//make sure the X decreased but also the Y and Z didn't change too much
		if(current_X<=OG_X-10 && current_Y>=OG_Y-15 && current_Y<=OG_Y+15 && current_Z>=OG_Z-15 && current_Z<=OG_Z+15){
			PRINTF("\r\n NICE RIGHT TURN!!!!!!!! \r\n");
		}
		else{
			PRINTF("\r\n FIX UR SPECS OMG ITS WRONG!!!!!!!! \r\n");
		}
		testingRightLeft=0;
	}

	if(testingRightLeft==1){ //image will be of left turn
			//make sure the X increased but also the Y and Z didn't change too much
			if(current_X>=OG_X+10 && current_Y>=OG_Y-15 && current_Y<=OG_Y+15 && current_Z>=OG_Z-15 && current_Z<=OG_Z+15){
				PRINTF("\r\n NICE LEFT TURN!!!!!!!! \r\n");
			}
			else{
				PRINTF("\r\n FIX UR SPECS OMG ITS WRONG!!!!!!!! \r\n");
			}
			testingRightLeft=1;
		}



	PIT->CHANNEL[0].TCTRL |= ~PIT_TCTRL_TEN_MASK; //disable Timer 0
	PIT->CHANNEL[0].LDVAL = (loadValue); // Set load value of zeroth PIT
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; //start Timer 0
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK; //set TFLG back to 1


}







/*!
 * @brief Main function
 */
int main(void)
{
    int32_t status;
    uint8_t fifoEvent;
    uint8_t data[MMA845x_ACCEL_DATA_SIZE * FIFO_SIZE];
    mma845x_acceldata_t rawData;

    ARM_DRIVER_I2C *I2Cdrv = &I2C_S_DRIVER; // Now using the shield.h value!!!
    mma845x_i2c_sensorhandle_t MMA845xdrv;

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();


    /*! Initialize the I2C driver. */
    status = I2Cdrv->Initialize(I2C_S_SIGNAL_EVENT);
    if (ARM_DRIVER_OK != status){return -1;}//I2C Initialization Failed

    /*! Set the I2C Power mode. */
    status = I2Cdrv->PowerControl(ARM_POWER_FULL);
    if (ARM_DRIVER_OK != status)  {return -1;}  //I2C Power Mode setting Failed

    /*! Set the I2C bus speed. */
    status = I2Cdrv->Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
    if (ARM_DRIVER_OK != status){return -1;}//I2C Control Mode setting Failed

    /*! Initialize the MMA845x sensor driver. */
    status = MMA845x_I2C_Initialize(&MMA845xdrv, &I2C_S_DRIVER, I2C_S_DEVICE_INDEX, MMA845x_I2C_ADDR,
                                    MMA8451_WHO_AM_I_WHOAMI_VALUE);

    if (SENSOR_ERROR_NONE != status){return -1;}//Sensor Initialization Failed


    /*!  Set the task to be executed while waiting for I2C transactions to complete. */
    MMA845x_I2C_SetIdleTask(&MMA845xdrv, (registeridlefunction_t)SMC_SetPowerModeWait, SMC);

    /*! Configure the MMA845x sensor driver with FIFO mode. */
    status = MMA845x_I2C_Configure(&MMA845xdrv, mma845x_Config_Fifo);
    if (SENSOR_ERROR_NONE != status){return -1;}//MMA845x Sensor Configuration Failed

    //Set up Timer 0!!
    NVIC_EnableIRQ(PIT_IRQn);
    SIM->SCGC6 = SIM_SCGC6_PIT_MASK; // Enable clock to PIT module
   	PIT->MCR &= (0 << 30); //Activate the PIT Module
   	PIT->CHANNEL[0].LDVAL = (loadValue); // Set load value of zeroth PIT
   	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK; //start Timer 0
   	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK; //enable Timer 0 for interrupts

    for (;;) /* Forever loop */
    {
        /*! Wait for data ready from the MMA845x. */
        status = MMA845x_I2C_ReadData(&MMA845xdrv, mma845x_Fifo_Status, &fifoEvent);
        if (0 == (fifoEvent & MMA845x_F_STATUS_F_WMRK_FLAG_MASK))
        { /* Loop, if new sample is not available. */
            continue;
        }

        /*! Read the raw sensor data from the MMA845x. */
        status = MMA845x_I2C_ReadData(&MMA845xdrv, mma845x_Output_Values, data);
        if (ARM_DRIVER_OK != status){return -1;}//Read Failed

        for (uint8_t i = 0; i < FIFO_SIZE; i++)
        {
            /*! Convert the raw sensor data to signed 16-bit container for display to the debug port. */
            rawData.accel[0] =
                ((int16_t)data[i * MMA845x_ACCEL_DATA_SIZE + 0] << 8) | data[i * MMA845x_ACCEL_DATA_SIZE + 1];
            rawData.accel[0] /= 4;
            rawData.accel[1] =
                ((int16_t)data[i * MMA845x_ACCEL_DATA_SIZE + 2] << 8) | data[i * MMA845x_ACCEL_DATA_SIZE + 3];
            rawData.accel[1] /= 4;
            rawData.accel[2] =
                ((int16_t)data[i * MMA845x_ACCEL_DATA_SIZE + 4] << 8) | data[i * MMA845x_ACCEL_DATA_SIZE + 5];
            rawData.accel[2] /= 4;
        }
        /* NOTE: PRINTF is relatively expensive in terms of CPU time, specially when used with-in execution loop.
         * Hence, we display only the last sample from each FIFO Burst Read. */

        if(once_marker==0){
        	OG_X=rawData.accel[0];
        	OG_Y=rawData.accel[1];
        	OG_Z=rawData.accel[2];
        }
        once_marker=1;
        current_X=rawData.accel[0];
        current_Y=rawData.accel[1];
        current_Z=rawData.accel[2];

        PRINTF("\r\n Curr_Accel X = %d  Y = %d  Z = %d\r\n", current_X, current_Y, current_Z);

    }
}
