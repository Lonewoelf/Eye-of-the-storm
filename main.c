
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"
#include <string.h>

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM6_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

struct Sensors{
char temperature[32];
char humidity[32];
char windSpeed[32];
char windDirection[32];
};


uint8_t tx_buffer[128] = "AT\r\n";
uint8_t rx_buffer[400];

uint8_t ssid[64] = "";
uint8_t password[64] = "";
uint8_t ipAdr[64] = "";

int connectManual = 0;
int connectionError = 0;
unsigned char cmd[2];
char id[5] = "I 1";

struct Sensors sensor;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_I2C1_Init();
  MX_TIM6_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

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

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 3, 0);
}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Analogue filter 
    */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Digital filter 
    */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM6 init function */
static void MX_TIM6_Init(void)
{

  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 0;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 0;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through 
        * the Code Generation settings)
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pins : PC13 PC14 PC15 PC0 
                           PC1 PC2 PC3 PC4 
                           PC5 PC6 PC7 PC8 
                           PC9 PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PF0 PF1 PF4 PF5 
                           PF6 PF7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA4 PA5 PA6 
                           PA7 PA8 PA11 PA12 
                           PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6 
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10 
                           PB11 PB12 PB13 PB14 
                           PB15 PB3 PB4 PB5 
                           PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* Empties the buffer to "" */
void emptyBuffer(uint8_t *buffer){
	strncpy((char*)buffer, "", strlen((const char*) buffer));
}

/* Sets the buffer to the specified paramatar pData */
void setBuffer(uint8_t *buffer, const char* pData){
	emptyBuffer(buffer);
	strcpy((char*)buffer,pData);
}

/* Receives data from the specified UART line and sets pData as the received data */
void getData(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Timeout){
	emptyBuffer(pData);
	HAL_UART_Receive(huart,pData, 400, Timeout);
}

/* Sends data via the specified UART line */
void sendData(UART_HandleTypeDef *huart, uint8_t *pData, uint32_t Timeout){
	HAL_UART_Transmit(huart,pData, strlen((const char*)pData),Timeout);
}

/* checks whether the buffer is empty */
int bufferIsEmpty(uint8_t *buffer){
	if(strcmp((const char*)buffer, "") == 0){
		return 1;
	}else{
		return 0;
	}
}

/* checks if the buffer is the same as the specified text */
int bufferIsText(uint8_t *buffer, const char* text){
	if(strcmp((const char*)buffer, text) == 0){
		return 1;
	}else{
		return 0;
	}
}

/* Opens a TCP port on the ESP */
void openPort(){
	sprintf((char*)tx_buffer, "AT+CIPSTART=\"TCP\",\"%s\",54000\r\n", ipAdr);
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 100);
	sendData(&huart2, rx_buffer, 100);
}

/* closes the port on the ESP */
void closePort(){
	setBuffer(tx_buffer, "AT+CIPCLOSE\r\n");
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 100);
	sendData(&huart2, rx_buffer, 100);

}

/* Connects with a wifi network */
int connect(){
	setBuffer(tx_buffer,"AT\r\n");
	sendData(&huart2, (uint8_t *) "begin connecting with wifi\r\n", 100);
	sendData(&huart2, tx_buffer, 100);
	sendData(&huart1, tx_buffer, 1000);
	getData(&huart1, rx_buffer, 1000);
	sendData(&huart2, rx_buffer, 100);
	if(bufferIsText(rx_buffer, "AT\r\r\n\r\nOK\r\n")){
		setBuffer(tx_buffer,"AT+CIPMUX=0\r\n");
		sendData(&huart1, tx_buffer, 100);
		getData(&huart1, rx_buffer, 100);
		sendData(&huart2, rx_buffer, 100);
		if(bufferIsText(rx_buffer, "AT+CIPMUX=0\r\r\n\r\nOK\r\n")){

			setBuffer(tx_buffer,"AT+CWMODE=1\r\n");
			sendData(&huart1, tx_buffer, 100);
			getData(&huart1, rx_buffer, 100);
			sendData(&huart2, rx_buffer, 100);
			if(bufferIsText(rx_buffer, "AT+CWMODE=1\r\r\n\r\nOK\r\n")){
				if(connectManual){
				do{
					connectionError = 1;
					//Ask user wich AP to connect to
					setBuffer(tx_buffer,"\r\nOptions for connections:\r\n1. Thom\r\n2. Tjeu\r\n3. manually\r\n\r\n");
					sendData(&huart2, tx_buffer, 100);
					emptyBuffer(rx_buffer);
					while(bufferIsEmpty(rx_buffer)){
						getData(&huart2, rx_buffer, 100);
					}
					if(strcmp((const char*)rx_buffer, "1") == 0){
						setBuffer(ssid,"ThomCrielaard");
						setBuffer(password,"jijKrijgtGeenWifi");
						connectionError = 0;
					}else if(bufferIsText(rx_buffer,"2")){
						setBuffer(ssid,"TjeuBuijs");
						setBuffer(password,"jijKrijgtGeenWifi");
						connectionError = 0;
					}else if(bufferIsText(rx_buffer,"3")){
						//Set the ssid and password manually
						emptyBuffer(ssid);
						emptyBuffer(password);
						while(bufferIsEmpty(ssid)){
							getData(&huart2, ssid, 100);
						}

						while(bufferIsEmpty(password)){
							getData(&huart2, password, 100);
						}
						connectionError = 0;
					/*}else if(bufferIsText(rx_buffer,"4")){
						connectionError = 0;
					*/
					}else{
						setBuffer(tx_buffer,"error: no such input allowed\r\n");
						sendData(&huart2, tx_buffer, 100);
					}

				}while(connectionError == 1);
				}else{
					setBuffer(ssid,"TjeuBuijs");
					setBuffer(password,"jijKrijgtGeenWifi");
				}

				/* connect with the AP */
				setBuffer(tx_buffer,"start connecting with AP\r\n");
				sendData(&huart2, tx_buffer, 100);
				sprintf((char*)tx_buffer, "AT+CWJAP=\"%s\",\"%s\"\r\n", ssid, password);
				sendData(&huart1, tx_buffer, 100);
				getData(&huart1, rx_buffer, 10000);
				sendData(&huart2, rx_buffer, 100);
				if(strcmp((const char*)rx_buffer + strlen((const char*) rx_buffer) - 4, "OK\r\n" ) == 0){
					sendData(&huart2, (uint8_t *) "succesfully connected with wifi AP\r\n", 100);
					return 1;
				}else{
					sendData(&huart2, (uint8_t *) "error: could not connect with wifi AP\r\n", 100);
				}

			}else{
				sendData(&huart2, (uint8_t *) "error: could not set CWMODE\r\n", 100);
			}
		}else{
			sendData(&huart2, (uint8_t *) "error: could not set CIPMUX\r\n", 100);
			sendData(&huart2, (uint8_t *) "trying to close port\r\n", 100);
			closePort();
		}
	}else{
		sendData(&huart2, (uint8_t *) "error: no connection with ESP\r\n", 100);
	}
	return 0;
}

/* Sets the ip address of where the tcp server is located */
void setIpAddress(){
	if(connectManual){
		setBuffer(tx_buffer,"IP address: \r\n");
		sendData(&huart2, tx_buffer, 100);
		emptyBuffer(rx_buffer);
		while(bufferIsEmpty(rx_buffer)){
			getData(&huart2, rx_buffer, 100);
		}
		setBuffer(ipAdr,(const char*)rx_buffer);
	}else{
		setBuffer(ipAdr, "192.168.43.216");
	}
}

/* Gets the humidity and temperature value from the SI7021 */
void getSensorValue(struct Sensors *s){
	int humidity, temperature;

	//get Humidity
	uint8_t buffer[16];
	cmd[0] = 0xE5;
	HAL_I2C_Master_Transmit(&hi2c1,0x40<<1,cmd,1,100);
	HAL_I2C_Master_Receive(&hi2c1,0x40<<1,buffer,2,100);
	humidity = buffer[0] << 8 | buffer[1];
	//humidity = (((125 * humidity) / 65536) - 6);
	sprintf(s->humidity, "H %i", humidity);
	osDelay(500);

	//get Temperature
	cmd[0] = 0xE0;
	HAL_I2C_Master_Transmit(&hi2c1,0x40<<1,cmd,1,100);
	HAL_I2C_Master_Receive(&hi2c1,0x40<<1,buffer,2,100);
	temperature = buffer[0] << 8 | buffer[1];
	//temperature = (((175.72 * temperature) / 65536) - 46.85);
	sprintf(s->temperature, "T %i", temperature);

	//get Windspeed
	int lastLight = 0;
	int lightCount = 0;
	for(int i = 0; i < 1000; i++){
		if(lastLight == 0 && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_SET){
			lightCount++;
			lastLight = 1;
		}
		if(lastLight == 1 && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) != GPIO_PIN_SET){
			lastLight = 0;
		}
		osDelay(5);
	}
	//windSpeed = lightCount * 2 * 3.14 / 5; //not acurate
	sprintf(s->windSpeed, "S %i", lightCount);
}

/* Sends the temperature, humidity and the windspeed values to the TCP server */
void sendValues(){
	openPort();
	//Send ID
	sprintf((char*)tx_buffer, "AT+CIPSEND=%i\r\n", strlen(id));
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	sendData(&huart1, (uint8_t*) id, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	//Send Temperature
	sprintf((char*)tx_buffer, "AT+CIPSEND=%i\r\n", strlen(sensor.temperature));
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	sendData(&huart1, (uint8_t *) sensor.temperature, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	//Send Humidity
	sprintf((char*)tx_buffer, "AT+CIPSEND=%i\r\n", strlen(sensor.humidity));
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	sendData(&huart1, (uint8_t *) sensor.humidity, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	//Send Windspeed
	sprintf((char*)tx_buffer, "AT+CIPSEND=%i\r\n", strlen(sensor.windSpeed));
	sendData(&huart1, tx_buffer, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	sendData(&huart1, (uint8_t *) sensor.windSpeed, 100);
	getData(&huart1, rx_buffer, 200);
	sendData(&huart2, rx_buffer, 100);
	//osDelay(200);
	closePort();
}

/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{
	osDelay(2000);
	while(!connect()){
		osDelay(5000);
	}
	setIpAddress();
	for(;;)
	{
		getSensorValue(&sensor);
		sendValues();
		setBuffer(tx_buffer, "send!");
		sendData(&huart2, tx_buffer, 100);
		osDelay(10000);
	}

}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
