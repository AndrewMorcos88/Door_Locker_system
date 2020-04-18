/******************************************************************************
 *
 *
 *
 * File Name: my_application.c
 *
 * Description: Source file for the human interface using keypad ,lcd
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/




#include"my_application.h"



/* function to output "Welcome sentence "to user on lcd and initialize lcd screen and all used modules*/
void Welcome_interface(void){

	LCD_init(); /* first initialize lcd screen */
	UART_init();/* initialize UART Driver */ 
	LCD_clearScreen(); /* to make sure just clear anything on the screen */
	LCD_displayString(WelcomeStartSentence); /* display the welcome text first */


}

/* function to take first input password from user */
void TakeFirstPassword (void){
	uint8 Password[10]; /* array of 10 char to save the input from user */
	uint8 CounterPassword =0;  /* counter to display char in password array */
	uint8 TempChar ; /* temp char to save the input cahr from keypad */
	LCD_goToRowColumn(1,0);/* to let the cursor at the next line of the screen */
	LCD_displayString(YourPasswordSentence); /* show on screen " enter your pass:" */
	while (1)
	{
		TempChar= KeyPad_getPressedKey(); /* get input from keypad */
		if (TempChar=='#')   /* # means user input password is finished */
			break;
		else
		{
			Password[CounterPassword]=TempChar;  /* save the input char in the array of password */
			LCD_displayCharacter('*');  /* display on screen ***** while entering his password */
			CounterPassword++;


		}


	}

	SendPassword(Password,CounterPassword);  /* send the password to be detected */


}

/* function to take the check of the first input password from user */
uint8 TakeCheckedFirstPassord(void){
	uint8 Password[10]; /* array of 10 char to save the input from user */
	uint8 CounterPassword =0;  /* counter to display char in password array */
	uint8 TempChar ; /* temp char to save the input char from keypad */
	LCD_clearScreen(); /* clear the screen to resume */
	LCD_displayString(ConfirmYourPasswordSentence); /* confirm your password */


	while (1)
		{
			TempChar= KeyPad_getPressedKey(); /* get input from keypad */
			if (TempChar=='#')   /* # means user input password is finished */
				break;
			else
			{
				Password[CounterPassword]=TempChar;  /* save the input char in the array of password */
				LCD_displayCharacter('*');  /* display on screen ***** while entering his password */
				CounterPassword++;


			}


		}

	return CheckPassword(Password ,CounterPassword );  /* if the value checked is true so output 1
	else output 0 and start again from the first */

}

/* function to send the entered password from user using UART to another MC to analyze data*/
 void SendPassword(uint8* Password,uint8 size){
uint8 Counter =0;
UART_sendByte('S'); /* To tell reciever to Save this password or Reset it */
for (;Counter<size;Counter++) /* loop the array elements to send it byte by byte */
{
	UART_sendByte(Password[Counter]); /* send pass char by char using UART */
}
UART_sendByte('&') ; /* to make the reciever know end of password */

}




/* function to check of the input password from user to be the same in the eeprom*/
 uint8 CheckPassword(uint8* Password ,uint8 size){
	 uint8 Counter =0;
	 UART_sendByte('C'); /* To tell reciever to Check this password */
	 for (;Counter<size;Counter++) /* loop the array elements to send it byte by byte */
	 {
	 	UART_sendByte(Password[Counter]); /* send pass char by char using UART */
	 }
	 UART_sendByte('&') ; /* to make the reciever know end of password */



	return UART_recieveByte();

	 /* return result of matching between the trial one and the defined first from user if
	  * 1== true   if 0 == false */


}

/* function to display the instruction needed to user */
void DisplayInstruction(void){

	LCD_clearScreen();
	LCD_displayString(OpenDoorInstuctionSetence); /* display instructions on screen */
	LCD_goToRowColumn(1,0);/* to let the cursor at the next line of the screen */
	LCD_displayString(ChangePasswordInstruction); /* display instructions on screen */


}

/* function to show on lcd that door is opening or closing */
void OpenCloseDoor(void){
	LCD_clearScreen();
	LCD_displayString(OpeniningTheDoorSentence); /* display sentence to user */

	UART_sendByte(OpenDoorChar); /* send order to open the door */

	_delay_ms(5000);   /* delay period while door is opening */

	UART_sendByte(CloseDoorChar); /* send order to close the door */
	LCD_displayString(ClosingTheDoorSentence);


	_delay_ms(5000);         /* delay period while door is closing */





}

/* function to show action that user inputs are wrong and excedded the allowed trials */

void CallPolice(void){

	 LCD_clearScreen();
	LCD_displayString(TheifSentence);  /* display that you have no Access to the system */

	UART_sendByte(BazzarONChar); /* make bazzar alert for 2 sec */

	_delay_ms(2000); /* delay the system */

	UART_sendByte(BazzarOFFChar); 

}


/* function to show on lcd while changing password */
void ChangePassword(void){
	uint8 flagFalsePassword=0; /* flag to check if user enter any correct trial or no */
	uint8 TrueFalsePassword ;
	uint8 CounterErrors=0;
	TrueFalsePassword= TakeCheckedFirstPassord(); /* check that user have correct authority */
	if (TrueFalsePassword==1)  /* correct password */
	{
		while (1)
		{ /* take password again from the start  */
		TakeFirstPassword();
		if (TakeCheckedFirstPassord()==1)
				break ;
		}

	}
	else {    /* wrong password */
		LCD_clearScreen();
		LCD_displayString(WrongPassword);
		CounterErrors++ ; /* number of errors icrements */

		while (TakeCheckedFirstPassord()==0)
		{
			CounterErrors++ ;
			if (CounterErrors==NumberOfWrongPasswordsTrial){ /* the number of allowed trials excids limits*/
				CallPolice();
				flagFalsePassword=1;
				break;
			}
		}
		if (flagFalsePassword==0)/* there is correct trial */
		{
			while (1){ /* take password again from the start  */
					TakeFirstPassword();
					if (TakeCheckedFirstPassord()==1)
							break ;
					}

		}

	}


}



/* function to show on screen that you entered wrong password*/
void DisplayWrongPassword(void){
	LCD_clearScreen();
	LCD_displayString(WrongTrialPasswordSentence);

	_delay_ms(1000);

}

/* function to show on screen that you entered correct password*/

void DisplayAcceptedPassword(void){
	LCD_clearScreen();
	LCD_displayString(AcceptedPasswordSetence);
	_delay_ms(200);
}




