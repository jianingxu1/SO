#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void Usage() {
    char buff[120];
    sprintf(buff, "Usage: parsExec. Este programa escribe unos argumentos.\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg,int exit_status) {
    perror(msg);
    exit(exit_status);
}

int main (int argc, char *argv[]) {
    if (argc == 1) {
        for (int i = 0; i < 4; ++i) {
            int pid = fork();
            char buffer[100];
            if (pid == -1) error_y_exit("Error en fork", 1);
            else if (pid == 0) {
                if (i == 0) execlp("./listaParametros", "listaParametros", "a", "b", (char*)0);
                else if (i == 1) execlp("./listaParametros", "listaParametros", (char*)0);
                else if (i == 2) execlp("./listaParametros", "listaParametros", "25", "4", (char*)0);
                else if (i == 3) execlp("./listaParametros", "listaParametros", "1024", "hola", "adios", (char*)0);
                sprintf(buffer, "Ha fallado la mutación al listaParametros del proceso %d", getpid());
                error_y_exit(buffer, 1);
            }
        }
        while(waitpid(-1, NULL, 0) > 0);
    }
    else Usage();
}