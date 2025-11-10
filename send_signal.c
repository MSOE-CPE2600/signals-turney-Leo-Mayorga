/**
 * File: send_signal.c
 * Modified by: Leo Mayorga
 * 
 * Brief summary of program:
    - generates a random int to send with SIGUSR1 through sigqueue to a receiver PID
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <receiver_pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);

    // seed rng using time
    srand((unsigned)time(NULL));                    // seed
    int val = rand();                               // random int
    printf("send_signal: generated value=%d\n", val);

    union sigval sv;
    sv.sival_int = val;

    if (sigqueue(pid, SIGUSR1, sv) == -1) 
    {
        perror("sigqueue");
        return 1;
    }
    printf("send_signal: sent SIGUSR1 to pid=%d with value=%d\n",
           (int)pid, val);
    return 0;
}