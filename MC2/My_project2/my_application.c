/******************************************************************************
 *
 *
 *
 * File Name: my_application.c
 *
 * Description: source file for the processing and analyzing of data received via UART and Send
 * via I2C module
 *
 * Author: Andrew Morcos
 *
 *******************************************************************************/

#include "my_application.h"

static uint8 NumberOfCharInPassword =0;


 /* function to recieve password from uart then send it using I2C to eeprom */
void SetPassword(void){
uint16 AdressMemory = 0x0311; /*  Address memory of EEPROM  firstly=0x0311 */
uint8 tempChar ;/* to carry char of the password from UART*/
NumberOfCharInPassword=0;
while (1)
{
	tempChar = UART_recieveByte();  /* start to receiving password bytes until the end Byte */
	if (tempChar== EndOfPasswordChar)
		break ;
	else
	{
		EEPROM_writeByte(AdressMemory, tempChar); /* Write tempChar in the external EEPROM */
		_delay_ms(10);
		NumberOfCharInPassword++;
		AdressMemory+=8; /* add 8 bites to the adress memory */
	}
}



}

/* function to recieve password from uart then check if is same at eeprom or not */
uint8 CheckPassword(void){
uint16 AdressMemory = 0x0311; /*  Address memory of EEPROM  firstly=0x0311 */
uint8 CounterChar =0; /* counter to count number of char in the checked password */
uint8 TempChar_UART; /* to carry char of the password from UART*/
uint8 TempChar_I2c; /* to carry char of the password from EEPROM*/
while (1)
{
	TempChar_UART = UART_recieveByte();  /* start to receiving password bytes until the end Byte*/
	if (TempChar_UART== EndOfPasswordChar) /* take password char until the end char */
	{
		if (CounterChar!=NumberOfCharInPassword) /* check number of char in password are same*/
			return 0;
		else
		return 1;   /* the end of password and is true */

	}
	else
	{
		EEPROM_readByte(AdressMemory, &TempChar_I2c); /* read AdressMemory from EEPROM and
		 put it in TempChar_I2c*/
	   if ( TempChar_UART != TempChar_I2c)
		   return 0;
		CounterChar++;
		AdressMemory+=8; /* add 8 bites to the adress memory */

	}
}

return 1 ;


}



/* function to initialize all required peripherials before start using them */
void InitModules(void){
	UART_init();
	Motor_init();
	TWI_init();
	EEPROM_init();
	Bazzar_Init();
}









