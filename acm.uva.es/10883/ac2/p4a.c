int main()
{
__asm__ __volatile__(
"	jmp	_main2\n"
"	.align 8\n"
"LC2:\n"
"	.long	-1698910392\n"
"	.long	1048238066\n"
"_solve:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$60, %esp\n"
"	movl	_n, %eax\n"
"	leal	-1(%eax), %esi\n"
"	movl	%esi, %edi\n"
"	sarl	%edi\n"
"	testl	$1, %esi\n"
"	je	L2\n"
"	pushl	%eax\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fstpl	(%esp)\n"
"	call	lgamma\n"
"	fstpl	-32(%ebp)\n"
"	leal	1(%edi), %ebx\n"
"	pushl	%ebx\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fstpl	(%esp)\n"
"	call	lgamma\n"
"	fsubrl	-32(%ebp)\n"
"	fstpl	-32(%ebp)\n"
"	movl	%esi, %edx\n"
"	subl	%edi, %edx\n"
"	incl	%edx\n"
"	pushl	%edx\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fstpl	(%esp)\n"
"	call	lgamma\n"
"	fsubrl	-32(%ebp)\n"
"	fstpl	-32(%ebp)\n"
"	pushl	%esi\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fmull	_l2\n"
"	fsubrl	-32(%ebp)\n"
"	fstpl	(%esp)\n"
"	call	exp\n"
"	fldz\n"
"	movl	%edi, %edx\n"
"	movl	%ebx, %ecx\n"
"	testl	%edi, %edi\n"
"	js	L25\n"
"	fld1\n"
"	fldl	LC2\n"
"	.p2align 4,,15\n"
"L9:\n"
"	fldl	_a(,%ecx,8)\n"
"	faddl	_a(,%edx,8)\n"
"	fmul	%st(4), %st\n"
"	faddp	%st, %st(3)\n"
"	pushl	%edx\n"
"	fildl	(%esp)\n"
"	movl	%esi, %ebx\n"
"	subl	%edx, %ebx\n"
"	movl	%ebx, (%esp)\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fadd	%st(3), %st\n"
"	fdivrp	%st, %st(1)\n"
"	fmulp	%st, %st(4)\n"
"	fucom	%st(3)\n"
"	fnstsw	%ax\n"
"	sahf\n"
"	ja	L23\n"
"	incl	%ecx\n"
"	decl	%edx\n"
"	jns	L9\n"
"L23:\n"
"	fstp	%st(0)\n"
"L24:\n"
"	fstp	%st(0)\n"
"L25:\n"
"	fstp	%st(1)\n"
"	addl	$60, %esp\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%edi\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,7\n"
"L2:\n"
"	pushl	%eax\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fstpl	(%esp)\n"
"	call	lgamma\n"
"	leal	1(%edi), %ebx\n"
"	pushl	%ebx\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fstpl	(%esp)\n"
"	fstpl	-56(%ebp)\n"
"	call	lgamma\n"
"	fadd	%st(0), %st\n"
"	fldl	-56(%ebp)\n"
"	fsubp	%st, %st(1)\n"
"	pushl	%esi\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fmull	_l2\n"
"	fsubrp	%st, %st(1)\n"
"	fstpl	(%esp)\n"
"	call	exp\n"
"	fld	%st(0)\n"
"	fmull	_a(,%edi,8)\n"
"	pushl	%edi\n"
"	fildl	(%esp)\n"
"	movl	%esi, %edx\n"
"	subl	%edi, %edx\n"
"	movl	%edx, (%esp)\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fld1\n"
"	fadd	%st, %st(1)\n"
"	fxch	%st(2)\n"
"	fdivp	%st, %st(1)\n"
"	fmulp	%st, %st(3)\n"
"	movl	%ebx, %ecx\n"
"	movl	%edi, %edx\n"
"	decl	%edx\n"
"	js	L24\n"
"	fldl	LC2\n"
"	.p2align 4,,15\n"
"L17:\n"
"	fldl	_a(,%ecx,8)\n"
"	faddl	_a(,%edx,8)\n"
"	fmul	%st(4), %st\n"
"	faddp	%st, %st(3)\n"
"	pushl	%edx\n"
"	fildl	(%esp)\n"
"	movl	%esi, %edi\n"
"	subl	%edx, %edi\n"
"	movl	%edi, (%esp)\n"
"	fildl	(%esp)\n"
"	addl	$4, %esp\n"
"	fadd	%st(3), %st\n"
"	fdivrp	%st, %st(1)\n"
"	fmulp	%st, %st(4)\n"
"	fucom	%st(3)\n"
"	fnstsw	%ax\n"
"	sahf\n"
"	ja	L23\n"
"	incl	%ecx\n"
"	decl	%edx\n"
"	jns	L17\n"
"	jmp	L23\n"
"LC7:\n"
"	.ascii \"%d\\0\"\n"
"LC8:\n"
"	.ascii \"%lf\\0\"\n"
"LC9:\n"
"	.ascii \"Case #%d: %.3f\\12\\0\"\n"
"_main2:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$28, %esp\n"
"	movl	$0, (%esp)\n"
"	movl	$1073741824, %eax\n"
"	movl	%eax, 4(%esp)\n"
"	call	log\n"
"	fstpl	_l2\n"
"	leal	-16(%ebp), %edx\n"
"	movl	%edx, 4(%esp)\n"
"	movl	$LC7, (%esp)\n"
"	call	scanf\n"
"	movl	$1, %edi\n"
"	.p2align 4,,15\n"
"L35:\n"
"	cmpl	-16(%ebp), %edi\n"
"	jg	L36\n"
"	movl	$_n, %edx\n"
"	movl	%edx, 4(%esp)\n"
"	movl	$LC7, (%esp)\n"
"	call	scanf\n"
"	decl	%eax\n"
"	jne	L36\n"
"	xorl	%esi, %esi\n"
"	cmpl	_n, %esi\n"
"	jge	L47\n"
"	movl	$_a, %ebx\n"
"	.p2align 4,,15\n"
"L44:\n"
"	movl	%ebx, 4(%esp)\n"
"	movl	$LC8, (%esp)\n"
"	call	scanf\n"
"	incl	%esi\n"
"	addl	$8, %ebx\n"
"	cmpl	_n, %esi\n"
"	jl	L44\n"
"L47:\n"
"	call	_solve\n"
"	fstpl	8(%esp)\n"
"	movl	%edi, 4(%esp)\n"
"	movl	$LC9, (%esp)\n"
"	call	printf\n"
"	incl	%edi\n"
"	jmp	L35\n"
"L36:\n"
"	movl	$0, (%esp)\n"
"	call	exit\n"
"	.comm	_l2, 16	 # 8\n"
"	.comm	_n, 16	 # 4\n"
"	.comm	_a, 524288	 # 524288\n"
);
}
