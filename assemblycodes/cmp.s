	.file	"len.c"
	.arch msp430x2013

	.text
	.p2align 1,0
.global	main
	.type	main,@function
/***********************
 * Function `main' 
 ***********************/
main:
	mov	#__stack, r1 
	mov	r1, r4 
	/* prologue ends here (frame size = 0) */
.L__FrameSize_main=0x0
.L__FrameOffset_main=0x2

	/*my simple program to implement strcmp*/
	mov #01, &0x022
	mov #0, &0x021
	mov #0x21, r7
	mov #512, r5
	mov #528, r6
L1:	cmp @r5, @r6
	jnz L2
	cmp #0, @r5
	jz L3
	inc r5
	inc r6
	jmp L1
L2:	mov #1,@r7
L3:	mov @r7,r8


	/* epilogue: frame size = 0 */
	br	#__stop_progExec__
.Lfe1:
	.size	main,.Lfe1-main
;; End of function 


/*********************************************************************
 * File len.c: code size: 7 words (0x7)
 * incl. words in prologues: 3, epilogues: 4
 *********************************************************************/
