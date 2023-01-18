#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void trat(int s) {
  if (s == SIGINT) {
    char buff[64];
    sprintf(buff, "Signal SIGINT recibido\n");
    write(1, buff, strlen(buff));
  }
}

int
main ()
{
  struct sigaction sa;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sa.sa_handler = &trat;
  sigaction(SIGINT, &sa, NULL);
  char c;
  char buffer[256];
  int ret = read (0, &c, sizeof (char));
  if (ret > 0) sprintf(buffer, "Read correcto\n");
  else if (errno == EINTR) sprintf(buffer, "Read interrumpido por signal\n");
  else sprintf(buffer, "Read incorrecto\n");
  write(1, buffer, strlen(buffer));
  write (1, &c, sizeof (char));
}
