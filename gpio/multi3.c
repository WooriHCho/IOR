#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR 13
#define LED1 24
#define BUTTON 19

int main(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(MOTOR, PWM_OUTPUT);
	pinMode(LED1, OUTPUT);
	pinMode(BUTTON, INPUT);
	

	int i=0;
	while(i <100)
	{
		if(digitalRead(BUTTON) == 0)
		{
			printf("LED1 ON\n");
			digitalWrite(LED1, 1);
			pwmWrite(MOTOR, 25);
			delay(100);
			
		}
		else
		{
			printf("LED1 OFF\n");
			digitalWrite(LED1, 0);
				
			//delay(200);
		}
		pwmWrite(MOTOR, 0);
		i++;
		delay(1000);
	}
	return 0;
}