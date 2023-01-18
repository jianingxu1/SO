#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char buff[256];
int pids[10];
int is_child_alive;

void treatment(int s) {
    if (s == SIGCHLD) {
        int exit_code, statcode, signcode;
        while( (is_child_alive = waitpid(-1, &exit_code, WNOHANG)) > 0 ) {
            if (WIFEXITED(exit_code)) {
                statcode = WEXITSTATUS(exit_code);
                sprintf(buff, "Child with PID %d exited with exit code %d\n", is_child_alive, statcode);
            }
            else if (WIFSIGNALED(exit_code)) {
                signcode = WTERMSIG(exit_code);
                sprintf(buff, "Child with PID %d was terminated by the signal %d\n", is_child_alive, signcode);
            }
            write(1, buff, strlen(buff));

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
    int n = 10;
    int pids[n];
    for (int i = 0; i < n; ++i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            exit(1);
        }
    }
    for (int i = 0; i < n; ++i) {
        kill(pids[i], SIGUSR1);
    }
    while(is_child_alive >= 0);
}