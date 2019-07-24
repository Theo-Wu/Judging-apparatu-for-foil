#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "util.h"
#include "sys.h"
#include "delay.c"

#define POWER 162
#define UP 98    
#define PLAY 2	 
#define ALIEN 226
#define RIGHT 194
#define LEFT 34
#define VOL_MINUS 224 
#define DOWN 168	   
#define VOL_PLUS 144

void continue_timing();

void display();

void stop_timing();

void display_hit(status status_1, status status_2);

u8 player_2_score = 0;
u8 player_1_score = 0;
u8 running = 0;

void remote_operations(u8 key){
	switch(key){
		case RIGHT:
			player_2_score++;
			display();
			break;
		case LEFT:
			player_2_score--;
			display();
			break;
		case UP:
			player_1_score++;
			display();
			break;
		case LEFT:
			player_1_score--;
			display();
		
			break;
		case ALIEN:
			player_1_score=0;
			player_2_score=0;
			display();
			break;
		case PLAY:
			if(running == 1){
				stop_timing();
				running = !running;
			}
			else if(running == 0){
				continue_timing();
				running = !running;
			}
			break;
			
	}
}

void display_hit(status status_1, status status_2){
	
	HAL_GPIO_WritePin(AN1_GPIO_Port, AN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(AN2_GPIO_Port, AN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(AN3_GPIO_Port, AN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(AN4_GPIO_Port, AN4_Pin, GPIO_PIN_SET);
	
	
	if(status_1 == PLAYER_1_HIT){
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
	}
		
	else if(status_1 == PLAYER_1_INVALID){
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
	}
	
	if(status_2 == PLAYER_2_HIT){
		HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	}
	
	else if(status_2 == PLAYER_2_INVALID){
		HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	}
	
	HAL_Delay(3000);
	
<<<<<<< HEAD:cube_project/Fence/Src/util.c
	// RESET
	// rows
	HAL_GPIO_WritePin(AN1_GPIO_Port, AN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(AN2_GPIO_Port, AN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(AN3_GPIO_Port, AN3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(AN4_GPIO_Port, AN4_Pin, GPIO_PIN_RESET);
=======
	delay_ms(50);//ms:Ҫ��ʱ��ms��
>>>>>>> upstream/master:Fence/Src/util.c
	
	// red leds
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
	
	// green leds
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
	
	
}
