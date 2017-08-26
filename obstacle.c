# include <p18f452.h>
#include <analogRead.h>
#include <setup.h>
#include <delay.h>

#define arbitrary_constant 50

void main (void)
	{
		float ob1,ob2,ob1volt,ob2volt,left_speed,right_speed;
		pinMode (6 , OUTPUT);
		pinMode (7 , OUTPUT);
		pinMode (8 , OUTPUT);
		pinMode (9 , OUTPUT);
		digitalWrite (6, HIGH);
		digitalWrite(7,LOW);
		digitalWrite (8, HIGH);				
		digitalWrite(9,LOW);
		setup_ADC();
		while(1)
			{
				ob1 = analogRead(0);	//left sensor
				ob2 = analogRead(1);    //right sensor
				ob1volt = (ob1 * 5) / 1024;
				ob2volt = (ob2 * 5) / 1024;
	
				if (ob2volt != ob1volt)
				{
					right_speed = ob2volt * arbitrary_constant; 
					left_speed = ob1volt * arbitrary_constant;
					setup_motors();
					set_motors (right_speed,left_speed);
					
				}
				else
				{	
					if (ob2volt < 1 && ob1volt < 1)
					{
						setup_motors();
						set_motors (50,50);	
					}
					else
					{
						setup_motors();
						set_motors (80,10);
					}
				}

			}

	}