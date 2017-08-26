# include <p18f452.h>
#include <analogRead.h>
#include <setup.h>
#include <delay.h>

#define arbitrary_constant 40

void main (void)
	{
		float li1,li2,li1volt,li2volt,left_speed,right_speed;
		pinMode (6 , OUTPUT);
		pinMode (7 , OUTPUT);
		pinMode (8 , OUTPUT);
		pinMode (9 , OUTPUT);
		digitalWrite (6, HIGH);
		digitalWrite(7,LOW);
		digitalWrite (8, HIGH);				
		digitalWrite(9,LOW);
		setup_ADC();
		setup_motors();
		while(1)
			{
				li1 = analogRead(4);	//left sensor
			//	li2 = analogRead(1);    //right sensor
				li1volt = (li1 * 5) / 1024;
			//	li2volt = (li2 * 5) / 1024;
	
				if(li1volt > 2)
				{
						set_motors (0,100);
				}
				if(li1volt < 2)
				{
						set_motors (100,0);
				}
			/*	if (li2volt != li1volt)
				{
					right_speed = li1volt * arbitrary_constant; 
					left_speed = li2volt * arbitrary_constant;
					
					set_motors (right_speed,left_speed);
					
				}
				else
				{	
					if (li2volt < 1 && li1volt < 1)
					{
						set_motors (50,50);	
					}
					else
					{
						set_motors (50,50);
					}
				}
*/
			}

	}