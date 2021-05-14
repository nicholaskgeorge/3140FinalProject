################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_debug_console.c \
../utilities/systick_utils.c 

OBJS += \
./utilities/fsl_debug_console.o \
./utilities/systick_utils.o 

C_DEPS += \
./utilities/fsl_debug_console.d \
./utilities/systick_utils.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DDEBUG -DCPU_MKL25Z128VLK4 -DFRDM_KL25Z -DFREEDOM -DPRINTF_ADVANCED_ENABLE -DCPU_MKL25Z128VLK4_cm0plus -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -D__REDLIB__ -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/board" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/source" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/CMSIS_driver" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/CMSIS" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/drivers" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/utilities" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/startup" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/gpio_driver" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/interface" -I"/Users/julietdenapoli/Documents/MCUXpressoIDE_11.3.0/workspace/3140FinalTest/sensors" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


