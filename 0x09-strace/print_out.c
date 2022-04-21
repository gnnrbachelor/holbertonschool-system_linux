#include "syscalls.h"

void print_out(const syscall_t *sys_call, struct user_regs_struct *user_regs, pid_t pid)
{
	size_t index, p[6];

	(void)pid;

	p[0] = user_regs->rdi;
	p[1] = user_regs->rsi;
	p[2] = user_regs->rdx;
	p[3] = user_regs->r10;
	p[4] = user_regs->r8;
	p[5] = user_regs->r9;

	putchar('(');
	for (index = 0; sys_call->params[0] != VOID && index < sys_call->nb_params; index++)
		if (sys_call->params[index] == VARARGS)
			printf("%s...", index ? "," : "");
		else
			printf("%s%#lx", index ? ", " : "", p[index]);
}
