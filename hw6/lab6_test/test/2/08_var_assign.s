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
t1:
	.zero	4
	.align	4
t2:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d"
	.align	4
STR1:
	.string	"Test:%d"
	.align	4
STR2:
	.string	" %d"
	.align	4
STR3:
	.string	" %d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $20, %eax
	movl %eax, t0
	movl %eax, _a
	movl $16, %eax
	movl %eax, t1
	movl %eax, _c
	pushl $_b
	pushl $STR0
	call scanf
	addl $8, %esp
	pushl _a
	pushl $STR1
	call printf
	addl $8, %esp
	pushl _b
	pushl $STR2
	call printf
	addl $8, %esp
	pushl _c
	pushl $STR3
	call printf
	addl $8, %esp

	ret
