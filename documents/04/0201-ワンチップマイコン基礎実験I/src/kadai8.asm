; ========== List 5 ========================================
	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

	ORG	0x000

	bsf	STATUS, RP0		;バンク０→１に切り替え
	movlw	B'00011111'		;下位5ビットを1に
	movwf	TRISA			;TRISAに代入、RA0からRA4が入力設定に
	movlw	B'00000000'		;Wレジスタにすべて0に
	movwf	TRISB			;TRISBをすべて0、出力設定に
	bcf	STATUS, RP0		;バンク１→０に切り替え

	clrw				;Wレジスタをクリア

MAIN
	bcf	STATUS,C		;Cフラグクリア
	movf	PORTA,	0			;入力データをWレジスタに転送
	rlf 	PORTA, 0
	movwf	PORTB			;ポートBに出力
	goto	MAIN

	END
