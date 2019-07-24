#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "util.h"
#include "sys.h"
#include "delay.c"

int LED_1_HIT  ;
int LED_1_INVALID ;
int LED_2_HIT ;
int LED_2_INVALID ;

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
	
	
	delay_ms(50);//ms:要延时的ms数
	
}