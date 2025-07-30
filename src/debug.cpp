#include "debug.h"

void log_debug(const char *fmt, ...) {

    va_list args;
    va_start(args, fmt);
    FILE *log = fopen("debug.log", "a");
    if (log) {
        vfprintf(log, fmt, args);
        fclose(log);
    }
    va_end(args);
}

void create_debug_file() {

    FILE *log = fopen("debug.log", "w");
    if (log) {
        fprintf(log, "DEBUG\n");
        fclose(log);
    }
    else{
        printf("couldn't create the file\n");
    }
}
