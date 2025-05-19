#include "files.h"


void loadFileContent(File* file){
	long size = 0;
	fseek(file->fd,0,SEEK_END);
	size = ftell(file->fd);
	file->size = size;
	file->content = (char*) malloc(size);
	fseek(file->fd,0,SEEK_SET);
	fgets(file->content,size,file->fd);
}

File* openFile(char * source){
	FILE* fd;
	File* file;	

	if(source == nullptr){
		return nullptr;
	}
	fd = fopen(source, "r");
	if(fd == NULL){
		return nullptr;
	}

	file = (File *) malloc(sizeof(File));	
	file->fd = fd;
	loadFileContent(file);
	return file; 



}

void closeFile(File* file){
	fclose(file->fd);
	free(file->content);
	free(file);
}	

