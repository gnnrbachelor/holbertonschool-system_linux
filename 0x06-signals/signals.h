#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int handle_signal(void);
void printer(int sig);

#endif
