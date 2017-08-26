# include <p18f452.h>
#include <delay.h>
void main (void)
	{
/*		TRISAbits.TRISA0 = 1;
		TRISAbits.TRISA1 = 1;
		TRISAbits.TRISA2 = 1;
		TRISAbits.TRISA3 = 1;
		TRISAbits.TRISA5 = 1;
		TRISEbits.TRISE0 = 1;
		TRISEbits.TRISE1 = 1;
		TRISEbits.TRISE2 = 1;
*/		TRISC =0;
		TRISD =0;
		TRISE=1;
//		TRISA=1;
		TRISB=0;
		while(1)
			{
			/*	PORTAbits.RA0 = 1;					
				PORTAbits.RA1 = 0;	
				PORTAbits.RA2 = 1;
				PORTAbits.RA3 = 0;
				PORTAbits.RA5 = 1;
				PORTEbits.RE0 = 0;					
				PORTEbits.RE1 = 1;	
				PORTEbits.RE2 = 0;
				PORTCbits.RC4 = 1;
				PORTCbits.RC5 = 0;
				PORTCbits.RC6 = 1;
				PORTCbits.RC7 = 0;
			*/	PORTCbits.RC1 = 1;
					Delay(500);
				PORTCbits.RC1 = 0;
				PORTCbits.RC2 = 1;
					Delay(500);
				PORTCbits.RC2 = 0;
			/*	PORTBbits.RB0 = 1;
				PORTBbits.RB1 = 0;
				PORTBbits.RB2 = 1;	
				PORTBbits.RB3 = 0;
				PORTBbits.RB4 = 1;
				PORTBbits.RB5 = 0;				
			*/}
	}