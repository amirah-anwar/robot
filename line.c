# include <p18f452.h>
#include <analogRead.h>
#include <setup.h>
#include <delay.h>

#define set_point 3.5
#define base_speed 45


/*int my_value(float real_value) 
	{
		if(real_value > 615)
		{
			return 0;
		}	
		else
		{
			return 1;
		}
	}
*/
void main (void)
	{
		float weighted_sum,sensor_sum,s1,s2,s3,s4,s5,s6,s1p,s6p;
		float position,position_error,left_speed,right_speed;
		pinMode (6 , OUTPUT);
		pinMode (7 , OUTPUT);
		pinMode (8 , OUTPUT);
		pinMode (9 , OUTPUT);
		pinMode (13 , OUTPUT);
		digitalWrite (6, HIGH);
		digitalWrite(7,LOW);
		digitalWrite (8, HIGH);				
		digitalWrite(9,LOW);
		pinMode (14 , INPUT);
		pinMode (15 , INPUT);
		pinMode (16 , INPUT);
		pinMode (17 , INPUT);
		pinMode (18 , INPUT);
		pinMode (19 , INPUT);	
		PORTDbits.RD7 = 1;
		setup_ADC();		
		setup_motors();	
		while(1)
			{	
				//digitalWrite(13,HIGH);
/*				s1 = my_value(analogRead(0));
				s2 = my_value(analogRead(1));
				s3 = my_value(analogRead(2));
				s4 = my_value(analogRead(3));
				s5 = my_value(analogRead(4));
				s6 = my_value(analogRead(5));
*/
				s1 = PORTBbits.RB0;
				s2 = PORTBbits.RB1;
				s3 = PORTBbits.RB2;
				s4 = PORTBbits.RB3;
				s5 = PORTBbits.RB4;
				s6 = PORTBbits.RB5;

				weighted_sum = (s1*1)+(s2*2)+(s3*3)+(s4*4)+(s5*5)+(s6*6);
				sensor_sum = s1+s2+s3+s4+s5+s6;
					position = weighted_sum / sensor_sum;
					position_error = set_point - position;	
					right_speed = base_speed + (position_error * 12);
					left_speed = base_speed - (position_error * 12);
					set_motors (right_speed,left_speed);
				
			}

	}