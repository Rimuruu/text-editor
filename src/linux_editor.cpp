#include "linux_editor.h"

void loop(Editor* e){
   while(e->isRunning){
	printFile(&(e->file));
   } 
}


void run(char* source ,Editor* e){
	initEditor(source,e);
	initScreen();
	loop(e);
	closeEditor(e);
	deleteScreen();
}