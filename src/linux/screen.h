#include "../files.h"
#include "../editor.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef SCREEN_H
#define SCREEN_H

extern int rows,cols;

void deleteScreen();
void initScreen();
void printFile(Editor* e);
void renderScreen();
void handleEvent(Editor* e);
void moveCursorScreen(Editor* e,int dirX,int dirY);

void handleKey(Editor* e,int key);
#endif

