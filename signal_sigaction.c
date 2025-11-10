/**
 * File: signal_sigaction.c
 * Modified by: Leo Mayorga
 * Course: CPE 2600 112
 * 
 * Brief summary of program:
    - uses sigaction with SA_SIGINFO to handle SIGUSR1
    - prints the sender PID
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handle_usr1(int signo, siginfo_t *info, void *ucontext) 
{
    (void)signo; 
    (void)ucontext;
    printf("signal_sigaction: got SIGUSR1 from pid=%d\n", (int)info->si_pid);
}

int main() 
{
    printf("signal_sigaction PID: %d\n", (int)getpid());

    struct sigaction sa = {0};
    sa.sa_sigaction = handle_usr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        perror("sigaction");
        return 1;
    }
    while (1)
    {
        pause();
    }
    return 0;
}


