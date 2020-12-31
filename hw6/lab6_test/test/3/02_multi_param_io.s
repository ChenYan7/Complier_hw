	.section .bss
_a:
	.zero	4
	.align	4
_b:
	.zero	4
	.align	4
_c:
	.zero	4
	.align	4
t0:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d %d %d"
	.align	4
STR1:
	.string	"%d %d %d\n"
	.align	4

	.section .text
	.globl main

main:
	pushl $_c
	pushl $_b
	pushl $_a
	pushl $STR0
	call scanf
	addl $16, %esp
	pushl _c
	pushl _b
	pushl _a
	pushl $STR1
	call printf
	addl $16, %esp

	ret
