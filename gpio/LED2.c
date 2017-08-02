#include <stdio.h>
#include <wiringPi.h>

#define LED1 13
#define LED2 19

int main (void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED1,OUTPUT);
	pinMode(LED2,OUTPUT);

	while(1)
	{
	 digitalWrite(LED1,1);
	 digitalWrite(LED2,1);

	 delay(1000);
	 
	 digitalWrite(LED1,0);
	 digitalWrite(LED2,0);

	 delay(1000);
	}
  return 0;
}
