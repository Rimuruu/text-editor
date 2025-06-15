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

void moveCursorX(Editor* e,int dirX){
    int maxX = strlen(e->file.content[e->cursorY]);
    int nextPos = e->cursorX + dirX;
    if(!(nextPos >= maxX) && !(nextPos < 0) ){
        if(e->file.content[e->cursorY][nextPos] != '\n'){
            e->cursorX += dirX;}
        
    }
}
void moveCursorY(Editor* e,int dirY){
    int maxY = e->file.rows;
    int nextPos = e->cursorY + dirY;
    int maxX = strlen(e->file.content[nextPos]);
    if(!(nextPos >= maxY) && !(nextPos < 0) ){
            if(e->cursorX >= maxX || e->file.content[nextPos][e->cursorX] == '\n')
                e->cursorX = maxX - (maxX == 1 ? 1:2); // 2 for the \n
            e->cursorY += dirY;
    }
}
 

void moveCursor(Editor* e,int dirX, int dirY){
    moveCursorX(e,dirX);
    moveCursorY(e,dirY);
}

void closeEditor(Editor* e){
	closeFile(&(e->file));	
}