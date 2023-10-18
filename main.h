#ifndef HEADER_H
#define HEADER_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
void handle_char(va_list my_list, int *counter);
void handle_string(va_list my_list, int *counter);
int handle_intger(va_list my_list);
void handle_unintger(va_list my_list);
void handle_percent(int *counter);
void handle_binary(va_list my_list, int *counter);



#endif
