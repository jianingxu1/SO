#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8

int
isNumber(char *str)
{
	int		length = strlen(str);
	int		answer = 1;
	if ((str[0] != '-' && length < MAX_SIZE) || (str[0] == '-' && length <= MAX_SIZE && length > 1)) {
		int		i = 0;
		if (str[0] == '-')
			i = 1;
		while (i < length && answer == 1) {
			if (str[i] < '0' || str[i] > '9')
				answer = 0;
			++i;
		}
	} else
		answer = 0;
	return answer;
}

int
main(int argc, char *argv[])
{
	char		buffer    [100];
	for (int i = 1; i < argc; ++i) {
		if (!isNumber(argv[i]))
			sprintf(buffer, "%s is not a number or it has more than 8 digits!\n", argv[i]);
		else
			sprintf(buffer, "%s is a number!\n", argv[i]);
		write(1, buffer, strlen(buffer));
	}
}
