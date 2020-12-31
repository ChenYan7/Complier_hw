	.section .bss
_a:
	.zero	4
	.align	4
_a:
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
t5:
	.zero	4
	.align	4
t6:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"Test %d %d\n"
	.align	4
STR1:
	.string	"Test %d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	movl $1, %eax
	movl %eax, t1
	movl %eax, _a
	movl $0, %eax
	movl %eax, t2
	movl %eax, _i
label0:
	movl _i, %eax
	cmp $10, %eax
	jl label1
	jmp label2
label1:
	movl _i, %eax
	imull $10, %eax
	movl %eax, t6
	XOR %edx, %edx
	movl _i, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl $3, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t0
	movl t6, %eax
	addl t0, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t4
	movl %eax, _a
	pushl _a
	pushl _i
	pushl $STR0
	call printf
	addl $12, %esp

	movl _i, %eax
	addl $1, %eax
	movl %eax, t0
	movl t0, %eax
	movl %eax, t3
	movl %eax, _i
	JMP label0
label2:
	pushl _a
	pushl $STR1
	call printf
	addl $8, %esp

	ret
