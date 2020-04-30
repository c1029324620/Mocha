
#define F_CPU 16000000UL									/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>										/* Include AVR std. library file */
#include <util/delay.h>									/* Include delay header file */
#include <inttypes.h>									/* Include integer type header file */
#include <stdlib.h>										/* Include standard library file */
#include <stdio.h>	
#include <math.h>									/* Include standard library file */
#include "MPU6050_def.h"							/* Include MPU6050 register define file */
#include "i2c_master.h"							/* Include I2C Master header file */
#include "uart.h"							/* Include USART header file */

float Acc_x,Acc_y,Acc_z,Temperature,Gyro_x,Gyro_y,Gyro_z;

void MPU6050_Init()										/* Gyro initialization function */
{
	_delay_ms(150);										/* Power up time >100ms */
	I2C_Start_Wait(0xD0);								/* Start with device write address */
	I2C_Write(SMPLRT_DIV);								/* Write to sample rate register */
	I2C_Write(0x07);									/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);								/* Write to power management register */
	I2C_Write(0x01);									/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);									/* Write to Configuration register */
	I2C_Write(0x00);									/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);								/* Write to Gyro configuration register */
	I2C_Write(0x18);									/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);								/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();
}

void MPU_Start_Loc()
{
	I2C_Start_Wait(0xD0);								/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);							/* Write start location address from where to read */
	I2C_Repeated_Start(0xD1);							/* I2C start with device read address */
}

void Read_RawValue()
{
	MPU_Start_Loc();									/* Read Gyro values */
	Acc_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Temperature = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Nack());
	I2C_Stop();
}


int main()
{
	//Variable Declarations
	char buffer[20];
	char float_val[10];
	float X_a,Y_a,Z_a;			//Acceleration Values X-Y-Z
	float X_g=0,Y_g=0,Z_g=0;		//Gyro Values X-Y-Z
	
	I2C_Init();						//Initialize I2C
	MPU6050_Init();					//Initialize MPU6050
	USART_Init(9600);				//Initialize UART
	
	while(1)
	{
		Read_RawValue();			//Call Read_RawValue Function
		
		X_a = Acc_x/16384.0;		//Acceleration-X
		Y_a = Acc_y/16384.0;		//Acceleration-Y
		Z_a = Acc_z/16384.0;		//Acceleration-Z
		
		X_g = Gyro_x/16.4;			//Gyro-X
		Y_g = Gyro_y/16.4;			//Gyro-Y
		Z_g = Gyro_z/16.4;			//Gyro-Z

		//Read/Print Acceleration-X
		dtostrf( X_a, 3, 2, float_val );
		sprintf(buffer," Ax = %s g\t",float_val);
		USART_SendString(buffer);
		
		//Read/Print Acceleration-Y
		dtostrf( Y_a, 3, 2, float_val );
		sprintf(buffer," Ay = %s g\t",float_val);
		USART_SendString(buffer);
		
		//Read/Print Acceleration-Z
		dtostrf( Z_a, 3, 2, float_val );
		sprintf(buffer," Az = %s g\t",float_val);
		USART_SendString(buffer);
		
		//Read/Print Gyro-X
		dtostrf( X_g, 3, 2, float_val );
		sprintf(buffer," Gx = %s%c/s\t",float_val,0xF8);
		USART_SendString(buffer);
		
		//Read/Print Gyro-Y
		dtostrf( Y_g, 3, 2, float_val );
		sprintf(buffer," Gy = %s%c/s\t",float_val,0xF8);
		USART_SendString(buffer);
		
		//Read/Print Gyro-Z
		dtostrf( Z_g, 3, 2, float_val);
		sprintf(buffer," Gz = %s%c/s\r\n",float_val,0xF8);
		USART_SendString(buffer);
		_delay_ms(1000);
	}
}//End Main