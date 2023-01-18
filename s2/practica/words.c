#include <stdio.h>
#include <string.h>
#include <unistd.h>

int countWords(char* str) {
    int words = 0;
    int found = 0;
    while (*str) {
        if (*str == ' ' || *str == '.' || *str == '\n' || *str == ',') found = 0;
        else if (found == 0) {
            ++words;
            found = 1;
        }
        ++str;
    }
    return words;
}

int main(int argc, char* argv[]) {
    char buff[40];
    int count = 0;
    if (argc > 1) count = countWords(argv[1]);
    sprintf(buff, "%d words\n", count);
    write(1, buff, strlen(buff));
}
