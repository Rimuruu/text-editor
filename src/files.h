
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
#endif
