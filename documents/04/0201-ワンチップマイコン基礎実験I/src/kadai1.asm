; ========== List 1 ========================================
	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

	ORG	0x000

	bsf	STATUS, RP0	;バンク０→１に切り替え
	clrf	TRISB		;TRISBをすべて0、全ビット出力設定に
	bcf	STATUS, RP0	;バンク１→０に切り替え

	clrf	PORTB		;すべて消灯
	bsf	PORTB,1		;0番目のLED点灯

STP	goto	STP		;無限ループ

	END
