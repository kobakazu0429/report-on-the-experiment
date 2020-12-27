;==========List 7====================================
list   p=16F84A
#include  <P16F84A.INC>
__CONFIG  _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

Memory		EQU	0x0C
WORK		EQU	Memory+0
Temp_STATUS	EQU	Memory+1
Temp_PORTB	EQU	Memory+2
COUNTER1	EQU	Memory+3
COUNTER2	EQU	Memory+4
Temp_COUNTER1	EQU	Memory+5
Temp_COUNTER2	EQU	Memory+6
;====================================================

	ORG  0			;リセットベクタ
	goto	START

	ORG  4			;割り込みベクタ
	movwf	WORK		;Wレジスタのデータを退避

	movwf	B'00010000'	;MSBを0
	movwf	INTCON		;割り込み禁止

	movf	STATUS,0	;STATUSレジスタを退避
	movwf	Temp_STATUS	;
	movf	PORTB,0		;PORTBを退避
	movwf	Temp_PORTB	;
	movf	COUNTER1,0	;以下同様
	movwf	Temp_COUNTER1	;
	movf	COUNTER2,0	;
	movwf	Temp_COUNTER2	;

	call SUB		;割り込みサブルーチンのコール

	movf	Temp_COUNTER2,0	;退避した変数の復帰
	movwf	COUNTER2	;
	movf	Temp_COUNTER1,0	;以下同様
	movwf	COUNTER1	;
	movf	Temp_PORTB,0	;
	movwf	PORTB		;
	movf	Temp_STATUS,0	;
	movwf	STATUS		;

	movlw	B'10010000'	;MSBを1に
	movwf	INTCON		;RB0/INT割り込み許可

	swapf	WORK,1		;なぜswap命令を使うのだろうか？
	swapf	WORK,0		;最後にWレジスタのデータを復帰
	retfie			;割り込みからの復帰

;================================================================
;リセット後ここにジャンプして、初期設定を行う。

START	bsf	STATUS,RP0	;バンク0→1
	movlw	0x01		;LSBのみ1
	movwf	TRISB		;RB0を入力、RB1～RB7を出力に
	movlw	B'10010000'	;ビット6を0
	movwf	OPTION_REG	;立下りエッジによる刷り込みモード
	bcf	STATUS,RP0	;バンク1→0

	clrf	PORTB		;PORTBをクリア

	movlw	B'10010000'	;MSBを1に
	movwf	INTCON		;RB0/INT割り込み許可

;================================================================
;割り込み時以外の通常処理、今回はRB1のLEDを点滅させる。

MAIN	movlw	0x01		;
	andwf	PORTB,1		;PORTBのRB0以外をクリア
	call	WAIT		;
	movlw	0x02		;
	addwf	PORTB,1		;Wを加算してPORTBに上書き、RB1のみ1
	call	WAIT		;
	 goto	MAIN		;

;================================================================
;割り込み後の処理、今回はRB4のLEDを点滅させる。
;処理をNOP 2個の間に書く

SUB	nop			;割り込みサブルーチン
	movlw	0x01		;
	andwf	PORTB,1		;PORTBのRB0以外をクリア
	call	WAIT		;
	movlw	0x08		;RB3のみ1
	addwf	PORTB,1		;Wを加算してPORTBに上書き、RB4のみ1
	call	WAIT		;
	movlw	0x01		;
	andwf	PORTB,1		;PORTBのRB0以外をクリア
	call	WAIT		;
	movlw	0x04		;RB2のみ1
	addwf	PORTB,1		;Wを加算してPORTBに上書き、RB4のみ1
	call	WAIT		;
	nop
	return

;================================================================
;時間待ちサブルーチン

WAIT	clrf	COUNTER1

WAIT1	clrf	COUNTER2
	call	WAIT2
	decfsz	COUNTER1,1
	goto	WAIT1
	return

WAIT2	decfsz	COUNTER2,1
	goto	WAIT2
	return

	END
