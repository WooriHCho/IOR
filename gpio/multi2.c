#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR 13

int main(void)
{
	int i = 0;
	int j = 0;
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(MOTOR, OUTPUT);
	digitalWrite(MOTOR, LOW);
	softPwmCreate(MOTOR, 0, 200);

	/*
	while(i<5)
	{

		softPwmWrite(MOTOR, 200);
		printf("MOTOR 200 \n");
		delay(2000);

		digitalWrite(MOTOR, LOW);
		softPwmWrite(MOTOR, 20);
		printf("MOTOR 20 \n");
		delay(2000);
		i++;
	}
	*/

	while(j<5)
	{	
		printf("MOTOR RUN RIGHT \n");
		for(i = 0; i<=180; i++)
		{
			softPwmWrite(MOTOR, i);
			delay(15);
		}
		delay(1000);

		printf("MOTOR RUN LEFT \n");
		for(i=180; i>=0; i--)
		{
			softPwmWrite(MOTOR, i);
			delay(15);
		}
		delay(1000);
		j++;
	}
	return 0;
}
