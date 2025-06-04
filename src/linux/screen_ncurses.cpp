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
    printw("%s",e->file.content);
    move(e->cursorX,e->cursorY);

}


void renderScreen(){
    refresh();
}

void moveCursorScreen(Editor* e,int dirX,int dirY){
    moveCursor(e,dirX,dirY);
    move(e->cursorX,e->cursorY);
    //printf("%d %d\n",e->cursorX,e->cursorY);
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
