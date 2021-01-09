	.section .bss
_a:
	.zero	4
	.align	4
_s:
	.zero	4
	.align	4
_ch:
	.zero	4
	.align	4
_b:
	.zero	4
	.align	4
_i:
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
t7:
	.zero	4
	.align	4
t8:
	.zero	4
	.align	4
t9:
	.zero	4
	.align	4
t10:
	.zero	4
	.align	4

	.section .rodata
STR0:
	.string	"%c"
	.align	4
STR1:
	.string	"%c\n"
	.align	4
STR2:
	.string	"result is: %d\n"
	.align	4
STR3:
	.string	"Have fun: %d\n"
	.align	4

	.section .text
	.globl main

main:
	movl $10, %eax
	movl %eax, t0
	movl %eax, _a
	movl $0, %eax
	movl %eax, t1
	movl %eax, _s
	pushl $_ch
	pushl $STR0
	call scanf
	addl $8, %esp
	pushl _ch
	pushl $STR1
	call printf
	addl $8, %esp
label0:
	movl _a, %eax
	cmp $0, %eax
	jg label3
	jmp label2
label3:
	movl _a, %eax
	cmp $10, %eax
	jle label1
	jmp label4
label4:
	XOR %edx, %edx
	movl _a, %eax
	cmp %edx, %eax
	jge O0
	movl $0, %edx
	not %edx
O0:
	movl $100, %ebx
	idiv %ebx
	XOR %eax, %eax
	movl %edx, t7
	movl t7, %eax
	cmp $10, %eax
	je label1
	jmp label2
label1:
	movl _a, %eax
	subl $1, %eax
	movl %eax, t0
	movl %eax, _a
	movl _s, %eax
	addl _a, %eax
	movl %eax, t0
	movl %eax, _s
	movl $10, %eax
	imul $-1, %eax
	movl %eax, t0
	movl _s, %eax
	cmp t0, %eax
	jg label5
	jmp label6
label5:
	pushl _s
	pushl $STR2
	call printf
	addl $8, %esp
	movl $10, %eax
	movl %eax, t9
	movl %eax, _b
	movl $0, %eax
	movl %eax, t10
	movl %eax, _i
label7:
	movl _i, %eax
	cmp _b, %eax
	jl label8
	jmp label9
label8:
	pushl _i
	pushl $STR3
	call printf
	addl $8, %esp

	movl _i, %eax
	movl %eax, t0
	addl $1, %eax
	movl %eax, _i
	JMP label7
label9:

label6:

	jmp label0
label2:

	ret
