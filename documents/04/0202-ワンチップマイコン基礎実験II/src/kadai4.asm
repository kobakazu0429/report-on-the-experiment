; ========== kadai 4 ========================================
	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

COUNTER1	EQU	0x0C		;作業用変数の設定
COUNTER2	EQU	0x0D		;汎用ファイルレジスタ0Chから
COUNTER3	EQU	0x0E		;
COUNTER4	EQU	0x0F		;
COUNTER5	EQU	0x10		;
COUNTER6	EQU	0x11		;
COUNTER7	EQU	0x12		;
COUNTER8	EQU	0x13		;
COUNTER9	EQU	0x14		;
; ==========================================================

	ORG	0x000

	bsf	STATUS, RP0	;バンク０→１に切り替え
	clrf	TRISA		;
	bcf	STATUS, RP0	;バンク１→０に切り替え

	clrf	PORTA		;すべて消灯
MAIN
	clrf	COUNTER7	;
	call	MUSC		;
	clrf	COUNTER8	;
	call	MUSD		;
	clrf	COUNTER9	;
	call	MUSE		;
	goto	MAIN		;

MUSC	bsf	PORTA,3		;
	call	WAIT1		;時間待ちサブルーチン呼び出し
	bcf	PORTA,3		;
	call	WAIT1		;
	decfsz	COUNTER7, 1	;変数から１を引く
	goto	MUSC		;結果が0でなければ実行
	return

MUSD	bsf	PORTA,3		;
	call	WAIT4		;時間待ちサブルーチン呼び出し
	bcf	PORTA,3		;
	call	WAIT4		;
	decfsz	COUNTER8, 1	;変数から１を引く
	goto	MUSD		;結果が0でなければ実行
	return

MUSE	bsf	PORTA,3		;
	call	WAIT7		;時間待ちサブルーチン呼び出し
	bcf	PORTA,3		;
	call	WAIT7		;
	decfsz	COUNTER9, 1	;変数から１を引く
	goto	MUSE		;結果が0でなければ実行
	return

WAIT1	movlw 	0xB0		;
	movwf	COUNTER1	;

WAIT2	movlw	0x02		;
	movwf	COUNTER2	;
	call	WAIT3		;さらにサブルーチンへ
	decfsz	COUNTER1, 1	;変数から１を引く
	goto	WAIT2		;結果が0でなければ実行
	return			;結果が0ならばスキップしこの行を実行

WAIT3	decfsz	COUNTER2, 1	;サブルーチンのサブルーチン
	goto	WAIT3
	return

WAIT4	movlw 	0xA0		;
	movwf	COUNTER3	;

WAIT5	movlw	0x02		;
	movwf	COUNTER4	;
	call	WAIT6		;さらにサブルーチンへ
	decfsz	COUNTER3, 1	;変数から１を引く
	goto	WAIT5		;結果が0でなければ実行
	return			;結果が0ならばスキップしこの行を実行

WAIT6	decfsz	COUNTER4, 1	;サブルーチンのサブルーチン
	goto	WAIT6
	return

WAIT7	movlw 	0x90		;
	movwf	COUNTER5	;

WAIT8	movlw	0x02		;
	movwf	COUNTER6	;
	call	WAIT9		;さらにサブルーチンへ
	decfsz	COUNTER5, 1	;変数から１を引く
	goto	WAIT8		;結果が0でなければ実行
	return			;結果が0ならばスキップしこの行を実行

WAIT9	decfsz	COUNTER6, 1	;サブルーチンのサブルーチン
	goto	WAIT9
	return

	END
