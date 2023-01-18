#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define FIFO_FILE "myFifo"

void errExit(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  char buffer[256];
  int fp = open(FIFO_FILE, O_WRONLY|O_NONBLOCK);
  if (errno == ENXIO) {
    sprintf(buffer, "Esperando a que haya un lector en la pipe %s...\n", FIFO_FILE);
    write(1, buffer, strlen(buffer));
    fp = open("./myFifo", O_WRONLY);
    sprintf(buffer, "Se ha encontrado un lector en la pipe!\n");
    write(1, buffer, strlen(buffer));
  }
  if (fp == -1) errExit("open");
  int n_bytes;
  while((n_bytes = read(0, buffer, sizeof(buffer))) > 0) {
    if (write(fp, buffer, n_bytes) < 0) errExit("write");
  }
  close(fp);
}
