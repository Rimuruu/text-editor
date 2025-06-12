#include "files.h"

#define TMP_SIZE 128

bool isNewLine(char * line,int size){
	size--;
	while(size >= 0){
		if(line[size] == '\n'  ){
			return true;
		}
		size--;
	}
	return false;
}

void loadFileContent(File* file){
	long size = 0;
	char tmp[TMP_SIZE];
	fseek(file->fd,0,SEEK_END);
	size = ftell(file->fd);
	fseek(file->fd,0,SEEK_SET);
	file->size = size;
	file->content = (char **) malloc(sizeof(char *));
	file->content[0] = (char *) malloc(sizeof(char ));
	file->rows = 1;
	int line = 0, lineOffset = 0;	
	memset(tmp, '\0', TMP_SIZE);

	while(fgets(tmp,TMP_SIZE,file->fd)){
		int sizeLine = strlen(tmp)+1;
		file->content[line] = (char *) realloc(file->content[line],sizeof(char) * (lineOffset+ sizeLine ));
		memset(file->content[line]+lineOffset, '\0', sizeLine);
		strncpy(file->content[line]+lineOffset,tmp,sizeLine);

		lineOffset += sizeLine;
		if(isNewLine(tmp,sizeLine)){
			addLine(file);
			line++;
			lineOffset = 0;
		}
		memset(tmp, '\0', TMP_SIZE);
	}
}
void addLine(File* f){

	f->content = (char **) realloc(f->content, sizeof(char*) * ++f->rows);
	f->content[f->rows-1] = nullptr; // garbage value;		

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
	for(int i=0; i< file->rows; i++)
		free(file->content[i]);
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
