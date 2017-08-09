#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signal){
	printf("hello\n");
}

int main(void)
{
	int a;
	while(1){
		FILE *fp = fopen("/tmp/abc.txt", "r");
		signal(SIGUSR1, signal_handler);

		fscanf(fp, "%d", &a);
		if( a == 1)
		{
			printf("read\n");
		}
	sleep(3);
	fclose(fp);
	}
	
}
