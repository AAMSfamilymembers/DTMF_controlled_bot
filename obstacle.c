#include<avr/io.h>
#include<util/delay.h>
forward()
{
	PORTB = 0b11111010;
}

backward()
{
	PORTB=0b11110101;	
}

stop()
{
	PORTB=0b11110000;
}
left()
{
	PORTB=0b11110110;
}
right()
{
	PORTB=0b11111001;
}
main()
   {
	DDRB = 0b11111111;
	DDRC = 0;
	char x;
	while(1)
	{
		x = PINC & 0b00000001;
		if ( x== 0b00000001)
		{	backward();
			_delay_ms(1000);
			left();
			_delay_ms(1000);}
		if (x==0)
			forward();

	}
	}
