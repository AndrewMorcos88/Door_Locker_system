/******************************************************************************
 *
 *
 *
 * File Name: Main.c
 *
 * Description: Main file for the processing and analyzing of data received via UART and Send
 * via I2C module
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#include "my_application.h"

int main(void)
{
	uint8 Tempvalue ; /* temp value to recieve byte from UART */
	InitModules(); /* start to init the modules to be used first */

	while (1)  /* main loop */
	{
		Tempvalue=UART_recieveByte();
		switch(Tempvalue)
		{
		case SetPasswordChar: SetPassword();
		break ;
		case CheckPasswordChar: CheckPassword();
		break ;
		case OpenDoorChar : Motor_ON();
		break;
		case CloseDoorChar :Motor_OFF();
		break;
		case BazzarONChar : Bazzar_ON();
		break;
		case BazzarOFFChar : Bazzar_OFF();
		break;
		default : break;

		}



	}






}
