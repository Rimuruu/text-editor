#include "editor.h"


int initEditor(char* source, Editor* e){
	if(openFile(source,&(e->file))){
        e->isRunning = 0;
        return -1;
	}
    int i = 0;	
    e->isRunning = 1;
	return 0;
}



void closeEditor(Editor* e){
	closeFile(&(e->file));	
}