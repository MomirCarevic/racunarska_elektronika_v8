#include<wiringPi.h>
#include<stdio.h>
#include<unistd.h>

unsigned char WriteBuf;
unsigned char ReadBuf0, ReadBuf1, ReadBuf2, ReadBuf3;

int main(int argc, char **argv)
{
	if(wiringPiSetup( == -1))
	{
		return 1;
	}

	int fd = wiringPiI2CSetup(0x48);

	while(1)
	{
		WriteBuf = 0x00;
		wiringPiI2CWriteReg8(fd,0x00,WriteBuf);
		ReadBuf0 = wiringPiI2CReadReg8(fd,0x00);

		WriteBuf = 0x01;
		wiringPiI2CWriteReg8(fd,0x01,WriteBuf);
		ReadBuf1 = wiringPiI2CReadReg8(fd,0x01);

 		WriteBuf = 0x02;
		wiringPiI2CWriteReg8(fd,0x02,WriteBuf);
		ReadBuf2 = wiringPiI2CReadReg8(fd,0x02);

 		WriteBuf = 0x03;
		wiringPiI2CWriteReg8(fd,0x03,WriteBuf);
		ReadBuf3 = wiringPiI2CReadReg8(fd,0x03);

		printf("adc0: %5.2f adc1: %5.2f adc2: %5.2f adc3: %5.2f\n",(double)ReadBuf0 * 3.3 / 255,(double)ReadBuf1 * 3.3/ 255,(double)ReadBuf2* 3.3 / 255,(double)ReadBuf3* 3.3/ 255);
		printf ("\r") ; fflush (stdout) ;

		delay(100);

 	}

 	return 0;
	
}
