/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message but does not quit
 */

/**
 * Modified by: Leo Mayorga
 * Course: CPE 2600 112
 * 
 * Brief summary of modifications:
    - updated the handles signatre to void handle_signal(int)
    - removed the exit() so that the program continues after SIGINT
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and continues
 */
void handle_signal(int signo) {
    (void)signo;
    printf("Received a signal and continuing\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}