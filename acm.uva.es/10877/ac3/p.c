void go()
{
__asm__ __volatile__(
"	jmp	main2\n"
"	.align 32\n"
"_sym:\n"
".long	0\n"
".long	1\n"
".long	2\n"
".long	3\n"
".long	4\n"
".long	5\n"
".space 8\n"
".long	0\n"
".long	2\n"
".long	5\n"
".long	3\n"
".long	1\n"
".long	4\n"
".space 8\n"
".long	0\n"
".long	4\n"
".long	1\n"
".long	3\n"
".long	5\n"
".long	2\n"
".space 8\n"
".long	0\n"
".long	5\n"
".long	4\n"
".long	3\n"
".long	2\n"
".long	1\n"
".space 8\n"
".long	1\n"
".long	0\n"
".long	4\n"
".long	5\n"
".long	2\n"
".long	3\n"
".space 8\n"
".long	1\n"
".long	2\n"
".long	0\n"
".long	5\n"
".long	3\n"
".long	4\n"
".space 8\n"
".long	1\n"
".long	3\n"
".long	2\n"
".long	5\n"
".long	4\n"
".long	0\n"
".space 8\n"
".long	1\n"
".long	4\n"
".long	3\n"
".long	5\n"
".long	0\n"
".long	2\n"
".space 8\n"
".long	2\n"
".long	0\n"
".long	1\n"
".long	4\n"
".long	5\n"
".long	3\n"
".space 8\n"
".long	2\n"
".long	1\n"
".long	3\n"
".long	4\n"
".long	0\n"
".long	5\n"
".space 8\n"
".long	2\n"
".long	3\n"
".long	5\n"
".long	4\n"
".long	1\n"
".long	0\n"
".space 8\n"
".long	2\n"
".long	5\n"
".long	0\n"
".long	4\n"
".long	3\n"
".long	1\n"
".space 8\n"
".long	3\n"
".long	1\n"
".long	4\n"
".long	0\n"
".long	2\n"
".long	5\n"
".space 8\n"
".long	3\n"
".long	2\n"
".long	1\n"
".long	0\n"
".long	5\n"
".long	4\n"
".space 8\n"
".long	3\n"
".long	4\n"
".long	5\n"
".long	0\n"
".long	1\n"
".long	2\n"
".space 8\n"
".long	3\n"
".long	5\n"
".long	2\n"
".long	0\n"
".long	4\n"
".long	1\n"
".space 8\n"
".long	4\n"
".long	0\n"
".long	5\n"
".long	2\n"
".long	1\n"
".long	3\n"
".space 8\n"
".long	4\n"
".long	1\n"
".long	0\n"
".long	2\n"
".long	3\n"
".long	5\n"
".space 8\n"
".long	4\n"
".long	3\n"
".long	1\n"
".long	2\n"
".long	5\n"
".long	0\n"
".space 8\n"
".long	4\n"
".long	5\n"
".long	3\n"
".long	2\n"
".long	0\n"
".long	1\n"
".space 8\n"
".long	5\n"
".long	0\n"
".long	2\n"
".long	1\n"
".long	4\n"
".long	3\n"
".space 8\n"
".long	5\n"
".long	2\n"
".long	3\n"
".long	1\n"
".long	0\n"
".long	4\n"
".space 8\n"
".long	5\n"
".long	3\n"
".long	4\n"
".long	1\n"
".long	2\n"
".long	0\n"
".space 8\n"
".long	5\n"
".long	4\n"
".long	0\n"
".long	1\n"
".long	3\n"
".long	2\n"
".space 8\n"
".p2align 4,,15\n"
"_sort:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$8, %esp\n"
"	movl	8(%ebp), %esi\n"
"L2:\n"
"	cmpl	$32, 12(%ebp)\n"
"	jle	L31\n"
"	movl	12(%ebp), %eax\n"
"	decl	%eax\n"
"	sarl	%eax\n"
"	movl	(%esi,%eax,4), %ecx\n"
"	movl	$-1, %edi\n"
"	movl	12(%ebp), %eax\n"
"	.p2align 4,,15\n"
"L30:\n"
"	incl	%edi\n"
"	movl	(%esi,%edi,4), %ebx\n"
"	cmpl	%ecx, %ebx\n"
"	jl	L30\n"
"	.p2align 4,,15\n"
"L21:\n"
"	decl	%eax\n"
"	movl	(%esi,%eax,4), %edx\n"
"	cmpl	%ecx, %edx\n"
"	jg	L21\n"
"	cmpl	%eax, %edi\n"
"	jge	L16\n"
"	movl	%edx, (%esi,%edi,4)\n"
"	movl	%ebx, (%esi,%eax,4)\n"
"	jmp	L30\n"
"L16:\n"
"	movl	12(%ebp), %eax\n"
"	subl	%edi, %eax\n"
"	cmpl	$1, %eax\n"
"	jg	L32\n"
"L25:\n"
"	movl	%edi, 12(%ebp)\n"
"	jmp	L2\n"
"L32:\n"
"	movl	%eax, 4(%esp)\n"
"	leal	(%esi,%edi,4), %eax\n"
"	movl	%eax, (%esp)\n"
"	call	_sort\n"
"	jmp	L25\n"
"L31:\n"
"	movl	$1, %edi\n"
"	cmpl	12(%ebp), %edi\n"
"	jge	L1\n"
"L14:\n"
"	movl	(%esi,%edi,4), %ecx\n"
"	movl	%edi, %eax\n"
"	decl	%eax\n"
"	js	L9\n"
"	movl	(%esi,%eax,4), %edx\n"
"	cmpl	%ecx, %edx\n"
"	jle	L9\n"
"L13:\n"
"	movl	%edx, 4(%esi,%eax,4)\n"
"	decl	%eax\n"
"	js	L9\n"
"	movl	(%esi,%eax,4), %edx\n"
"	cmpl	%ecx, %edx\n"
"	jg	L13\n"
"L9:\n"
"	movl	%ecx, 4(%esi,%eax,4)\n"
"	incl	%edi\n"
"	cmpl	12(%ebp), %edi\n"
"	jl	L14\n"
"L1:\n"
"	addl	$8, %esp\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%edi\n"
"	popl	%ebp\n"
"	ret\n"
".comm _a.0,4096\n"
".comm _b.1,32\n"
"LC0:\n"
"	.ascii \"%d\\12\\0\"\n"
"	.text\n"
"	.p2align 4,,15\n"
"main2:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$28, %esp\n"
"	movl	$48, -16(%ebp)\n"
"L38:\n"
"	movl	-16(%ebp), %eax\n"
"	movl	$1, %ecx\n"
"	movl	%ecx, _isdig(,%eax,4)\n"
"	incl	%eax\n"
"	movl	%eax, -16(%ebp)\n"
"	cmpl	$57, %eax\n"
"	jle	L38\n"
"	movl	$1048576, %edx\n"
"	movl	%edx, 8(%esp)\n"
"	movl	$_inbuf, %eax\n"
"	movl	%eax, _inp\n"
"	movl	$_inbuf, %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	read\n"
"	movb	$0, _inbuf(%eax)\n"
"L39:\n"
"	movl	_inp, %esi\n"
"	movsbl	(%esi),%eax\n"
"	movl	_isdig(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L91\n"
"	leal	1(%esi), %edx\n"
"L45:\n"
"	movl	%edx, %esi\n"
"	movl	%edx, _inp\n"
"	leal	1(%edx), %edx\n"
"	movsbl	-1(%edx),%eax\n"
"	movl	_isdig(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L45\n"
"L91:\n"
"	movl	%esi, %eax\n"
"	movsbl	(%esi),%edx\n"
"	subl	$48, %edx\n"
"	movl	%edx, -24(%ebp)\n"
"	incl	%esi\n"
"	movl	%esi, _inp\n"
"	movsbl	1(%eax),%eax\n"
"	movl	_isdig(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L93\n"
"L50:\n"
"	movl	-24(%ebp), %eax\n"
"	leal	(%eax,%eax,4), %edx\n"
"	movl	%esi, %ecx\n"
"	movsbl	(%esi),%eax\n"
"	leal	-48(%eax,%edx,2), %eax\n"
"	movl	%eax, -24(%ebp)\n"
"	incl	%esi\n"
"	movl	%esi, _inp\n"
"	movsbl	1(%ecx),%eax\n"
"	movl	_isdig(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L50\n"
"L93:\n"
"	movl	-24(%ebp), %edi\n"
"	testl	%edi, %edi\n"
"	je	L40\n"
"	movl	$0, -16(%ebp)\n"
"	movl	-24(%ebp), %edx\n"
"	cmpl	%edx, -16(%ebp)\n"
"	jge	L95\n"
"L81:\n"
"	xorl	%edi, %edi\n"
"L69:\n"
"	movsbl	(%esi),%eax\n"
"	movl	_isdig(,%eax,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L99\n"
"	leal	1(%esi), %edx\n"
"	.p2align 4,,15\n"
"L63:\n"
"	movl	%edx, %esi\n"
"	movl	%edx, _inp\n"
"	leal	1(%edx), %edx\n"
"	movsbl	-1(%edx),%eax\n"
"	movl	_isdig(,%eax,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	je	L63\n"
"L99:\n"
"	movl	%esi, %eax\n"
"	movsbl	(%esi),%edx\n"
"	leal	-48(%edx), %ecx\n"
"	incl	%esi\n"
"	movl	%esi, _inp\n"
"	movsbl	1(%eax),%eax\n"
"	movl	_isdig(,%eax,4), %edx\n"
"	testl	%edx, %edx\n"
"	je	L101\n"
"	leal	1(%esi), %ebx\n"
"	.p2align 4,,15\n"
"L68:\n"
"	leal	(%ecx,%ecx,4), %edx\n"
"	movsbl	-1(%ebx),%eax\n"
"	leal	-48(%eax,%edx,2), %ecx\n"
"	movl	%ebx, %eax\n"
"	movl	%ebx, %esi\n"
"	incl	%ebx\n"
"	movl	%eax, _inp\n"
"	movsbl	-1(%ebx),%eax\n"
"	movl	_isdig(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L68\n"
"L101:\n"
"	leal	-1(%ecx), %eax\n"
"	movl	%eax, _b.1(,%edi,4)\n"
"	incl	%edi\n"
"	cmpl	$5, %edi\n"
"	jle	L69\n"
"	xorl	%edi, %edi\n"
"	movl	$1073741823, -20(%ebp)\n"
"	.p2align 4,,15\n"
"L80:\n"
"	xorl	%ecx, %ecx\n"
"	xorl	%eax, %eax\n"
"	leal	0(,%edi,8), %ebx\n"
"	.p2align 4,,15\n"
"L78:\n"
"	leal	(%eax,%eax,2), %edx\n"
"	leal	(%ecx,%ebx), %eax\n"
"	movl	_sym(,%eax,4), %eax\n"
"	movl	_b.1(,%eax,4), %eax\n"
"	leal	(%eax,%edx,2), %eax\n"
"	incl	%ecx\n"
"	cmpl	$5, %ecx\n"
"	jle	L78\n"
"	cmpl	-20(%ebp), %eax\n"
"	jge	L72\n"
"	movl	%eax, -20(%ebp)\n"
"L72:\n"
"	incl	%edi\n"
"	cmpl	$23, %edi\n"
"	jle	L80\n"
"	movl	-20(%ebp), %edx\n"
"	movl	-16(%ebp), %eax\n"
"	movl	%edx, _a.0(,%eax,4)\n"
"	incl	%eax\n"
"	movl	%eax, -16(%ebp)\n"
"	movl	-24(%ebp), %edx\n"
"	cmpl	%edx, %eax\n"
"	jl	L81\n"
"L95:\n"
"	movl	-24(%ebp), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$_a.0, (%esp)\n"
"	call	_sort\n"
"	movl	$1, -20(%ebp)\n"
"	movl	$1, -16(%ebp)\n"
"	movl	-24(%ebp), %edx\n"
"	cmpl	%edx, -20(%ebp)\n"
"	jge	L107\n"
"L87:\n"
"	movl	-16(%ebp), %edx\n"
"	movl	_a.0(,%edx,4), %eax\n"
"	cmpl	%eax, _a.0-4(,%edx,4)\n"
"	je	L84\n"
"	incl	-20(%ebp)\n"
"L84:\n"
"	incl	-16(%ebp)\n"
"	movl	-24(%ebp), %eax\n"
"	cmpl	%eax, -16(%ebp)\n"
"	jl	L87\n"
"L107:\n"
"	movl	-20(%ebp), %edx\n"
"	movl	%edx, 4(%esp)\n"
"	movl	$LC0, (%esp)\n"
"	call	printf\n"
"	jmp	L39\n"
"L40:\n"
"	movl	$0, (%esp)\n"
"	call	exit\n"
"	.comm	_isdig, 1024	 # 1024\n"
"	.comm	_inbuf, 1048576	 # 1048576\n"
"	.comm	_inp, 16	 # 4\n"
);
}

int main()
{
	go();
	return 0;
}
