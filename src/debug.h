#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#ifndef DEBUG_H 
#define DEBUG_H


void log_debug(const char *fmt, ...); 
void create_debug_file();
#endif