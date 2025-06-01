#include "files.h"

#ifndef EDITOR_H
#define EDITOR_H


struct Editor {
    File file;
    int isRunning;
    int cursorX,cursorY = 0;
};

int initEditor(char * source,Editor* e);
void moveCursor(Editor*e ,int dirX,int dirY);
void closeEditor(Editor* e);
#endif