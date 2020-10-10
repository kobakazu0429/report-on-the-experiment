#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void){
	char x;
	U1MODE = 0x8400;
	U1BRG = 95;
	U1STA = 0x0400;
	init_LCD();

	while(1){
		while(U1STAbits.URXDA!=1);
			x=U1RXREG;
			put_char(x);
		while(U1STAbits.UTXBF!=0);
			U1TXREG=x;
	}
}
