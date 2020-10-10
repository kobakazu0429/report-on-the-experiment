#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void){
	U1MODE = 0x8400;
	U1BRG = 95;
	U1STA = 0x0400;
	init_LCD();
	char* greet = "Hello PC";

	while(*greet != '\0'){
		U1TXREG = *greet;
		put_char(*greet);
		greet++;
	}

	while(1);
}
