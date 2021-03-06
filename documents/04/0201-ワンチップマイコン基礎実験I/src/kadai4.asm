; ========== List 4 ========================================
	list	p=16F84A
	#include <p16F84A.inc>
	__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

COUNTER1	EQU	0x0C		;作業用変数の設定
COUNTER2	EQU	0x0D		;汎用ファイルレジスタ0Chから
; ==========================================================

	ORG	0x000

	bsf	STATUS, RP0	;バンク０→１に切り替え
	clrf	TRISB		;TRISBをすべて0、全ビット出力設定に
	bcf	STATUS, RP0	;バンク１→０に切り替え

	clrf	PORTB		;すべて消灯

MAIN
	movlw	0x01		;Wレジスタに01hを代入
	movwf	PORTB		;PORTBに値を転送→0番目のLED点灯
	call	WAIT		;時間待ちサブルーチン呼び出し
	movlw	0x03		;
	movwf	PORTB		;
	call	WAIT		;
	movlw	0x07		;
	movwf	PORTB		;
	call	WAIT		;
	movlw	0x0f		;
	movwf	PORTB		;
	call	WAIT		;
    movlw	0x1f		;
	movwf	PORTB		;
	call	WAIT		;
    movlw	0x3f		;
	movwf	PORTB		;
	call	WAIT		;
    movlw	0x7f		;
	movwf	PORTB		;
	call	WAIT		;
    movlw	0xff		;
	movwf	PORTB		;
	call	WAIT		;
	goto	MAIN		;無限ループ

WAIT	clrf	COUNTER1	;変数１をクリア

WAIT1	clrf	COUNTER2	;変数２をクリア
	call	WAIT2		;さらにサブルーチンへ
	decfsz	COUNTER1, 1	;変数から１を引く
	goto	WAIT1		;結果が0でなければ実行
	return			;結果が0ならばスキップしこの行を実行

WAIT2	decfsz	COUNTER2, 1	;サブルーチンのサブルーチン
	goto	WAIT2
	return

	END
