	.file	"palindromo.c"
	.text
	.globl	leer
	.type	leer, @function
leer:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	cmpl	$0, -24(%rbp)
	jne	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rcx
	movl	-20(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jg	.L4
	movl	$1, %eax
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	subl	%eax, -24(%rbp)
	movl	-4(%rbp), %eax
	cltq
	addq	%rax, -32(%rbp)
	cmpl	$0, -24(%rbp)
	jg	.L2
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	leer, .-leer
	.globl	palindro
	.type	palindro, @function
palindro:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L6
.L9:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-28(%rbp), %eax
	subl	$1, %eax
	subl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L7
	movl	-4(%rbp), %eax
	jmp	.L8
.L7:
	addl	$1, -4(%rbp)
.L6:
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -4(%rbp)
	jl	.L9
	movl	-28(%rbp), %eax
.L8:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	palindro, .-palindro
	.globl	palindro_par
	.type	palindro_par, @function
palindro_par:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%rdi, -136(%rbp)
	movl	%esi, -140(%rbp)
	movl	%edx, -144(%rbp)
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	-140(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cltd
	idivl	-144(%rbp)
	movl	%eax, -64(%rbp)
	movl	-144(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -80(%rbp)
	movl	-144(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -88(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	movl	$0, -60(%rbp)
	jmp	.L11
.L16:
	leaq	-116(%rbp), %rax
	movq	%rax, %rdi
	call	pipe@PLT
	call	fork@PLT
	movl	%eax, -100(%rbp)
	cmpl	$0, -100(%rbp)
	jne	.L12
	movl	-116(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	-64(%rbp), %eax
	imull	-60(%rbp), %eax
	movl	%eax, -104(%rbp)
	movl	-60(%rbp), %eax
	leal	1(%rax), %edx
	movl	-64(%rbp), %eax
	imull	%edx, %eax
	movl	%eax, -108(%rbp)
	movl	-140(%rbp), %eax
	movl	%eax, -120(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -56(%rbp)
	jmp	.L13
.L15:
	movl	-56(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-136(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-140(%rbp), %eax
	subl	$1, %eax
	subl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-136(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L14
	movl	-56(%rbp), %eax
	movl	%eax, -120(%rbp)
.L14:
	addl	$1, -56(%rbp)
.L13:
	movl	-56(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jle	.L15
	movl	-112(%rbp), %eax
	leaq	-120(%rbp), %rcx
	movl	$4, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	movl	$0, %edi
	call	exit@PLT
.L12:
	movl	-112(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	-116(%rbp), %ecx
	movq	-96(%rbp), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	movq	-80(%rbp), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	movl	-100(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -60(%rbp)
.L11:
	movl	-60(%rbp), %eax
	cmpl	-144(%rbp), %eax
	jl	.L16
	movl	$0, -52(%rbp)
	jmp	.L17
.L19:
	movq	-96(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	leaq	-124(%rbp), %rcx
	movl	$4, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	leer
	movq	-96(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %edi
	call	close@PLT
	movq	-80(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	$0, %edx
	movl	$0, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	waitpid@PLT
	movl	-124(%rbp), %eax
	cmpl	%eax, -140(%rbp)
	je	.L18
	movl	-124(%rbp), %eax
	movl	%eax, -140(%rbp)
.L18:
	addl	$1, -52(%rbp)
.L17:
	movl	-52(%rbp), %eax
	cmpl	-144(%rbp), %eax
	jl	.L19
	movl	-140(%rbp), %eax
	movq	%rbx, %rsp
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	palindro_par, .-palindro_par
	.section	.rodata
.LC0:
	.string	"Est\303\241 bien"
.LC1:
	.string	"Est\303\241 mal"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$4, -20(%rbp)
	movl	$5, -16(%rbp)
	movl	$1, -64(%rbp)
	movl	$2, -60(%rbp)
	movl	$3, -56(%rbp)
	movl	$2, -52(%rbp)
	movl	$1, -48(%rbp)
	leaq	-32(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	palindro
	cmpl	$5, %eax
	je	.L22
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L23
.L22:
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L23:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
