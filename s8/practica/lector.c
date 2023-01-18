#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO_FILE "myFifo"

void errExit(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  int fp = open(FIFO_FILE, O_RDONLY);
  if (fp == -1) errExit("error opening pipe");
  char buffer[256];
  int n_bytes;
  while((n_bytes = read(fp, buffer, sizeof(buffer))) > 0) {
    write(1, buffer, n_bytes);
  }
  close(fp);
}
