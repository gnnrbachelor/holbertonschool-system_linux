#ifndef SIGNALS_H
#define SIGNALS_H

#define _GNU_SOURCE


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>


int handle_signal(void);
void printer(int sig);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
void sig_hand(int sig_num, siginfo_t *info, void *context);
int pid_exist(pid_t pid);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
#endif
