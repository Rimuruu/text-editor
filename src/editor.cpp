#include "editor.h"


int initEditor(char* source, Editor* e){
	if(openFile(source,&(e->file))){
        e->isRunning = 0;
        return -1;
	}	
	printf("%s\n",e->file.content);	
	printf("%s\n",e->file.filename);
    initScreen();
    e->isRunning = 1;
	return 0;
}


void loop(Editor* e){
   while(e->isRunning){
    getch();
    e->isRunning = 0;
   } 
}


void closeEditor(Editor* e){
	closeFile(&(e->file));	
    deleteScreen();
}