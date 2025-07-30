#include "../files.h"
#include "../editor.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef SCREEN_H
#define SCREEN_H

extern int rows,cols,scrollX,scrollY;
extern int tabsize;
extern Editor* editor;
int get_charsize(char c);
int get_tabsize();
void deleteScreen();
void initScreen(Editor* e);
void printFile(Editor* e);
void renderScreen();
void handleEvent(Editor* e);
void moveCursorScreen(Editor* e,int dirX,int dirY);
int  translateX(Editor* e);
void handleKey(Editor* e,int key);
#endif

