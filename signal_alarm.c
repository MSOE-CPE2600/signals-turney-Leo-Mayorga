/**
 * File: signal_alarm.c
 * Modified by: Leo Mayorga
 * 
 * Brief summary of program:
    - reguster the SIGALRM handler
    - uses alarm(5) to scedule the signal
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_alarm(int signo)
{
    (void)signo;
    printf("SIGALRM received after 5 seconds\n");
}

int main(void)
{
    // schedule the alarm
    signal(SIGALRM, handle_alarm);
    alarm(5);

    while(1)
    {
        pause;  // sleep until the signal arrives
    }
    return 0;
}