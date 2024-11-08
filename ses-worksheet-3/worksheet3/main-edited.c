/** 
  ****************************************************************************** 
  * @file    GPIO/IOToggle/main.c 
  * @author  MCD Application Team 
  * @version V3.5.0 
  * @date    08-April-2011 
  * @brief   Main program body. 
  ****************************************************************************** 
  * @attention 
  * 
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS 
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE 
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY 
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING 
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE 
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS. 
  * 
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2> 
  ****************************************************************************** 
  */ 

/* Includes ------------------------------------------------------------------*/ 
#include <stm32f10x.h> 
#include <stm32f10x_rcc.h> 
#include <stm32f10x_gpio.h> 

/* Private variables ---------------------------------------------------------*/ 
GPIO_InitTypeDef GPIO_InitStructure; 

int main(void) 
{ 
	volatile uint32_t i; 
	static int greenledval = 0;	 
	 
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup 
       file (startup_stm32f10x_xx.s) before to branch to application main. 
       To reconfigure the default setting of SystemInit() function, refer to 
       system_stm32f10x.c file 
     */     
        
  /* GPIOC Periph clock enable */ 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 

  /* Configure PC6 in output pushpull mode */ 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 ; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure); 

  /* To achieve GPIO toggling maximum frequency, the following  sequence is mandatory. 
     You can monitor PD0 or PD2 on the scope to measure the output signal. 
     If you need to fine tune this frequency, you can add more GPIO set/reset 
     cycles to minimize more the infinite loop timing. 
     This code needs to be compiled with high speed optimization option.  */ 

  while (1) 
  { 
		GPIO_WriteBit(GPIOC , GPIO_Pin_6 , (greenledval) ? Bit_SET : Bit_RESET); 
		greenledval = 1 - greenledval; 
    
    i = 1000000; 
    while(--i); 
	 
   sleep(2);
    
		GPIO_WriteBit(GPIOC , GPIO_Pin_6 , (greenledval) ? Bit_SET : Bit_RESET); 
		greenledval = 1 - greenledval; 
	 
    i = 8000000; 
    while(--i); 

    sleep(2);
  } 
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
  /* User can add his own implementation to report the file name and line number, 
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */ 

  /* Infinite loop */ 
  while (1) 
  { 
  } 
} 

#endif 
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/


