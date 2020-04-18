 /******************************************************************************
 *
 * Module: Human Interface ECU
 *
 * File Name: my_application.h
 *
 * Description: Header file for the Human Interface with keypad and lcd
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/
#ifndef my_application_H_
#define my_application_H_
#include"keypad.h"
#include "lcd.h"
#include "micro_config.h"
#include"std_types.h"
#include"uart.h"




/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define WelcomeStartSentence "please enter your password then #"
#define YourPasswordSentence "your pass:"
#define ConfirmYourPasswordSentence "confirm pass:"
#define OpenDoorInstuctionSetence "to open door press #"
#define ChangePasswordInstruction "to change pass press *"
#define OpeniningTheDoorSentence "the door is opening!"
#define ClosingTheDoorSentence "the door is closing!"
#define NumberOfWrongPasswordsTrial 3
#define WrongPassword "Wrong Password!!"
#define TheifSentence "Move Away 7araamy!!"
#define WrongTrialPasswordSentence "Wrong,try again"
#define AcceptedPasswordSetence "Accepted pass"
#define ChangePasswordChar '*'
#define OpenCloseDoorChar '#'


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
/* function to output "Welcome sentence "to user on lcd */
void Welcome_interface(void);

/* function to take first input password from user */
void TakeFirstPassword (void);

/* function to take the check of the first input password from user */
uint8 TakeCheckedFirstPassord(void);

/* function to send the entered password from user using UART to another MC to analyze data*/
void SendPassword(uint8* Password,uint8 size);

/* function to check of the input password from user to be the same in the eeprom*/
uint8 CheckPassword(uint8* Password ,uint8 size);


/* function to display the instructions needed to user */
void DisplayInstruction(void);

/* function to show on lcd that door is opening or closing */
void OpenCloseDoor(void);

/* function to show on lcd while changing password */
void ChangePassword(void);

/* function to show action when the user didn't input the password correctly  */
 void CallPolice(void);

/* function to show on screen that you entered wrong password*/
void DisplayWrongPassword(void);

/* function to show on screen that you entered correct password*/
void DisplayAcceptedPassword(void);








#endif









