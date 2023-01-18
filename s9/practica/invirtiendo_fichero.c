#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdlib.h>

void Usage() {
    char buff[64];
    sprintf(buff, "Usage: invirtiendo_fichero <source_file> \n");
    write(1, buff, strlen(buff));
    exit(1);
}

void errExit(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    char buffer[256];
    if (argc != 2) Usage();
    sprintf(buffer, "%s", argv[1]);
    int fd_rd = open(buffer, O_RDONLY);
    if (fd_rd == -1) errExit("Error en el open");
    int posIni = lseek(fd_rd, -1, SEEK_END);
    char *token = strtok(buffer, ".");
    sprintf(buffer, "%s.inv", token);
    int fd_wr = open(buffer, O_WRONLY|O_CREAT|O_TRUNC, 0660);
    int ret;
    char c;
    while (posIni != -1 && (ret = read(fd_rd, &c, 1)) > 0) {
        write(fd_wr, &c, 1);
        --posIni;
        if (posIni != -1) lseek(fd_rd, -2, SEEK_CUR);
    }
    close(fd_rd);
    close(fd_wr);
}
