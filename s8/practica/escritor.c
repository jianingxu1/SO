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
  int fp = open(FIFO_FILE, O_WRONLY);
  if (fp == -1) errExit("open");
  int n_bytes;
  char buffer[256];
  while((n_bytes = read(0, buffer, sizeof(buffer))) > 0) {
    if (write(fp, buffer, n_bytes) < 0) errExit("write");
  }
  close(fp);
}
