/******************************************************************************
 *
 *
 *
 * File Name: motor.h
 *
 * Description: header file for controlling DC Motor connected
 *
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include"micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define FirstPin PC6
#define SecondPin PC7
#define PortDirection DDRC
#define PortOutput PORTC

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* function to init pin direction and set motor to be off */
void Motor_init(void);

/* function to rotate motor clockwise (open motor ) */
void Motor_ON(void);

/* function to rotate motor clockwise (open motor ) */
void Motor_OFF(void);




#endif /* MOTOR_H_ */
