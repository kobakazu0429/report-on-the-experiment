;===========List 6===================================
	list   p=16F84A
	#include  <P16F84A.INC>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

	ORG  0x000

	bsf	STATUS,RP0		;バンク０→１に切り替え
	movlw	B'00011111'	;Wレジスタの下位5ビットを1に
	movwf	TRISA		;PORTAを入力に
	movlw	B'00000000'	;Wレジスタに0を代入
	movwf	TRISB		;PORTBを出力設定に
	bcf	STATUS,RP0	;バンク１→０に切り替え

	clrw			;Wレジスタをクリア

MAIN	bcf	STATUS,C	;Cフラグクリア
	movf	PORTA,0		;入力データをWレジスタに
	call	SS_Data		;7セグLED点灯データ取得ルーチンに
	movwf	PORTB		;データ表示
	goto	MAIN

;7セグLED点灯データ取得ルーチン

SS_Data
	addwf	PCL,1
	retlw	B'00111111'	;W+PCL(プログラムカウンタの下位)→PCL
	retlw	B'00000110'	;W=0→左の点灯データをWレジスタが持って帰る
	retlw	B'01011011'	;W=1→左の点灯データをWレジスタが持って帰る
	retlw	B'01001111' ;w=3
	retlw	B'01100110' ;w=4
	retlw	B'01101101' ;w=5
	retlw	B'01111101' ;w=6
	retlw	B'00000111' ;w=7
	retlw	B'01111111' ;w=8
	retlw	B'01101111' ;w=9
	retlw	B'01110111'	;W=10→"A"のデータを持って帰る
	retlw	B'01111100'	;W=11→"b"のデータを持って帰る
	retlw	B'01011000'	;W=12→"c"のデータを持って帰る
	retlw	B'01011110'	;W=13→"d"のデータを持って帰る
	retlw	B'01111001'	;W=14→"E"のデータを持って帰る
	retlw	B'01110001'	;W=15→"F"のデータを持って帰る

	END
