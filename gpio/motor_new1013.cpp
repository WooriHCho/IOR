#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR 13

int main(void)
{
	int j = 0;
	int i;
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(MOTOR, PWM_OUTPUT);
	
	softPwmCreate(MOTOR, 0, 50);

	while( j < 5)
	{
		for(i = 0; i< 180; i++)
		{	
			int duty = 1./18. *(i) +2;
			softPwmWrite(MOTOR, duty);	
		}
		
		j++;
	}
}