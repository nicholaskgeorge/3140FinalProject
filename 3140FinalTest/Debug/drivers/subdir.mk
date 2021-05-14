################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_dma.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_i2c_dma.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_lpsci_dma.c \
../drivers/fsl_lptmr.c \
../drivers/fsl_smc.c \
../drivers/fsl_spi.c \
../drivers/fsl_spi_dma.c \
../drivers/fsl_uart.c \
../drivers/fsl_uart_dma.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dma.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_i2c_dma.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_lpsci_dma.o \
./drivers/fsl_lptmr.o \
./drivers/fsl_smc.o \
./drivers/fsl_spi.o \
./drivers/fsl_spi_dma.o \
./drivers/fsl_uart.o \
./drivers/fsl_uart_dma.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dma.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_i2c_dma.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_lpsci_dma.d \
./drivers/fsl_lptmr.d \
./drivers/fsl_smc.d \
./drivers/fsl_spi.d \
./drivers/fsl_spi_dma.d \
./drivers/fsl_uart.d \
./drivers/fsl_uart_dma.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DDEBUG -DCPU_MKL25Z128VLK4 -DFRDM_KL25Z -DFREEDOM -DPRINTF_ADVANCED_ENABLE -DCPU_MKL25Z128VLK4_cm0plus -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -D__REDLIB__ -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/board" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/source" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/CMSIS_driver" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/CMSIS" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/drivers" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/utilities" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/startup" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/gpio_driver" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/interface" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/sensors" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


