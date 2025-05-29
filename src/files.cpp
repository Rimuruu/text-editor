#include "files.h"

#define TMP_SIZE 128

void loadFileContent(File* file){
	long size = 0;
	char tmp[TMP_SIZE];
	fseek(file->fd,0,SEEK_END);
	size = ftell(file->fd);
	file->size = size;
	file->content = (char*) malloc(size);
	fseek(file->fd,0,SEEK_SET);
	char* offset = file->content;
	while(fgets(tmp,TMP_SIZE,file->fd)){
		int sizeLine = strlen(tmp);
		strncpy(offset,tmp,sizeLine);
		offset += sizeLine;	
	}
}

int openFile(char * source, File* file){
	FILE* fd;
	if(file == nullptr){
		return -1;
	}
	if(source == nullptr){
		return -1;
	}
	fd = fopen(source, "r");
	if(fd == NULL){
		return -1;
	}

	file->fd = fd;
	file->filename = getFilename(source);
	loadFileContent(file);
	return 0;


}

void closeFile(File* file){
	fclose(file->fd);
	free(file->content);
	free(file->filename);
	
}

int find(char* source, char c){
	int size = strlen(source);	
	int res = -1;	
	while(size--){
		if(source[size] == c){
			res = size;	
			break;
		}
	}
	return res;
}

char* getFilename(char* source){
	int size = strlen(source);
	char* res;
	if(size == 0)
	{
		return nullptr;
	}	
	int i = find(source,'/');
	if(i == -1){
		res = (char*) malloc(size);
		strncpy(res,source,size);
	}
	else{
		res = (char*) malloc(size - i);	
		strncpy(res,source+i+1,size-i);

	}
	return res;
}
