	.file	"formats.c"
# GNU C17 (Debian 12.2.0-14) version 12.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 12.2.0, GMP version 6.2.1, MPFR version 4.1.1-p1, MPC version 1.3.1, isl version isl-0.25-GMP

# warning: GMP header version 6.2.1 differs from library version 6.3.0.
# warning: MPFR header version 4.1.1-p1 differs from library version 4.2.0.
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables
	.text
	.section	.rodata
.LC0:
	.string	"Enter a date (YYYYMMDD): "
.LC1:
	.string	"%d/%d/%d"
.LC2:
	.string	"You entered: %d%d%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# formats.c:6:   printf("Enter a date (YYYYMMDD): ");
	leaq	.LC0(%rip), %rax	#, tmp87
	movq	%rax, %rdi	# tmp87,
	movl	$0, %eax	#,
	call	printf@PLT	#
# formats.c:7:   scanf("%d/%d/%d", &day, &month, &year);
	leaq	-12(%rbp), %rcx	#, tmp88
	leaq	-8(%rbp), %rdx	#, tmp89
	leaq	-4(%rbp), %rax	#, tmp90
	movq	%rax, %rsi	# tmp90,
	leaq	.LC1(%rip), %rax	#, tmp91
	movq	%rax, %rdi	# tmp91,
	movl	$0, %eax	#,
	call	__isoc99_scanf@PLT	#
# formats.c:9:   printf("You entered: %d%d%d\n", day, month, year);
	movl	-12(%rbp), %ecx	# year, year.0_1
	movl	-8(%rbp), %edx	# month, month.1_2
	movl	-4(%rbp), %eax	# day, day.2_3
	movl	%eax, %esi	# day.2_3,
	leaq	.LC2(%rip), %rax	#, tmp92
	movq	%rax, %rdi	# tmp92,
	movl	$0, %eax	#,
	call	printf@PLT	#
# formats.c:11:   return 0;
	movl	$0, %eax	#, _8
# formats.c:12: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
