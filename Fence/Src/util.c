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

#define NOT_HIT 0;
#define PLAYER_1_HIT 1
#define PLAYER_2_HIT 2
#define PLAYER_1_INVALID 3
#define PLAYER_2_INVALID 4

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
	
	// set all pins
	HAL_GPIO_WritePin(AN1_GPIO_Port, AN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(AN2_GPIO_Port, AN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	
	
	if(status_1 == PLAYER_1_HIT){
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	}
		
	else if(status_1 == PLAYER_1_INVALID){
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	}
	
	if(status_2 == PLAYER_2_HIT){
		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	}

	else if(status_2 == PLAYER_2_INVALID){
		HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	}
	
	HAL_Delay(3000);
	
	// RESET
	// rows
	HAL_GPIO_WritePin(AN1_GPIO_Port, AN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(AN2_GPIO_Port, AN2_Pin, GPIO_PIN_RESET);
	
	// red leds
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	
	// green leds
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	
	
}
