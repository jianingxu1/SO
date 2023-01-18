#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void errExit(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  char buffer[256];
  int pipefd[2];
  if (pipe(pipefd) == -1) errExit("pipe");
  switch(fork()) {
    case -1: errExit("fork");
    case 0:
      close(pipefd[1]); // close write end of pipe
      close(0);
      dup(pipefd[0]);   // set standard input to read end of pipe
      close(pipefd[0]);
      execlp("cat", "cat", (char *) 0);
      errExit("execlp");
    default:
      close(pipefd[0]); // close read end of pipe
      sprintf(buffer, "Inicio\n");
      write(pipefd[1], buffer, strlen(buffer)); 
      // close(pipefd[1]);
      waitpid(-1, NULL, 0);
      sprintf(buffer, "Fin\n");
      write(1, buffer, strlen(buffer));
      break;
   }
}
