#include<stdio.h>
#include<wiringPi.h>
#define LED1 13
int main(void){
	if(wiringPiSetupGpio()== -1)
		return 1;
	pinMode(LED1, OUTPUT);
	while(1){

		digitalWrite(LED1,0);
		delay(5000);
		digitalWrite(LED1, 1);
		delay(5000);
	}
	return 0;
}

