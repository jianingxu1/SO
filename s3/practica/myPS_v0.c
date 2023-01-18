#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void Usage() {
    char buff[120];
    sprintf(buff, "Usage: myPS_v0 arg1. Este programa escribe el pid del proceso padre, el del hijo y el argumento.\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg,int exit_status) {
    perror(msg);
    exit(exit_status);
}

int main (int argc, char *argv[]) {
    if (argc == 2) {
        char buffer[80];
        int pid;
        if ((pid = fork())<0) error_y_exit("Error en fork", 1);
        else if (pid == 0) {
            sprintf(buffer, "HIJO: %d y argumento: %s\n", getpid(), argv[1]);
            write(1, buffer, strlen(buffer));
        }
        else {
            sprintf(buffer, "PADRE: %d\n", getpid());
            write(1, buffer, strlen(buffer));
        }
        while(1);
    }
    else Usage();
}