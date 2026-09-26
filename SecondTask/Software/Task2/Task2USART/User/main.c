#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "RxData:");
	
	Serial_Init();
	
	uint8_t MyArray[] = {0x52, 0x6F, 0x62, 0x6F, 0x4D, 0x61, 0x73, 0x74, 0x65 ,0x72};
	Serial_SendArray(MyArray,10 );
	Serial_Printf("\t华南虎，不要怂，就是干!\r\n");
	
	while (1)
	{
		if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
		{
			RxData = USART_ReceiveData(USART1);
			OLED_ShowHexNum(1, 8, RxData, 2);
		}
	}
}
