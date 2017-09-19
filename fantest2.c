#include<stdio.h>
#include<softPwm.h>
#include<wiringPi.h>

#define fan 13

int main()
{
	int i;
	int j = 0;
	if(wiringPiSetupGpio()==-1) return 1;
	pinMode(fan, OUTPUT);
	digitalWrite(fan , LOW);
	softPwmCreate(fan,0,100);

	printf("start\n");
	while(j<5){
		softPwmWrite(fan,100);
		sleep(10);
		softPwmWrite(fan, 0);
		sleep(10);
		softPwmWrite(fan,50);
		sleep(10);
		j++;
	}
	printf("end\n");
}
