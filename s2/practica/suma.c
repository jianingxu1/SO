#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_functions.h"

int main(int argc, char *argv[])
{
	char buffer [100];
    int sum = 0;
    int found = 0;
	for (int i = 1; i < argc; ++i) {
		if (isNumber(argv[i])) sum += mi_atoi(argv[i]);
		else { 
            found = 1;
			sprintf(buffer, "Error: the parameter \"%s\" is not a number\n", argv[i]);
            write(1, buffer, strlen(buffer));
        }
	}
    if (!found) {
       sprintf(buffer, "The addition is %d\n", sum); 
       write(1, buffer, strlen(buffer));
    }
}
