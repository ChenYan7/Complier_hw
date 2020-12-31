	.section .bss
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
t3:
	.zero	4
	.align	4
t4:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d\n"
	.align	4

	.section .text
	.globl main

main:
	movl t0, %eax
	imull _point, %eax
	movl %eax, t0
	movl $0, %eax
	movl %eax, t0
	movl %eax, _i
label0:
	movl _i, %eax
	cmp $10, %eax
	jl label1
	jmp label2
label1:
	movl _i, %eax
	addl $10, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t2
	movl %eax, _a
	movl t0, %eax
	movl %eax, t3
	movl %eax, _point
	pushl t0
	pushl $STR0
	call printf
	addl $8, %esp

	movl _i, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _i
	JMP label0
label2:

	ret
