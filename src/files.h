
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef FILES_H
#define FILES_H

struct File {
	char* content;
	int size;
	char* filename;
	char* source;
	FILE* fd;
};


int openFile( char* source,File* file);
void closeFile(File* file);
char* getFilename(char* source);

#endif
