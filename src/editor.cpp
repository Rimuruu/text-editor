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
    bool islastLine = e->cursorY == e->file.rows-1 ;
    if(!(nextPos >= maxX) && !(nextPos < 0)  ){
        char c = e->file.content[e->cursorY][nextPos];  
        e->cursorX += dirX;

        
    }else if(islastLine){
            if(!(nextPos > maxX) && !(nextPos < 0)){
                e->cursorX += dirX;
            }
             
    }

    
}

void moveCursorY(Editor* e,int dirY){
    int maxY = e->file.rows;
    int nextPos = e->cursorY + dirY;
    int nextPosFile = nextPos ;
    if(!(nextPosFile >= maxY)   && !(nextPos < 0) ){  

            int maxX = strlen(e->file.content[nextPosFile]);
            if(e->cursorX >= maxX || e->file.content[nextPosFile][e->cursorX] == '\n')
                {   
                e->cursorX = maxX - 1;
                }
            e->cursorY += dirY;
    }
   
}
 

void moveCursor(Editor* e,int dirX, int dirY){
    if(dirX != 0) moveCursorX(e,dirX);
    if(dirY != 0) moveCursorY(e,dirY);
}

void closeEditor(Editor* e){
	closeFile(&(e->file));	
}

void refreshCursor(Editor* e ){
    if(e->cursorY >= e->maxY){
        e->cursorY = e->maxY-1;
        int maxX = strlen(e->file.content[e->cursorY]);
        if(e->cursorX > maxX){
            e->cursorX = maxX-1;
        }
    }
    if(e->cursorX >= e->maxX){
        e->cursorX = e->maxX-1;
    }
}

void addChar(Editor* e, char c ){
    addCharAt(&(e->file),e->cursorX,e->cursorY,c);
    e->cursorX++;
}

void addLine(Editor*e ){
    addLineAt(&(e->file),e->cursorX,e->cursorY);
    e->cursorY++;
    e->cursorX=0;
}


void saveFile(Editor* e){
    saveFile(&(e->file));
}