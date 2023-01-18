#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int seconds_executed = 0;
char buffer[256];

void treatment(int s) {
    if (s == SIGUSR1) {
        seconds_executed = 0;
    }
    else if (s == SIGALRM) {
        ++seconds_executed;
        alarm(1);
    }
    else if (s == SIGUSR2) {
        sprintf(buffer, "Time executed: %d seconds\n", seconds_executed);
        write(1, buffer, strlen(buffer));
    }
}

int main(int argc, char *argv[]) {
    struct sigaction sa;
    sa.sa_handler = &treatment;
    sa.sa_flags = SA_RESETHAND;
    sigfillset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    alarm(1);
    while(1);
}