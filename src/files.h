
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#ifndef FILES_H
#define FILES_H

struct File {
	char** content; // todo load line by line 
	int rows,size;
	char* filename;
	char* source;
	FILE* fd;
};


int openFile( char* source,File* file);
void closeFile(File* file);
char* getFilename(char* source);
void addLine(File* f);
void addLineFromIndex(File* f,int index);
void addCharAt(File* f,int x,int y,char c);
void addLineAt(File* f,int y,int x);
void deleteCharAt(File* f, int x,int y);
void deleteLine(File* f,int y);
void saveFile(File* file);
#endif
