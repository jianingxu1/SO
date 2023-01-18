#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  char buffer[256];
  int fd = creat("./salida.txt", 0600);
  sprintf(buffer, "ABCD");
  write(fd, buffer, strlen(buffer));
}

