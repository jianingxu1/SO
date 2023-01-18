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
    sprintf(buff, "Usage: append <file_name>\n");
    write(1, buff, strlen(buff));
    exit(1);
}

int main(int argc, char *argv[]) {
    char buffer[256];
    if (argc != 2) Usage();
    sprintf(buffer, "%s", argv[1]);
    int fd_rd = open(buffer, O_RDONLY);
    int fd_wr = open(buffer, O_WRONLY);
    int posEnd = lseek(fd_wr, 0, SEEK_END);
    int ret;
    int posIni = 0;
    while (posIni != posEnd && (ret = read(fd_rd, buffer, sizeof(buffer))) > 0) {
        write(fd_wr, buffer, ret);
        posIni += ret;
    }
    close(fd_rd);
    close(fd_wr);
}
