#include "main.h"

UART_HandleTypeDef huart1;
unsigned char uTx_Data1[] = {0x1};
unsigned char uTx_Data2[] = {0x2};

void vUser_UART_SendString();
