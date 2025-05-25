#include "files.h"
#include "screen.h"
#ifndef EDITOR_H
#define EDITOR_H


struct Editor {
    File file;
    int isRunning;
};

int initEditor(char * source,Editor* e);
void loop(Editor* e);
void closeEditor(Editor* e);
#endif