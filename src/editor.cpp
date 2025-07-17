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
    int maxX = strlen(e->file.content[e->cursorY+e->scrollY]);
    int nextPos = e->cursorX + dirX;
    if(!(nextPos >= maxX) && !(nextPos < 0) ){
        if(e->file.content[e->cursorY+e->scrollY][nextPos] != '\n'){
            e->cursorX += dirX;}
        
    }
    
}

void moveCursorY(Editor* e,int dirY){
    int maxY = e->file.rows;
    int nextPos = e->cursorY + dirY;
    int nextPosFile = nextPos + e->scrollY;
    log_debug("%d %d %d %d\n",e->maxY, nextPos, maxY,nextPosFile);
    log_debug("%d\n",1);
    if(!(nextPosFile >= maxY)  && !(nextPos >= e->maxY-1) && !(nextPos < 0) ){
            printf("%d %d down", nextPosFile, e->maxY);
            int maxX = strlen(e->file.content[nextPosFile]);
            if(e->cursorX >= maxX || e->file.content[nextPosFile][e->cursorX] == '\n')
                e->cursorX = maxX - (maxX == 1 ? 1:2); // 2 for the \n
            e->cursorY += dirY;
    }
    else if ((nextPosFile < maxY) && nextPos >= e->maxY-1){
        //printf("scroll");
        e->scrollY++; 
    }
    else if (nextPos <= 0 && e->scrollY > 0)
    {
        e->scrollY--;
    }
}
 

void moveCursor(Editor* e,int dirX, int dirY){
    moveCursorX(e,dirX);
    moveCursorY(e,dirY);
}

void closeEditor(Editor* e){
	closeFile(&(e->file));	
}