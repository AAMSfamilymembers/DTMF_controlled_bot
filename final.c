x#include<avr/io.h>
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
	char y;
	while(1)
	{
		
		x = PINC;
		if( x == 0b00000010)
			forward();

	    if( x == 0b00000100)
			left();
			
		if( x == 0b00000110)
			right();
			

		if( x == 0b00001000)
			backward();

		if( x == 0b00000101)
			stop();

		if( x == 0b00000111)
			{
				y = PINC & 0b00100000;
				if ( y== 0b00100000)
				{	backward();
					_delay_ms(500);
					left();
					_delay_ms(500);}
				if(y==0)
				forward();
			}
						
		
		
						
			
	
	}
}
