#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "socketMng.c"
#define MAXSTRING 256

void errExit(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  int socketFD;
  int connectionFD;
  char buffer[MAXSTRING];
  int ret;
  if (argc != 2) {
    sprintf(buffer, "Usage: lector_socket socketPath\n");
    write(1, buffer, strlen(buffer));
    exit(1);
  }
  socketFD = createSocket(argv[1]);
  if (socketFD < 0) errExit("Error creating socket");

  connectionFD = serverConnection(socketFD);
  if (connectionFD < 0) errExit("Error establishing connection");

  strcpy(buffer, "Hello!\n");
  ret = write(connectionFD, buffer, strlen(buffer));
  if (ret < 0) errExit("Error writing on connection");

  char c;
  while ((ret = read(connectionFD, &c, sizeof(c))) > 0) {
    write(1, &c, ret);
  }
  closeConnection(connectionFD);
  deleteSocket(socketFD, argv[1]);
}
