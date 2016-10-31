	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.section	__TEXT,__literal8,8byte_literals
	.align	3
LCPI0_0:
	.quad	4611686018427387904     ## double 2
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_findMedianSortedArrays
	.align	4, 0x90
_findMedianSortedArrays:                ## @findMedianSortedArrays
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	$2, %eax
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	movq	%rdx, -32(%rbp)
	movl	%ecx, -36(%rbp)
	movl	-20(%rbp), %ecx
	addl	-36(%rbp), %ecx
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-68(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	subl	$1, %eax
	movl	%eax, -40(%rbp)
	movl	-20(%rbp), %eax
	addl	-36(%rbp), %eax
	cltd
	idivl	%ecx
	cmpl	$0, %edx
	jne	LBB0_2
## BB#1:
	movl	-40(%rbp), %eax
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)         ## 4-byte Spill
LBB0_3:
	movl	-72(%rbp), %eax         ## 4-byte Reload
	movl	%eax, -44(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -48(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -52(%rbp)
	movl	$1, -64(%rbp)
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -48(%rbp)
	je	LBB0_8
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=1
	cmpl	$0, -52(%rbp)
	je	LBB0_8
## BB#6:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-48(%rbp), %eax
	addl	-52(%rbp), %eax
	cmpl	-40(%rbp), %eax
	je	LBB0_8
## BB#7:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-48(%rbp), %eax
	addl	-52(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jne	LBB0_9
LBB0_8:
	jmp	LBB0_13
LBB0_9:                                 ##   in Loop: Header=BB0_4 Depth=1
	movl	-20(%rbp), %eax
	movl	-64(%rbp), %ecx
                                        ## kill: CL<def> ECX<kill>
	shll	%cl, %eax
	movl	%eax, -56(%rbp)
	movl	-36(%rbp), %eax
	movl	-64(%rbp), %ecx
                                        ## kill: CL<def> ECX<kill>
	shll	%cl, %eax
	movl	%eax, -60(%rbp)
	movl	-48(%rbp), %eax
	subl	-56(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rsi
	movl	(%rsi,%rdx,4), %eax
	movl	-52(%rbp), %edi
	subl	-60(%rbp), %edi
	subl	$1, %edi
	movslq	%edi, %rdx
	movq	-32(%rbp), %rsi
	cmpl	(%rsi,%rdx,4), %eax
	jl	LBB0_11
## BB#10:                               ##   in Loop: Header=BB0_4 Depth=1
	movl	-56(%rbp), %eax
	movl	-48(%rbp), %ecx
	subl	%eax, %ecx
	movl	%ecx, -48(%rbp)
	jmp	LBB0_12
LBB0_11:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-60(%rbp), %eax
	movl	-52(%rbp), %ecx
	subl	%eax, %ecx
	movl	%ecx, -52(%rbp)
LBB0_12:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-64(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -64(%rbp)
	jmp	LBB0_4
LBB0_13:
	cmpl	$0, -48(%rbp)
	jne	LBB0_15
## BB#14:
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movslq	-44(%rbp), %rax
	movq	-32(%rbp), %rcx
	cvtsi2sdl	(%rcx,%rax,4), %xmm1
	movslq	-44(%rbp), %rax
	movq	-32(%rbp), %rcx
	cvtsi2sdl	(%rcx,%rax,4), %xmm2
	addsd	%xmm2, %xmm1
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -8(%rbp)
	jmp	LBB0_21
LBB0_15:
	cmpl	$0, -52(%rbp)
	jne	LBB0_17
## BB#16:
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movslq	-40(%rbp), %rax
	movq	-16(%rbp), %rcx
	cvtsi2sdl	(%rcx,%rax,4), %xmm1
	movslq	-40(%rbp), %rax
	movq	-16(%rbp), %rcx
	cvtsi2sdl	(%rcx,%rax,4), %xmm2
	addsd	%xmm2, %xmm1
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -8(%rbp)
	jmp	LBB0_21
LBB0_17:
	movl	-40(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jne	LBB0_19
## BB#18:
	jmp	LBB0_19
LBB0_19:
	jmp	LBB0_20
LBB0_20:
	jmp	LBB0_21
LBB0_21:
	movsd	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$2, %esi
	movl	$1, %ecx
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -20(%rbp)
	movq	L_main.a(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	L_main.b(%rip), %r8d
	movl	%r8d, -24(%rbp)
	callq	_findMedianSortedArrays
	leaq	L_.str(%rip), %rdi
	movsd	%xmm0, -32(%rbp)
	movsd	-32(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movb	$1, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	cmpq	-8(%rbp), %rdx
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	jne	LBB1_2
## BB#1:                                ## %SP_return
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
LBB1_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__literal8,8byte_literals
	.align	2                       ## @main.a
L_main.a:
	.long	1                       ## 0x1
	.long	3                       ## 0x3

	.section	__TEXT,__literal4,4byte_literals
	.align	2                       ## @main.b
L_main.b:
	.long	2                       ## 0x2

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"result: %f\n"


.subsections_via_symbols
