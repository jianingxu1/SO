#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char buffer[256];
  int fd = open("./salida.txt", O_RDWR);
  lseek(fd, -1, SEEK_END);
  char cRead;
  read(fd, &cRead, 1);
  lseek(fd, -1, SEEK_END);
  char c = 'X';
  write(fd, &c, 1);
  write(fd, &cRead, 1);
}
