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

void printFile(File* file){
    move(0,0);
    printw("%d %d",rows,cols);
    printw("%s",file->content);
}


void renderScreen(){
    refresh();
}

void moveCursorScreen(Editor* e,int dirX,int dirY){
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
    printf("start");
	int key = getch();

    printf("end");
	while(key != ERR){
        handleKey(e,key);
        key = getch();
    }
}
