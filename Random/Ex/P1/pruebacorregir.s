	.file	"pruebacorregir.c"
	.text
	.globl	corregir
	.type	corregir, @function
corregir:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L2
.L5:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L3
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L3
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L3
	addq	$1, -8(%rbp)
	jmp	.L4
.L3:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-16(%rbp), %rax
	movb	%dl, (%rax)
	addq	$1, -16(%rbp)
.L4:
	addq	$1, -8(%rbp)
.L2:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L5
	movq	-16(%rbp), %rax
	subq	$1, %rax
	movzbl	(%rax), %eax
	cmpb	$44, %al
	jne	.L6
	movq	-16(%rbp), %rax
	movb	$0, (%rax)
	jmp	.L8
.L6:
	movq	-16(%rbp), %rax
	movb	$0, (%rax)
.L8:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	corregir, .-corregir
	.section	.rodata
.LC0:
	.string	"Result: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movabsq	$2336277681913489440, %rax
	movabsq	$2318263578432118881, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movabsq	$7002007203786072181, %rax
	movq	%rax, -16(%rbp)
	movw	$27680, -8(%rbp)
	movb	$0, -6(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	corregir
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
