#include <stdio.h>
#include <stdlib.h>
#include "gpioLED.h"

int main(){
	//Nota* notas_saved = NULL;
	//INPUT
	initGPIO(GPIO_F1, MODULO_2, DIR_INPUT);
	initGPIO(GPIO_F2, MODULO_2, DIR_INPUT);
	initGPIO(GPIO_F3, MODULO_2, DIR_INPUT);
	initGPIO(GPIO_F4, MODULO_2, DIR_INPUT);
	
	//OUTPUT
	initGPIO(LED_F1, MODULO_2, DIR_OUTPUT);
	initGPIO(LED_F2, MODULO_2, DIR_OUTPUT);
	initGPIO(LED_F3, MODULO_2, DIR_OUTPUT);
	initGPIO(LED_F4, MODULO_2, DIR_OUTPUT);
	initGPIO(BUZZER, MODULO_2, DIR_OUTPUT);
	initGPIO(LED_WAIT, MODULO_2, DIR_OUTPUT);
	
	while(TRUE){
		blink(LED_WAIT, MODULO_2);
		if(getPinValue(GPIO_F1, MODULO_2)){
			//notas_saved = insertLista(notas_saved, LED_F1, FREQUENCIA_1);
			GPIOHigh(LED_F1, MODULO_2);
			playNota(BUZZER, MODULO_2, FREQUENCIA_1);
		}
		GPIOLow(LED_F1, MODULO_2);
		
		if(getPinValue(GPIO_F2, MODULO_2)){
			//notas_saved = insertLista(notas_saved, LED_F2, FREQUENCIA_2);
			GPIOHigh(LED_F2, MODULO_2);
			playNota(BUZZER, MODULO_2, FREQUENCIA_2);
		}
		GPIOLow(LED_F2, MODULO_2);
		
		if(getPinValue(GPIO_F3, MODULO_2)){
			//notas_saved = insertLista(notas_saved, LED_F3, FREQUENCIA_3);
			GPIOHigh(LED_F3, MODULO_2);
			playNota(BUZZER, MODULO_2, FREQUENCIA_3);
		}
		GPIOLow(LED_F3, MODULO_2);
		
		if(getPinValue(GPIO_F4, MODULO_2)){
			//notas_saved = insertLista(notas_saved, LED_F4, FREQUENCIA_4);
			GPIOHigh(LED_F4, MODULO_2);
			playNota(BUZZER, MODULO_2, FREQUENCIA_4);
		}
		GPIOLow(LED_F4, MODULO_2);
/*
		if(getPinValue(GPIO_PLAY, MODULO_2)){
			playMusicSaved(notas_saved);
		}
*/
	}
}
