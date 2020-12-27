; ========== kadai 2 ========================================
	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

COUNTER1	EQU	0x0C		;作業用変数の設定
COUNTER2	EQU	COUNTER1+1	;汎用ファイルレジスタ0Chから
COUNTER3	EQU	COUNTER2+1	;汎用ファイルレジスタ0Chから
; ==========================================================

	ORG	0x000

	bsf	STATUS, RP0	;バンク０→１に切り替え
	clrf	TRISB		;TRISBをすべて0、全ビット出力設定に
	bcf	STATUS, RP0	;バンク１→０に切り替え

	clrf	PORTB		;すべて消灯


MAIN
	bsf	PORTB,0		;0番目のLED点灯
	call	delay05s		;時間待ちサブルーチン呼び出し
        
	bcf	PORTB,0		;0番目のLED消灯
	call	delay05s		;
	goto	MAIN		;無限ループ


delay05s
        movlw	0x32 ;50
        movwf	COUNTER3
        decfsz	COUNTER3, 1
        call	delay1s
        return


;1 *10^-4 * 100 = 1*10^-2
delay1s
        movlw	0x64 ;100
        movwf	COUNTER2
        decfsz	COUNTER2, 1
        call	delay01ms
        return


;0.4*10^-6 * 250 = 1 *10^-4
delay01ms
        movlw	0xf9 ;249
        movwf	COUNTER1
        call delay04us
        return


delay04us
        decfsz	COUNTER1, 1
        call delay04us
        return

END
