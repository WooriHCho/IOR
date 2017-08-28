#include <stdio.h>
#include <wiringPi.h>
#define fan1 18

int main()
{
	if(wiringPiSetupGpio() == -1)
		return 1;
	
	pinMode(fan1, OUTPUT);
	
	int x = 0;
	while(1)
	{
		digitalWrite(fan1, 0);
		printf("%d \n", x);
		x++;
		sleep(10);
		digitalWrite(fan1, 1);
		printf("%d \n", x);
		x++;
		sleep(10);
	}

	return 0;
}
