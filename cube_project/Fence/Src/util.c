#include "tim.h"
#include "usart.h"
#include "gpio.h"

#define ushort unsigned short
#define status unsigned short 

#define NOT_HIT 0;
#define PLAYER_1_HIT 1
#define PLAYER_2_HIT 2
#define PLAYER_1_INVALID 3
#define PLAYER_2_INVALID 4

int LED_1_HIT  ;
int LED_1_INVALID ;
int LED_2_HIT ;
int LED_2_INVALID ;

void continue_timing();

void display();

void stop_timing();

void display_hit(status status_1, status status_2);

unsigned short player_2_score = 0;
unsigned short player_1_score = 0;
unsigned short running = 0;

void remote_operations(unsigned short key){
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
	if(status_1 == PLAYER_1_HIT)
		LED_1_HIT = 0;
	else if(status_1 == PLAYER_1_INVALID)
		LED_1_INVALID =0;
	
	
	if(status_2 == PLAYER_2_HIT)
		LED_2_HIT = 0;
	else if(status_2 == PLAYER_2_INVALID)
		LED_2_INVALID =0;
	
	LED_1_HIT = 1;
	LED_1_INVALID =1;
	LED_2_HIT = 1;
	LED_2_INVALID =1;
	
	
	Delay();
	
}