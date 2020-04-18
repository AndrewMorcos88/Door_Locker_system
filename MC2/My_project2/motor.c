/******************************************************************************
 *
 *
 *
 * File Name: motor.c
 *
 * Description: source file for controlling DC Motor connected
 *
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#include"motor.h"

void Motor_init(void){

	SET_BIT(PortDirection,FirstPin); /* make the pins as output pins */
	SET_BIT(PortDirection,SecondPin); /* make the pins as output pins */
	CLEAR_BIT(PortOutput,FirstPin); /* make motor first initilaize to be off */
	CLEAR_BIT(PortOutput,SecondPin); /* make motor first initilaize to be off */
}

/* function to rotate motor clockwise (open motor ) */
void Motor_ON(void){
	CLEAR_BIT(PortOutput,FirstPin);
	SET_BIT(PortOutput,SecondPin);
	/* rotate clock wise */
	_delay_ms(5000);


}

/* function to rotate motor clockwise (open motor ) */
void Motor_OFF(void){
	SET_BIT(PortOutput,FirstPin);
	CLEAR_BIT(PortOutput,SecondPin);
	/* rotate anti clockwise */
	_delay_ms(5000);
	CLEAR_BIT(PortOutput,FirstPin); /* make motor to be off at the end  */
	CLEAR_BIT(PortOutput,SecondPin); /* make motor to be off at the end  */


}

