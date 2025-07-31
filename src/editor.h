#include "files.h"
#include "debug.h"

#ifndef EDITOR_H
#define EDITOR_H


struct Editor {
    File file;
    int isRunning;
    int cursorX = 0,cursorY = 0;

    int maxX = 0, maxY = 0;
};

int initEditor(char * source,Editor* e);
void moveCursor(Editor*e ,int dirX,int dirY);
void closeEditor(Editor* e);
void refreshCursor(Editor* e );
void addChar(Editor* e, char c);
void addLine(Editor*e );
void deleteChar(Editor* e);
void saveFile(Editor* e);
#endif