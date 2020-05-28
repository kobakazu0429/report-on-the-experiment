#include <p30F3013.h>
#include <string.h>
#include <stdio.h>

#define	E_pin	PORTFbits.RF4		// RF4 as signal enable
#define	RS_pin	PORTFbits.RF5		// RF5 as select register
#define	TRIS_E	TRISFbits.TRISF4
#define	TRIS_RS	TRISFbits.TRISF5

//-----------------------------------------------
// delay time

void wait(unsigned x) {
	unsigned i;
	for(i=0 ; i<x ; i=i+1)
		asm("nop");
}

void delayms(unsigned x){
	unsigned i, j;
	for(i=0 ; i<x ; i=i+1) {
		for (j=0; j<4850; j=j+1)
			asm("nop");
	}
}

void delay600ns(void){
	unsigned i;
	for(i=0 ; i<18 ; i=i+1)
		asm("nop");
}

//-----------------------------------------------
// LCD

void dataout(void){
	E_pin = 1;
	delay600ns();
	E_pin = 0;
}

void locate(char x, char y){
	RS_pin = 0;				// RS = 0
	delayms(15);

	if(y==0)
		PORTB = 0x80;		// row = 0
	else
		PORTB = 0xc0;		// row = 1
	dataout();

	PORTB = x << 4;			// send column data
	dataout();
}

void put_char(char x){
	char temp = x;
	temp &= 0xf0;			// lower 4 bits clear

	RS_pin = 1;				// RS = 1
	delayms(15);

	PORTB = temp;			// send upper 4 bits
	dataout();
	PORTB = x << 4;			// send lower 4 bits
	dataout();
}

void put_str(char *str){
	while(*str != '\0'){	// while exist data
		put_char(*str);
		str++;
	}
}

void reverse(char s[]){
	int i, j;
	char c;
	for(i=0, j=strlen(s)-1 ; i<j ; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void put_num(int n){
	char s[18];
	int i=0, sign;

	if((sign = n) < 0)
		n = -n;

	do{
		s[i++] = n%10 + 0x30;	// +30 is d to s
	}while((n /= 10) > 0);

	if(sign < 0)
		s[i++]='-';

	s[i] = '\0';
	reverse(s);

	put_str(s);
}

void clr_LCD(void){
	RS_pin = 0;			// RS = 0
	delayms(15);

	PORTB = 0x0000;		// LCD Clear
	dataout();
	PORTB = 0x0010;
	dataout();
}

void open_LCD(void){

	RS_pin = 0;			// RS = 0

	delayms(15);
	PORTB=0x0030;
	dataout();

	delayms(15);
	PORTB=0x0030;
	dataout();

	delayms(15);
	PORTB=0x0030;
	dataout();

	delayms(15);
	PORTB=0x0020;
	dataout();

	delayms(15);

	PORTB=0x0020;		// Function set
	dataout();
	PORTB=0x0080;
	dataout();

	delayms(15);

	PORTB=0x0000;		// Display ON/OFF
	dataout();
	PORTB=0x00c0;
	dataout();

	delayms(15);

	PORTB=0x0000;		// LCD Clear
	dataout();
	PORTB=0x0010;
	dataout();

	delayms(15);

	PORTB=0x0000;		// Entry Mode
	dataout();
	PORTB=0x0060;
	dataout();
}

void init_LCD(void){
	PORTB = 0x0000;
	E_pin = 0;			// E = 0
	RS_pin = 0;			// RS = 0

// PORTB 4,5,6,7bit is Output
	_TRISB4 = 0;
	_TRISB5 = 0;
	_TRISB6 = 0;
	_TRISB7 = 0;

	TRIS_E = 0;
	TRIS_RS = 0;

	open_LCD();
	clr_LCD();
}

//-------------------------------------------------
// ADC

int smp_INT(void){
	int val;

	ADCON1bits.SAMP = 1;		// start sampling
	delayms(100);
	ADCON1bits.SAMP = 0;		// start converting

	while (!ADCON1bits.DONE){	// conversion done ?
		val = ADCBUF0;			// get ADC value
	}
	return val;
}

void init_ADC(void){

	ADCON1 = 0x0000;			// SAMP bit=0 ends sampling
	ADCON2 = 0x0000;
	ADCON3 = 0x0003;			// Manual Sample, Tad=internal 3 Tcy

//del	ADPCFG = 0xFEFF;			// RB8=analog
//del 	ADCHS = 0x0008;				// Connect RB8/AN8 as CH0 input
	ADPCFG = 0xFFFE;			// RB0=analog
	ADCHS = 0x0000;				// Connect RB0/AN0 as CH0 input
	ADCSSL = 0;
	ADCON1bits.ADON = 1;		// turn ADC on
}

//---------------------------------------------------
// 8x8 dot matrix LED

void send_bit(unsigned char data){
	unsigned i;

	for(i=0 ; i<8 ; i=i+1) {
		wait(10);
		_RB3 = 0;				// CLOCK=0
		wait(10);

		if (0x80<=data) {		// send data bit
			_RB1 = 1;
		 } else {
			_RB1 = 0;
		}

		data = data<<1;			// shift data bits
		wait(10);
		_RB3=1;					// CLOCK=1
	}
}

void send_one(unsigned char adrs, unsigned char data) {

	_RB2=0;						// LOAD=0

	send_bit(adrs);				// write address
	send_bit(data);				// write data

	wait(10);
		_RB2=1;					// LOAD=1
	wait(10);
		_RB3=0;					// CLOCK=0
	wait(10);
}

void send_dual(unsigned char adrs1, unsigned char data1, unsigned char adrs2, unsigned char data2) {

	_RB2=0;						// LOAD=0
	
	send_bit(adrs2);			// write address2
	send_bit(data2);			// write data2
	send_bit(adrs1);			// write address1
	send_bit(data1);			// write data1
	
	wait(10);
		_RB2=1;					// LOAD=1
	wait(10);
		_RB3=0;					// CLOCK=0
	wait(10);
}

void init_MTLED(void) {
	unsigned i;

	_RB2=1;						// LOAD=1
	_RB3=0;						// CLOCK=0
	_TRISB1=0;					// RB1 DATA output
	_TRISB2=0;					// RB2 LOAD output
	_TRISB3=0;					// RB3 CLOCK output
	
	send_dual(0x0f, 0x00, 0x0f, 0x00);	// set display test reg - normal operation

	for(i=1 ; i<=8 ; i=i+1) {
		send_dual(i, 0, i, 0);			// clear data reg
	}

	send_dual(0x09, 0x00,0x09, 0x00);	// set decode moode reg - no decode
	send_dual(0x0a, 0x0f,0x0a, 0x0f);	// set intensity reg - maximum brightness
	send_dual(0x0b, 0x07,0x0b, 0x07);	// set scan limit reg - no limit
	send_dual(0x0c, 0x01,0x0c, 0x01);	// seet shutdown reg - normal operation

}

//--------------------------------------------------
