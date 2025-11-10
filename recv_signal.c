/**
 * File: recv_signal.c
 * Modified by: Leo Mayorga
 * 
 * Brief summary of program:
    - registers a SIGUSR1 handle using sigaction with SA_SIGINTO
    - prints the sender's PID
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void handle_usr1(int signo, siginfo_t *info, void *ucontext)
{
    (void)signo;
    (void)ucontext;
    printf("recv_signal: got SIGUSR1 from pid=%d with value=%d\n", 
        (int)info->si_pid, info->si_value.sival_int);
}

int main()
{
    // show PID 
    printf("recv_signal PID: %d\n", getpid());

    struct sigaction sa = {0};
    sa.sa_sigaction = handle_usr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    // wait forever for signal
    while(1)
    {
        pause(); // sleep until any signal arrives
    }
    return 0;
}
