#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void Usage() {
    char buff[120];
    sprintf(buff, "Usage: myPS arg1. Este programa escribe el pid del proceso padre, el del hijo y el argumento.\n");
    write(1, buff, strlen(buff));
}

void error_y_exit(char *msg,int exit_status) {
    perror(msg);
    exit(exit_status);
}

/* Ejecuta el comando ps –u username mediante la llamada al sistema execlp */ /* Devuelve: el código de error en el caso de que no se haya podido mutar */
void muta_a_PS(char *username) {
    execlp("ps", "ps", "-u", username, (char*)NULL);
    error_y_exit("Ha fallado la mutación al ps", 1);
}

int main (int argc, char *argv[]) {
    if (argc == 2) {
        char buffer[80];
        int pid;
        if ((pid = fork())<0) error_y_exit("Error en fork", 1);
        else if (pid == 0) {
            sprintf(buffer, "HIJO: soy el proceso %d y el parametro es %s\n", getpid(), argv[1]);
            write(1, buffer, strlen(buffer));
            muta_a_PS(argv[1]);
        }
        else {
            sprintf(buffer, "PADRE: Soy el proceso %d\n", getpid());
            write(1, buffer, strlen(buffer));
        }
        while(1);
    }
    else Usage();
}