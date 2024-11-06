/**
 * signal.c
 *
 * Demonstrates signal handling. During normal operation this program counts up
 * each second, starting from 1. Upon receiving SIGINT, the final count will be
 * printed and the program will exit. Many programs use this type of signal
 * handling to clean up and gracefully exit when the user presses Ctrl+C.
 *
 * Compile: gcc -g -Wall signal.c -o signal
 * Run: ./signal
 */

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned long count = 0;

void sigint_handler(int signo) {
    printf("\n");
    printf("Final count is: %ld\n", count);
    printf("Goodbye!\n");
    exit(0);
}

int main(void) {
    /* Set up our signal handler. SIGINT can be sent via Ctrl+C */
    signal(SIGINT, sigint_handler);

    int pid1 = fork();
   	int pid2 = fork();

	// child process 
    if (pid2 == 0) {
    	while (true) {
	        count++;
	        printf("Grandchild: %ld\n", count);
	        sleep(1);
	    }	
    } else if (pid1 == 0) {
    	printf("PIDs: %d\n", pid2);
    	while (true) {
	        count++;
	        printf("Child: %ld\n", count);
	        sleep(1);
	    }	    	
    }
    else {
    	printf("PIDs: %d; %d\n", pid1, pid2);
		while (true) {
	        count++;
	        printf("Parent: %ld\n", count);
	        sleep(1);
	    } 	
    }
    return 0;

}
