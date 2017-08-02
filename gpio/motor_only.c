#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR 13

int main(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(MOTOR, PWM_OUTPUT);
	
	

	int i=0;
	while(i <100)
	{
		pwmWrite(MOTOR, 25);
		delay(3000);
			
		
		pwmWrite(MOTOR, 0);
		i++;
		delay(3000);
	}
	return 0;
}