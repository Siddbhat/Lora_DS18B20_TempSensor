/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_lorawan.h"
#include "stdio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
//void Set_Pin_Output(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);
//void Set_Pin_Input(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);
//void delay(uint32_t us);
//uint8_t DS18B20_Start(void);
//void DS18B20_Write(uint8_t data);
//uint8_t DS18B20_Read(void);
//
#define DS18B20_PORT    				GPIOB
#define DS18B20_PIN						GPIO_PIN_4
//#define RESOLUTION_FACTOR_FOR_12_BIT	0.0625
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
//	uint8_t Presence = 0, Temp_byte1 = 0, Temp_byte2 = 0;
//	float temp_data = 0;
//
//	int8_t str[100] = {0};
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();
  MX_GPIO_Init();
  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_LoRaWAN_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_LoRaWAN_Process();
//    Presence = DS18B20_Start ();
//    HAL_Delay (1);
//    DS18B20_Write (0xCC);  // skip ROM
//    DS18B20_Write (0x44);  // convert t
//    HAL_Delay (800);
//
//    Presence = DS18B20_Start ();
//    HAL_Delay(1);
//    DS18B20_Write (0xCC);  // skip ROM
//    DS18B20_Write (0xBE);  // Read Scratch-pad
//
//    Temp_byte1 = DS18B20_Read();
//    Temp_byte2 = DS18B20_Read();
//
//    temp_data = (float)(((Temp_byte2<<8)|(Temp_byte1))*RESOLUTION_FACTOR_FOR_12_BIT);

//    sprintf(str,"Temperature in degC = %0.2f\r\n", temp_data);
//    HAL_UART_Transmit(&huart1, str, sizeof(str), 1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DS18B20_PORT,DS18B20_PIN,0);

  /*Configure GPIO pin : PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
//  HAL_PWR_EnableBkUpAccess();
//  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
//  /** Configure the main internal regulator output voltage
//  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK
                              |RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  while (1)
  {
  }
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
//void Set_Pin_Output(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//	//Configure GPIO Pin PXx
//	GPIO_InitStruct.Pin = GPIO_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//	GPIO_InitStruct.Pull = GPIO_NOPULL;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
//}
//
//void Set_Pin_Input(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
//{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//	//Configure GPIO Pin PXx
//	GPIO_InitStruct.Pin = GPIO_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//	GPIO_InitStruct.Pull = GPIO_NOPULL;
//	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
//}
//
//void delay(uint32_t us)
//{
//	for(int i= 0;i < (4*us);i++);
//}
//
//uint8_t DS18B20_Start(void)
//{
//	uint8_t Response = 0;
//	Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
//	HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pin pulled to low
//	delay(480);		//acc to datasheet
//
//	Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//	delay(80);
//
//	if(!(HAL_GPIO_ReadPin(DS18B20_PORT, DS18B20_PIN)))
//		Response = 1;		//pin is low==presence pulse detected
//	else
//		Response =-1;
//
//	delay(400);		//480us total
//
//	return Response;
//}
//
//void DS18B20_Write(uint8_t data)
//{
//	Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
//	for(int i=0;i<8;i++)
//	{
//		if((data&(1<<i))!=0)		//if bit high
//		{
//			//write 1
//			Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
//			HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull pin low
//			delay(1);
//
//			Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//			delay(50);		//wait for 60 us
//		}
//		else		//if bit low
//		{
//			//write 0
//			Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//			HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull pin low
//			delay(50);		//wait for 60 us
//
//			Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//		}
//	}
//}
//
//uint8_t DS18B20_Read(void)
//{
//	uint8_t Value = 0;
//	Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//	for(int i=0;i<8;i++)
//	{
//		Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
//		HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull data pin low
//		delay(2);		//2us delay
//
//		Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
//		if(HAL_GPIO_ReadPin(DS18B20_PORT, DS18B20_PIN))		//if pin high
//		{
//			Value |= 1<<i;		//read =1
//		}
//		delay(60);		//wait 60us
//	}
//	return Value;
//}
