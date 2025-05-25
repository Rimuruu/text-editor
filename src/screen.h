#include "files.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "ncurses.h"
#ifndef SCREEN_H
#define SCREEN_H

void deleteScreen();
void initScreen();
void printFile(File* file);
#endif

