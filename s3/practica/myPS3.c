#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void Usage() {
    char buff[120];
    sprintf(buff, "Usage: myPS3 arg1 [arg2] [...]. Este programa escribe el pid del proceso padre, el del hijo y el argumento.\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg,int exit_status) {
    perror(msg);
    exit(exit_status);
}

int main (int argc, char *argv[]) {
    if (argc >= 2) {
        char buffer[80];
        sprintf(buffer, "PADRE: Soy el proceso %d\n", getpid());
        write(1, buffer, strlen(buffer));
        int ret;
        for (int i = 1; i < argc; ++i) {
            ret = fork();
            if (ret == -1) {
                sprintf(buffer, "Error en el fork del proceso %d\n", getpid());
                error_y_exit(buffer, 1);
            }
            else if (ret == 0) {
                sprintf(buffer, "HIJO: Soy el proceso %d con parametro %s\n",getpid(), argv[i]);
                write(1, buffer, strlen(buffer));
                exit(0);
            }
        }
        while(waitpid(-1, NULL, 0)>0);
        char c;
        read(0, &c, sizeof(char));
    }
    else Usage();
}