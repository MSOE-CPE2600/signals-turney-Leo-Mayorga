/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
    - SIGSEGV handler that prints a message and returns
 */

#include <signal.h>
#include <stdio.h>

void handle_segv(int signo)
{
    (void)signo;
    printf("SIGSEGV was received (NULL)");
}

int main (int argc, char* argv[]) {
    signal(SIGSEGV, handle_segv);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}