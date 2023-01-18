#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int is_child_alive;

void treatment(int s) {
    if (s == SIGCHLD) {
        while( (is_child_alive = waitpid(-1, NULL, WNOHANG)) > 0 ) {
            // char buff[256];
            // sprintf(buff, "%d ha terminado.\n", is_child_alive);
            // write(1, buff, strlen(buff));

        }
    }
}

int main(int argc, char *argv[]) {
    struct sigaction sa;
    sa.sa_handler = &treatment;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGCHLD, &sa, NULL);

    // create child processes
    // for (int i = 0; i < 10; ++i) {
    //     int ret = fork();
    //     if (ret == 0) exit(1);
    // }

    while(is_child_alive >= 0);
}