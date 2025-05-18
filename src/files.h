

#include <stdio.h>
struct File {
	char* content;
	int size;
	char* filename;
	char* source;
	FILE* fd;
}


File openFile( char* source);
void closeFile(File* file);
