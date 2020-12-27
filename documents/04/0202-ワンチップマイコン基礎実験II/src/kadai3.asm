	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

	COUNTER1	EQU	0x0C		;作業用変数の設定

	ORG	0x000

	bsf	STATUS, RP0	;バンク０→１に切り替え
	clrf	TRISA		;TRISAをすべて0、全ビット出力設定に
	bcf	STATUS, RP0	;バンク１→０に切り替え

	clrf	PORTA		;すべて消灯
	clrf	PORTB		;すべて消灯

MAIN
	bsf	PORTA, 3		;Wレジスタに01hを代入
	call	WAIT

	bcf	PORTA, 3		;Wレジスタに01hを代入
	call	WAIT
    
	goto MAIN


WAIT
	movlw	0xF9;
	movwf	COUNTER1	;変数１をクリア


WAIT1
	nop
	nop
	decfsz	COUNTER1, 1	;変数から１を引く
	goto	WAIT1		;結果が0でなければ実行
	return			;結果が0ならばスキップしこの行を実行

	END
