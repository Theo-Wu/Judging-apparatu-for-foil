#include "main.h"
#include "time.h"



void stop_timing()
{
	
	vUser_UART_SendString(&huart1, uTx_Data1);
        
        HAL_Delay(1000);HAL_Delay(1000);
}

void continue_timing()
{
	vUser_UART_SendString(&huart1, uTx_Data2);
        /* ??1s */
        HAL_Delay(1000);HAL_Delay(1000);
}