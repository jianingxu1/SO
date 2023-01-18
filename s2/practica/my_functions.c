#include "my_functions.h"

unsigned int char2int(char c) {
    return (c - '0');
}   

int isNumber(char *str) {
    int length = strlen(str);
    int answer = 1;
    if ((str[0] != '-' && length < MAX_SIZE) || (str[0] == '-' && length <= MAX_SIZE && length > 1)) {
         int i = 0;
         if (str[0] == '-') i = 1;
         while (i < length && answer == 1) {
             if (str[i] < '0' || str[i] > '9') answer = 0;
            ++i;
        }
    } else answer = 0;
    return answer;  
}

int mi_atoi(char *s) {
    int i = 0;
    int neg = 0; 
    if (s[i] == '-') {
        ++i;
        neg = 1;
    }
    int size = strlen(s);
    int num = 0;
    int found = 0;
    for (; i < size && !found; ++i) {
        if (s[i] > '9' || s[i] < '0') found = 1;
        else {
            num *= 10;
           num += char2int(s[i]); 
        } 
    }
    if (neg) num = -num; 
    return num; 
}

void Usage() {
    char buffer[150];
    sprintf(buffer, "Usage: listaParametros arg1 [arg2..argn]\nEste programa escribe por su salida la lista de argumentos que recibe\n");
    write(1, buffer, strlen(buffer));
}
