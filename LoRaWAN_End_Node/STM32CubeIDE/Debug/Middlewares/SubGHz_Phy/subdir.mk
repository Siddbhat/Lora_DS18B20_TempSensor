################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio.c \
C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio_driver.c \
C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio_fw.c 

OBJS += \
./Middlewares/SubGHz_Phy/radio.o \
./Middlewares/SubGHz_Phy/radio_driver.o \
./Middlewares/SubGHz_Phy/radio_fw.o 

C_DEPS += \
./Middlewares/SubGHz_Phy/radio.d \
./Middlewares/SubGHz_Phy/radio_driver.d \
./Middlewares/SubGHz_Phy/radio_fw.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/SubGHz_Phy/radio.o: C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio.c Middlewares/SubGHz_Phy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DSTM32WLE5xx -DUSE_HAL_DRIVER -c -I../../Core/Inc -I"C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Projects/Applications/LoRaWAN/LoRaWAN_End_Node/STM32CubeIDE/Application/Include" -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../../../../../Utilities/trace/adv_trace -I../../../../../../Utilities/misc -I../../../../../../Utilities/sequencer -I../../../../../../Utilities/timer -I../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/BSP/STM32WLxx_LoRa_E5_mini -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/SubGHz_Phy/radio_driver.o: C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio_driver.c Middlewares/SubGHz_Phy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DSTM32WLE5xx -DUSE_HAL_DRIVER -c -I../../Core/Inc -I"C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Projects/Applications/LoRaWAN/LoRaWAN_End_Node/STM32CubeIDE/Application/Include" -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../../../../../Utilities/trace/adv_trace -I../../../../../../Utilities/misc -I../../../../../../Utilities/sequencer -I../../../../../../Utilities/timer -I../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/BSP/STM32WLxx_LoRa_E5_mini -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/SubGHz_Phy/radio_fw.o: C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver/radio_fw.c Middlewares/SubGHz_Phy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DSTM32WLE5xx -DUSE_HAL_DRIVER -c -I../../Core/Inc -I"C:/Users/prath/STM32CubeIDE/workspace_1.13.0/LoRaWan-E5-Node-main/Projects/Applications/LoRaWAN/LoRaWAN_End_Node/STM32CubeIDE/Application/Include" -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../../../../../Utilities/trace/adv_trace -I../../../../../../Utilities/misc -I../../../../../../Utilities/sequencer -I../../../../../../Utilities/timer -I../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/BSP/STM32WLxx_LoRa_E5_mini -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-SubGHz_Phy

clean-Middlewares-2f-SubGHz_Phy:
	-$(RM) ./Middlewares/SubGHz_Phy/radio.cyclo ./Middlewares/SubGHz_Phy/radio.d ./Middlewares/SubGHz_Phy/radio.o ./Middlewares/SubGHz_Phy/radio.su ./Middlewares/SubGHz_Phy/radio_driver.cyclo ./Middlewares/SubGHz_Phy/radio_driver.d ./Middlewares/SubGHz_Phy/radio_driver.o ./Middlewares/SubGHz_Phy/radio_driver.su ./Middlewares/SubGHz_Phy/radio_fw.cyclo ./Middlewares/SubGHz_Phy/radio_fw.d ./Middlewares/SubGHz_Phy/radio_fw.o ./Middlewares/SubGHz_Phy/radio_fw.su

.PHONY: clean-Middlewares-2f-SubGHz_Phy

