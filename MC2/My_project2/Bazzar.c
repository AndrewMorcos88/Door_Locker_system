/******************************************************************************
 *
 *
 *
 * File Name: Bazzar.c
 *
 * Description: source file for the alerting bazzar disturbance
 *
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#include"Bazzar.h"


/* function to initialize DIO Pin */
void Bazzar_Init(void){
	SET_BIT(DirectionTargetPort,TargetPin);
	CLEAR_BIT(OutputPort,TargetPin); /* make it initially off */
}

/* function to activate DIO Pin */
void Bazzar_ON(void){
	SET_BIT(OutputPort,TargetPin);
}

/* function to deactivate DIO Pin */
void Bazzar_OFF(void){
	CLEAR_BIT(OutputPort,TargetPin);
}


