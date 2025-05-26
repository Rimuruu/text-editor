#include "linux_editor.h"

void loop(Editor* e){
   while(e->isRunning){
    e->isRunning = 0;
   } 
}


void run(char* source ,Editor* e){
	initEditor(source,e);
	loop(e);
	closeEditor(e);
}