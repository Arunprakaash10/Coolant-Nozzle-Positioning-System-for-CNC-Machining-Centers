/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#define enable GPIO_PIN_0
#define direction GPIO_PIN_1
#define pulse GPIO_PIN_2
#define power GPIO_PIN_4
#define mode GPIO_PIN_3
#define B0 GPIO_PIN_15
#define B1 GPIO_PIN_8
#define B2 GPIO_PIN_15
#define B3 GPIO_PIN_14
#define B4 GPIO_PIN_13
#define B5 GPIO_PIN_12

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_RESET);
  int step_previous = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if (HAL_GPIO_ReadPin(GPIOB, power) == 0)
	  {
		  if (HAL_GPIO_ReadPin(GPIOB, mode) == 0) // advanced mode
		  {
			  int b0;
			  int b1;
			  int b2;
			  int b3;
			  int b4;
			  int b5;
			  if (HAL_GPIO_ReadPin(GPIOA, B0) == 0) //0
			  {
				  b0 = 1;
			  }
			  else
			  {
				  b0 = 0;
			  }
			  if (HAL_GPIO_ReadPin(GPIOA, B1) == 0) //1
			  {
				  b1 = 1;
			  }
			  else
			  {
				  b1 = 0;
			  }
			  if (HAL_GPIO_ReadPin(GPIOB, B2) == 0) //2
			  {
				  b2 = 1;
			  }
			  else
			  {
				  b2 = 0;
			  }
			  if (HAL_GPIO_ReadPin(GPIOB, B3) == 0) //3
			  {
				  b3 = 1;
			  }
			  else
			  {
				  b3 = 0;
			  }
			  if (HAL_GPIO_ReadPin(GPIOB, B4) == 0) //4
			  {
				  b4 = 1;
			  }
			  else
			  {
				  b4 = 0;
			  }
			  if (HAL_GPIO_ReadPin(GPIOB, B5) == 0) //5
			  {
				  b5 = 1;
			  }
			  else
			  {
				  b5 = 0;
			  }
			  int binary[] = {b0, b1, b2, b3, b4, b5};
			  int step_current = 0;
			  int step = 0;
			  int conversion =0;
			  for (int j = 0; j<6; j++)
			  {
				  conversion += binary[j]*pow(2,j);
			  }
			  step_current = conversion*8;
			  if (step_current > step_previous)
			  {
				  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_SET);
				  HAL_Delay(5);
				  step = step_current - step_previous;
				  for (int a = 0; a < step; a++)
				  {
				  	HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_SET);
				  	HAL_Delay(0.01);
				  	HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_RESET);
				  	HAL_Delay(0.01);
				  }
			  }
			  else if (step_current < step_previous)
			  {
				  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_RESET);
				  HAL_Delay(5);
				  step = step_previous - step_current;
				  for (int a = 0; a < step; a++)
				  {
				  	HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_SET);
				  	HAL_Delay(0.01);
				  	HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_RESET);
				  	HAL_Delay(0.01);
				  }
			  }
			  step_previous = step_current;
		  }
		  else // oscillating mode
		  {
			  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_SET);
			  HAL_Delay(10);
			  for( int i = 0; i<400; i++)
			  {
			      HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_SET);
				  HAL_Delay(0.01);
				  HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_RESET);
				  HAL_Delay(0.01);
			  }
			  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_RESET);
			  HAL_Delay(10);
			  for( int i = 0; i<400; i++)
			  {
			      HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_SET);
				  HAL_Delay(0.01);
				  HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_RESET);
				  HAL_Delay(0.01);
			  }
		  }
		  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_RESET);
	  }
	  else if (step_previous != 0)
	  {
		  HAL_GPIO_WritePin(GPIOA, direction, GPIO_PIN_RESET);
		  for(int step = step_previous; step>0; step--)
		  {
		      HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_SET);
			  HAL_Delay(0.01);
			  HAL_GPIO_WritePin(GPIOA, pulse, GPIO_PIN_RESET);
			  HAL_Delay(0.01);
		  }

	  }

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
