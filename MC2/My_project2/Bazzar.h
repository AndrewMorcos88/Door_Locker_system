/******************************************************************************
 *
 *
 *
 * File Name: Bazzar.h
 *
 * Description: header file for the alerting bazzar disturbance
 *
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/
#ifndef BAZZAR_H_
#define BAZZAR_H_

#include"micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/


#define TargetPin PA0
#define DirectionTargetPort DDRA
#define OutputPort PORTA


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* function to initialize DIO Pin */
void Bazzar_Init(void);

/* function to activate DIO Pin */
void Bazzar_ON(void);

/* function to deactivate DIO Pin */
void Bazzar_OFF(void);


#endif /* BAZZAR_H_ */
