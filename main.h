#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int put_char(char c);
int _printf(const char *format, ...);
int print_binary(unsigned int n);
int convert_b(va_list args);

#endif
