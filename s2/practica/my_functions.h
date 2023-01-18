#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8

// Given a number in character type, convert it to int type.
unsigned int char2int(char c);

// Given a string, return 0 if string does not represent a number or its length > 8. Otherwise, return 1.
int isNumber(char *str);

// Given a number in string type, convert its representation to int type. 
int mi_atoi(char *s);

// Prints a usage message if the function is not used properly.
void Usage();

#endif
