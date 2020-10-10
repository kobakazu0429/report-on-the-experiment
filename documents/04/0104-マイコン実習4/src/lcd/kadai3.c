#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void){
	U1MODE = 0x8400;
	U1BRG = 95;
	U1STA = 0x0400;
	init_LCD();
	char data[] = {'0','1','2','3','4','5','6','7','8','9'};
	char split = ',';
	
	int i = 0;
	for(;i < 10; i++) {
		U1TXREG = data[i];
		put_char(data[i]);
		U1TXREG = split;
		put_char(split);
	}

	while(1);
}
