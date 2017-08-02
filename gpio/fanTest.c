#include <stdio.h>
#include <wiringPi.h>

#define LED1 13

int main (void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	pinMode(LED1,OUTPUT);
	while(1)
	{
	 digitalWrite(LED1,1);
	}
  return 0;
}
