	.section .bss
t0:
	.zero	4
	.align	4
t1:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%d\n"
	.align	4
STR1:
	.string	"Continue\n"
	.align	4

	.section .text
	.globl main

main:
	movl $0, %eax
	movl %eax, t0
	movl %eax, _i
label0:
	movl _i, %eax
	cmp $10, %eax
	jl label1
	jmp label2
label1:
	pushl _i
	pushl $STR0
	call printf
	addl $8, %esp
	movl _i, %eax
	cmp $5, %eax
	jl label3
	jmp label4
label3:
	pushl $STR1
	call printf
	addl $4, %esp

label4:

	movl _i, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t1
	movl %eax, _i
	JMP label0
label2:

	ret
