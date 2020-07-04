#include <p30F3013.h>

unsigned char hdata[16]={
	0x77, 
	0x41, 
	0x3b,
	0x6b,
	0x4d,
	0x6e,
	0x7e,
	0x43,
	0x7f,
	0x4f,
	0x5f,
	0x7c,
	0x36,
	0x79,
	0x3e,
	0x1e
};

void wait(unsigned x) {
	unsigned i, j;
	for (i=0; i<x; i=i+1) {
		for (j=0; j<60000; j=j+1){
			asm("nop");
		}
	}
}

void printNum(unsigned digit, unsigned number) {
	unsigned char adrs = digit == 1 ? 1 : 3;
	unsigned char x = hdata[number];
	while(U1STAbits.UTXBF!=0);
	U1TXREG=adrs+(x<<4);
	while(U1STAbits.UTXBF!=0);
	U1TXREG=adrs+((x>>4)<<4);
}

void main(void) {

	_TRISF6=0;       // RF6ポートを出力設定
	U1BRG =95;
	U1MODE=0x8000;
	U1STA =0x0400;

	_RF6=0;          // SN74LV8153をリセット
	wait(10);
	_RF6=1;          // SN74LV8153 release reset

	while(1){
		printNum(1, 0);
		printNum(2, 16);
		wait(60);

		printNum(1, 5);
		printNum(2, 8);
		wait(60);
	}
}
