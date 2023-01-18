#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define REGION_SIZE		4096

int *p;

void trat(int s) {
  if (s == SIGSEGV) {
    char buff[256];
    sprintf(buff, "Program code -- p address: %p, p value: %p, end heap address: %p\n", &p, p, p);
    p = malloc(sizeof(int));
  }
}
int
main (int argc, char *argv[])
{
  // captura SIGSEGV
  struct sigaction sa;
  sa.sa_flags = 0;
  sigfillset(&sa.sa_mask);
  sa.sa_handler = &trat;
  sigaction(SIGSEGV, &sa, NULL);

  int i = 0;
  char buff[256];

  sprintf (buff, "Addresses:\n");
  write (1, buff, strlen (buff));
  sprintf (buff, "\tp: %p\n", &p);
  write (1, buff, strlen (buff));

  p = malloc (sizeof (int));

  if (p == NULL)
    {
      sprintf (buff, "ERROR en el malloc\n");
      write (2, buff, strlen (buff));
    }

  while (1)
    {
      *p = i;
      sprintf (buff, "\tProgram code -- p address: %p, p value: %p, *p: %d\n",
               &p, p, *p);
      write (1, buff, strlen (buff));
      p++;
      i++;
    }

}
