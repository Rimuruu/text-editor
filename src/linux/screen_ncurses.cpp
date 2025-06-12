#include "screen.h"
#include "ncurses.h"

#define KEY_ESCAPE 27


int rows,cols = 0;

void initScreen(){
    initscr();	
	refresh();
    noecho();
    nodelay(stdscr,TRUE); // non blocking getch
    getmaxyx(stdscr,rows,cols);

    cbreak();
    keypad(stdscr, TRUE);

}

void deleteScreen(){
	endwin();
}

void printFile(Editor* e){
    move(0,0);
    const int maxRows = e->file.rows > rows ? rows : e->file.rows;
    for(int i = 0; i < maxRows; i++)
        printw("%s",e->file.content[i]);
    move(e->cursorX,e->cursorY);

}


void renderScreen(){
    refresh();
}

void moveCursorScreen(Editor* e,int dirX,int dirY){
    if(e->cursorX + dirX < 0 || e->cursorX + dirX >= rows  ){
        dirX = 0;
    } 
    if(e->cursorY + dirY < 0 || e->cursorY + dirY >= cols  ){
        dirY = 0;
    }
    
    moveCursor(e,dirX,dirY);
    move(e->cursorX,e->cursorY);
    
}


void handleKey(Editor* e,int key){
    switch(key){
        case KEY_ESCAPE:
            e->isRunning = 0;        
            break;
        case KEY_UP:
            moveCursorScreen(e,-1,0);     
             break;
        case KEY_DOWN:
            moveCursorScreen(e,1,0);
             break;
        case KEY_LEFT:
            moveCursorScreen(e,0,-1); 
            break;
        case KEY_RIGHT:
            moveCursorScreen(e,0,1);
            break;
    }
}

void handleEvent(Editor* e){
	int key = getch();
	while(key != ERR){
        handleKey(e,key);
        key = getch();
    }
}
