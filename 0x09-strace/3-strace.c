#include "syscalls.h"

/**
 * main - executes and traces a given command
 * @argc:  arg count
 * @argv: args
 * @envp: Environment
 * Return: 1 or 0
 */

int main(int argc, char *argv[], char *envp[])
{
	int index, status;
	struct user_regs_struct user_regs;
	pid_t pid;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <full_path> [path_args]\n", argv[0]);
		return (1);
	}

	setbuf(stdout, NULL);
	pid = fork();

	if (pid == 0)
	{
		printf("execve");
		ptrace(PTRACE_TRACEME, pid, NULL, NULL);
		execve(argv[1], argv + 1, envp);
	}
	else
	{
		for (status = 1, index = 0; !WIFEXITED(status); index ^= 1)
		{
			ptrace(PT_SYSCALL, pid, NULL, NULL);
			wait(&status);
			ptrace(PT_GETREGS, pid, NULL, &user_regs);
			if (index)
			{
				printf("\n%s", syscalls_64_g[user_regs.orig_rax].name);
				print_out(&syscalls_64_g[user_regs.orig_rax], &user_regs, pid);
			}
			else if (WIFEXITED(status))
				printf(" = ?\n");
			else
				printf(" = %#lx", (size_t)user_regs.rax);
		}
	}
	return (0);
}
