#include <wiringPi.h>
#include <softPwm.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAXTIMINGS	85
#define DHTPIN	4	
#define fan 19

int dht11_dat[5] = { 0, 0, 0, 0, 0 };

int read_dht11_dat()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; /* fahrenheit */

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	/* pull pin down for 18 milliseconds */
	pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, LOW );
	delay( 18 );
	/* then pull it up for 40 microseconds */
	digitalWrite( DHTPIN, HIGH );
	delayMicroseconds( 40 );
	/* prepare to read the pin */
	pinMode( DHTPIN, INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHTPIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHTPIN );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) &&
	     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
		f = dht11_dat[2] * 9. / 5. + 32;
		printf( "Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",
			dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
		return dht11_dat[2];
	}else  {
		printf( "Data not good, skip\n" );
	}
}

int main( void )
{
	printf( "Raspberry Pi wiringPi DHT11 Temperature test program\n" );
	if ( wiringPiSetupGpio() == -1 )
		exit( 1 );

	pinMode(fan, OUTPUT);
	digitalWrite(fan, LOW);
	softPwmCreate(fan, 0, 100);
	int j = 0;
	int i;
	int temp;

	while ( 1 )
	{
		temp=read_dht11_dat();
		if(temp >= 26)
		{
			softPwmWrite(fan, 100);
			sleep(3);
		}
		delay( 1000 ); /* wait 1sec to refresh */
		if(temp <= 25)
		{
			softPwmWrite(fan, 50);
			sleep(3);
		}
	}

	return(0);
}
