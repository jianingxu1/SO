#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketMng.c"
#define MAXSTRING 256

void errExit(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  int connectionFD;
  int ret;
  char buffer[MAXSTRING];
  if (argc != 2)
  {
    strcpy (buffer, "Usage: escritor_socket socketPath\n");
    write (2, buffer, strlen (buffer));
    exit (1);
  }

  connectionFD = clientConnection (argv[1]);
  if (connectionFD < 0) errExit("Error establishing connection");

  ret = read (connectionFD, buffer, sizeof (buffer));
  if (ret < 0) errExit("Error reading from connection");

  strcpy (buffer, "Hello there!\n");
  ret = write (connectionFD, buffer, strlen (buffer));
  if (ret < 0) errExit("Error writing on connection");

  while((ret = read(0, buffer, sizeof(buffer))) > 0) {
    if (write(connectionFD, buffer, ret) < 0) errExit("Error writing on connection");
  }
  closeConnection(connectionFD);
}
