/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes
-----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
void Set_Pin_Output(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Input(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);
void delay(uint32_t us);
uint8_t DS18B20_Start(void);
void DS18B20_Write(uint8_t data);
uint8_t DS18B20_Read(void);

#define DS18B20_PORT    				GPIOA
#define DS18B20_PIN						GPIO_PIN_1
#define RESOLUTION_FACTOR_FOR_12_BIT	0.0625
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
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  uint8_t Presence = 0, Temp_byte1 = 0, Temp_byte2 = 0;
  float temp_data = 0;

  int8_t str[100] = {0};

  while (1)
  {
    /* USER CODE END WHILE */
	  Presence = DS18B20_Start ();
	  HAL_Delay (1);
	  DS18B20_Write (0xCC);  // skip ROM
	  DS18B20_Write (0x44);  // convert t
	  HAL_Delay (800);

	  Presence = DS18B20_Start ();
	  HAL_Delay(1);
	  DS18B20_Write (0xCC);  // skip ROM
	  DS18B20_Write (0xBE);  // Read Scratch-pad

	  Temp_byte1 = DS18B20_Read();
	  Temp_byte2 = DS18B20_Read();

	  temp_data = (float)(((Temp_byte2<<8)|(Temp_byte1))*RESOLUTION_FACTOR_FOR_12_BIT);

	  sprintf(str,"Temperature in degC = %0.2f\r\n", temp_data);
	  HAL_UART_Transmit(&huart2, str, sizeof(str), 1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

void Set_Pin_Output(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	//Configure GPIO Pin PXx
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	//Configure GPIO Pin PXx
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void delay(uint32_t us)
{
	for(int i= 0;i < us;i++)
	{
		for(int j=0;j<5;j++)
		{
			;
		}
	}
}

uint8_t DS18B20_Start(void)
{
	uint8_t Response = 0;
	Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
	HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pin pulled to low
	delay(480);		//acc to datasheet

	Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
	delay(80);

	if(!(HAL_GPIO_ReadPin(DS18B20_PORT, DS18B20_PIN)))
		Response = 1;		//pin is low==presence pulse detected
	else
		Response =-1;

	delay(400);		//480us total

	return Response;
}

void DS18B20_Write(uint8_t data)
{
	Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
	for(int i=0;i<8;i++)
	{
		if((data&(1<<i))!=0)		//if bit high
		{
			//write 1
			Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
			HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull pin low
			delay(1);

			Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
			delay(50);		//wait for 60 us
		}
		else		//if bit low
		{
			//write 0
			Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
			HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull pin low
			delay(50);		//wait for 60 us

			Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
		}
	}
}

uint8_t DS18B20_Read(void)
{
	uint8_t Value = 0;
	Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
	for(int i=0;i<8;i++)
	{
		Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);		//set pin as o/p
		HAL_GPIO_WritePin(DS18B20_PORT, DS18B20_PIN, 0);		//pull data pin low
		delay(2);		//2us delay

		Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);		//set pin as i/p
		if(HAL_GPIO_ReadPin(DS18B20_PORT, DS18B20_PIN))		//if pin high
		{
			Value |= 1<<i;		//read =1
		}
		delay(60);		//wait 60us
	}
	return Value;
}
