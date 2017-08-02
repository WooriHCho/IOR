#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR 13

int main()
{
    	int i;
   	int x;
    	if(wiringPiSetupGpio() == -1)
		return 1;

	pinMode(MOTOR, OUTPUT);
    	digitalWrite(MOTOR, LOW);
   	softPwmCreate(MOTOR, 0, 100);
	while(1){
		printf("input angle:");
		scanf("%d", &x);
		
		x = x / 10 + 2;
		
		printf("%d\n", x);
		softPwmWrite(MOTOR, x);
		//delay(15);
		sleep(1);
	
	}
	
	//printf("1 \n");
	

	/*for(i = 51; i<= 100; i++){
		softPwmWrite(MOTOR, i);
		delay(15);
	}
	printf("2 \n");
	

	for(i = 101; i<= 140; i++){
		softPwmWrite(MOTOR, i);
		delay(15);
	}
	printf("3 \n");
	

	for(i = 141; i<= 180; i++){
		softPwmWrite(MOTOR, i);
		delay(15);
	}
	printf("4 \n");*/

	return 0;
}
