/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "dac.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Key.h"
#include "LED.h"
#include "OLED.h"
#include "BMP.h"
#include "MOTOR.h"
#include "Servo.h"
#include "Serial.h"
#include "retarget.h"
#include "scan.h"
#include "Track.h"
#include "serial_protocol.h"
#include "SR04.h"
#include "Voice.h"
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
uint8_t RxData = 0; //用于接收一个字节数据
uint8_t VoiceData = 0; //用于接收一个字节语音数据
uint8_t flag_bt = 0;
uint8_t flag_voice = 0;
float angle = 0;

float temp = 0;
float humi = 0;

uint8_t center_x = 0; //扫描中心点x坐标
uint8_t center_y = 0; //扫描中心点y坐标
uint8_t scan = 0; //扫描模式
uint8_t mode = 0; //扫描模式

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
  MX_DMA_Init();
  MX_DAC1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_UART4_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
  int8_t speed = 0; //一般速度变量
  int8_t speed_L = 0; //左轮速度
  int8_t speed_R = 0; //右轮速度

  uint8_t keynum = 0; //按键值

  float distance = 0; //距离
  //
  // OLED_Init();
  // OLED_Clear();
  Servo_Init();
  RetargetInit(&huart3);
  //下面是普通串口中断，使用闲时中断+DMA不需开启普通中断，需要在串口初始化时开启，见uart.c
  // HAL_UART_Receive_IT(&huart2, &RxData, 1);

  printf("Hello World\r\n"); //串口测试

  Motor_Start(); //启动4轮的PWM输出
  //
  // OLED_ShowString(0, 0, "L", 12); //左轮速度
  // OLED_ShowString(0, 2, "R", 12); //右轮速度
  // OLED_ShowString(0, 4, "Dis", 12); //障碍距离
  // OLED_ShowString(0, 6, "scan", 12); //扫描模态
  // OLED_ShowString(60, 0, "temp", 12); //温度
  // OLED_ShowString(60, 2, "humi", 12); //湿度
  // OLED_ShowString(60, 4, "x", 12); //??
  // OLED_ShowString(60, 6, "mode", 12); //小车模式 *遥控 *巡线 *跟随

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


    // //左屏
    // OLED_ShowSignedNum(20, 0, speed_L, 3, 12); //左轮速度
    // OLED_ShowSignedNum(20, 2, speed_R, 3, 12); //右轮速度
    // OLED_ShowNum(38, 4, distance, 1, 12); //显示距离
    // OLED_ShowNum(38, 6, scan, 1, 12); //显示扫描模态
    //
    // //右屏
    // OLED_ShowNum(98, 0, temp, 1, 12); //显示温度
    // OLED_ShowNum(98, 2, humi, 1, 12); //显示湿度
    // OLED_ShowNum(108, 4, angle, 3, 12); //显示舵机角度
    //
    // OLED_ShowNum(98, 6, mode, 1, 12); //显示小车模式

    // switch (mode)
    // {
    // case 1://循迹模式
    //   {
    //     Track(&speed_L, &speed_R);
    //     break;
    //   }
    // case 2: //自由运动模式
    //
    // default: //默认遥控或语音控制
    //         break;
    // }
    // //
    // if (flag_bt == 1) //遥控小车运动
    // {
    //   Motor_BlueTooth(&speed_L, &speed_R, &RxData, &mode); //蓝牙控制模式 *信息位：RxData
    //   flag_bt = 0;
    // }
    //
    // if (flag_voice == 1) //接收到语音数据
    // {
    //   Voice_Control(&speed_L, &speed_R, &VoiceData, &mode);
    //   flag_voice = 0;
    // }

     scan_mode(); //扫描模式选择 *标志位：scan
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV3;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  if (GPIO_Pin == B1_Pin) //按键1控制扫描模态
  {
    scan = (scan + 1) % 6;
    printf("scan = %d\n", scan);
  }
  if (GPIO_Pin == B2_Pin) //按键2
  {
    mode = (mode + 1) % 3;
    printf("mode = %d\n", mode);
  }
  if (GPIO_Pin == B3_Pin) //按键3
  {
    RxData = 5;
    flag_bt = 1;
    printf("B3");
  }
  if (GPIO_Pin == B4_Pin) //按键4
  {
    printf("B4");
  }

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}

void OnUartCmd_uart1(uint8_t* _data, uint16_t _len) //CAM 串口1的DMA接收中断处理函数
{
  process_received_frame(_data, _len); //根据DMA接收到的数组进行有效判断和坐标转换

  //根据中心坐标，判断模态
  if (center_x < 200 && center_x > 120 && center_y < 140 && center_y > 84)
  {
    scan = 1;
  }
  //轴中点*4 0 0.5 / 0 -0.5 / 0.5 0 / -0.5 0
  else if ((center_x <= 200 && center_x >= 120 && (center_y < 84 && center_y > 28 || center_y < 192 && center_y > 140))
      || ((center_x < 120 && center_x > 40 || center_x < 280 && center_x > 200) && center_y < 140 && center_y > 84))
  {
    scan = 2;
  }
  //-0.5 0.5 / 0.5 -0.5
  else if ((center_x < 120 && center_x > 40 && center_y < 84 && center_y > 28)
      || (center_x < 280 && center_x > 200 &&  center_y < 192 && center_y > 140))
  {
    scan = 3;
  }
  /// -0.5 -0.5 / 0.5 0.5
  else if ((center_x < 120 && center_x > 40 &&  center_y < 192 && center_y > 140)
      || (center_x < 280 && center_x > 200 && center_y < 84 && center_y > 28 ))
  {
    scan = 4;
  }
  else if ( 0 < center_x && center_x < 40 || center_x < 320 && center_x > 280
            || 0 < center_y && center_y < 28 || center_y < 224 && center_y > 192)
  {
    scan = 5;
  }
  else
  {
    scan = 0;
  }



  // printf(" mode = %d", mode);
  // if (_len == 21)
  // {
  //     printf("Rx: ");
  //     for (uint16_t i = 0; i < _len; i++)
  //         printf("%02X ", _data[i]);
  // }
  // printf("\r\n");
}

void OnUartCmd_uart2(uint8_t* _data, uint16_t _len) //BT 串口2的DMA接收中断处理函数
{
  if (_len == 3)
    if (_data[0] == 0xFF && _data[2] == 0xFE) //接收到命令
      //     printf("Rx:%x\r\n", _data[1]);
        RxData = _data[1]; //保存收到的命令
  flag_bt = 1;
}

void OnUartCmd_uart4(uint8_t* _data, uint16_t _len) //语音 串口4的DMA接收中断处理函数
{
  // if (_len == 3)
  //   if (_data[0] == 0xFF && _data[2] == 0xFE) //接收到命令
  //     //     printf("Rx:%x\r\n", _data[1]);
  //       VoiceData = _data[1]; //保存收到的命令
  flag_voice = 1;
  printf("%d\r\n", _data[0]);
  printf("%d\r\n", _data[1]);
  printf("%d\r\n", _data[2]);
}

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
