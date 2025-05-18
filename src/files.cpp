#include "files.h"


void loadFileContent(File* file){
	

}

File* openFile(char * source){
	FILE* fd;
	File* file;	

	if(source == nullptr){
		return nullptr;
	}
	fd = fopen(source, "r");
	if(fd == NULL){
		retun nullptr;
	}

	file = malloc(sizeof(File));	
	file.fd = fd;
	loadFileContent(file);
	return file; 



}

void closeFile(File* file){
	fclose(file->fd);
	free(file);
}	

