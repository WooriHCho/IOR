#include <stdio.h>
#include <wiringPi.h>



#define LED1 24


int main(void)
{
	if(wiringPiSetupGpio() == -1)
		return 1;

	pinMode(LED1, OUTPUT);

	
	int i=0;
	while(i <5)
	{
		
			printf("LED1 ON\n");
			digitalWrite(LED1, 1);
			delay(2000);
		
			printf("LED1 OFF\n");
			digitalWrite(LED1, 0);	
			delay(2000);
		
		i++;
	}
	return 0;
}