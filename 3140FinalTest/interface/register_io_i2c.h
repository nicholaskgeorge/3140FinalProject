/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file register_io_i2c.h
 * @brief The register_io_i2c.h file declares low-level interface functions for reading
 *  and writing sensor registers.
 */

#ifndef __REGISTER_IO_I2C_H__
#define __REGISTER_IO_I2C_H__

#include "sensor_drv.h"
#include "Driver_I2C.h"

#if defined(I2C0)
/*! @brief The I2C0 device index. */
#define I2C0_INDEX 0

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C0_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C1)
/*! @brief The I2C1 device index. */
#define I2C1_INDEX 1

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C1_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C2)
/*! @brief The I2C2 device index. */
#define I2C2_INDEX 2

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C2_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C3)
/*! @brief The I2C3 device index. */
#define I2C3_INDEX 3

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C3_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C4)
/*! @brief The I2C4 device index. */
#define I2C4_INDEX 4

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C4_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C5)
/*! @brief The I2C5 device index. */
#define I2C5_INDEX 5

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C5_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C6)
/*! @brief The I2C6 device index. */
#define I2C6_INDEX 6

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C6_SignalEvent_t(uint32_t event);
#endif

#if defined(I2C7)
/*! @brief The I2C7 device index. */
#define I2C7_INDEX 7

/*! @brief       Defines the I2C signal event handler.
 *  @details     The Signal Event Handler function required by register_io_i2c.c.
 *  @param[in]   event The I2C event that occured.
 *  @Constraints None
 *  @Reentrant   Yes
 *  @return      void
 */
void I2C7_SignalEvent_t(uint32_t event);
#endif

/*!
 * @brief The interface function to write a sensor register.
 *
 * @param ARM_DRIVER_I2C *pCommDrv - The I2C driver to use.
 * @param registerDeviceInfo_t *devInfo - The I2C device number and idle function.
 * @param uint16_t slaveAddress - the sensor's I2C slave address.
 * @param uint8_t offset - The register/offset to write to.
 * @param uint8_t *pBuffer - The buffer containing bytes to write.
 * @param uint8_t bytesToWrite - A number of bytes to write.
 *
 * @return ARM_DRIVER_OK if success or ARM_DRIVER_ERROR if error.
 */
int32_t Register_I2C_BlockWrite(ARM_DRIVER_I2C *pCommDrv,
                                registerDeviceInfo_t *devInfo,
                                uint16_t slaveAddress,
                                uint8_t offset,
                                const uint8_t *pBuffer,
                                uint8_t bytesToWrite);

/*!
 * @brief The interface function to write a sensor register.
 *
 * @param ARM_DRIVER_I2C *pCommDrv - The I2C driver to use.
 * @param registerDeviceInfo_t *devInfo - The I2C device number and idle function.
 * @param uint16_t slaveAddress - the sensor's I2C slave address.
 * @param uint8_t offset - The register/offset to write to
 * @param uint8_t value - The value to write to the register
 * @param uint8_t mask - A mask value to use when writing.
 *                       A non-zero mask indicates that a read-modify-write operation should be used.
 *                       where only the bits set in the mask will be updated according to the value param.
 * @param bool repeatedStart - Indicates whether to send STOP or REPEATED_START bit after the write
 *
 * @return ARM_DRIVER_OK if success or ARM_DRIVER_ERROR if error.
 */
int32_t Register_I2C_Write(ARM_DRIVER_I2C *pCommDrv,
                           registerDeviceInfo_t *devInfo,
                           uint16_t slaveAddress,
                           uint8_t offset,
                           uint8_t value,
                           uint8_t mask,
                           bool repeatedStart);

/*!
 * @brief The interface function to read a sensor register.
 *
 * @param ARM_DRIVER_I2C *pCommDrv - The I2C driver to use.
 * @param registerDeviceInfo_t *devInfo - The I2C device number and idle function.
 * @param uint16_t slaveAddress - the sensor's I2C slave address.
 * @param uint8_t offset - The register/offset to read from
 * @param uint8_t length - The number of bytes to read
 * @param uint8_t *pOutBuffer - The pointer to the buffer to store the register value read.
 *
 * @return ARM_DRIVER_OK if success or ARM_DRIVER_ERROR if error.
 */
int32_t Register_I2C_Read(ARM_DRIVER_I2C *pCommDrv,
                          registerDeviceInfo_t *devInfo,
                          uint16_t slaveAddress,
                          uint8_t offset,
                          uint8_t length,
                          uint8_t *pOutBuffer);

#endif // __REGISTER_IO_I2C_H__
