/******************************************************************************
 *
 *
 *
 * File Name: main.c
 *
 * Description: main file for human interface with lcd and keypad
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/


#include "my_application.h"
int main(void)
{
	uint8 TempValue ;/* temp value to have the output char from keypad each time is pressed */
	Welcome_interface();
	/* welcome function to be shown on screen only 1 time and initialize
	the used modules in the system  */



	while (1)
		{
		/* first time to enter to make sure that there is matching between entered pass
		 *  and assurance pass */
			TakeFirstPassword(); /* take first password from the user */

			if (TakeCheckedFirstPassord()==1) /* true matching so break from the loop and show accepted pass */
				{
				DisplayAcceptedPassword();
					break ;
				}
			else
				DisplayWrongPassword(); /* wrong matching so repeat again and show wrong matching on screen */

		}



	while (1)   /* main loop of the application */
	{
		DisplayInstruction();/* display instructions on the screen */
		TempValue= KeyPad_getPressedKey();

		if (TempValue==ChangePasswordChar) /* user wants to change pass */
			ChangePassword();
		else if (TempValue==OpenCloseDoorChar) /* user want to open the door */
			OpenCloseDoor();







	}










}
