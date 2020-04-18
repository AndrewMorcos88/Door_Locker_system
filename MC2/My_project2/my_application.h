/******************************************************************************
 *
 *
 *
 * File Name: my_application.c
 *
 * Description: header file for the processing and analyzing of data received via UART and Send
 * via I2C module
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#ifndef MY_APPLICATION_H_
#define MY_APPLICATION_H_

#include "micro_config.h"
#include"std_types.h"
#include "uart.h"
#include "i2c.h"
#include "motor.h"
#include "common_macros.h"
#include "Bazzar.h"
#include "external_eeprom.h"




/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define SetPasswordChar 'S'
#define CheckPasswordChar 'C'
#define OpenDoorChar 'O'
#define CloseDoorChar 'E'
#define EndOfPasswordChar '&'
#define BazzarONChar 'A'
#define BazzarOFFChar 'B'






/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* function to recieve password from uart then send it using I2C to eeprom */
void SetPassword(void);

/* function to recieve password from uart then check if is same at eeprom or not */
uint8 CheckPassword(void);


/* function to initialize all required peripherials before start using them */
void InitModules(void);










#endif /* MY_APPLICATION_H_ */
