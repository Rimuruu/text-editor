#include "screen.h"

#include "ncurses.h"

void initScreen(){
    initscr();	
	refresh();
    raw();
}

void deleteScreen(){
	endwin();
}

void printFile(File* file){

}
