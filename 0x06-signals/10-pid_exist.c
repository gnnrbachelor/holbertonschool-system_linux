#include <signal.h>

/**
 * pid_exist - checks if pid exists
 * @pid: pid
 * Return:  0 or 1
 */
int pid_exist(pid_t pid)
{
	return (!kill(pid, 0));
}
