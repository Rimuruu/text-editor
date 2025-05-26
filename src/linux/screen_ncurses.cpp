#include "screen.h"


void initScreen(){
    initscr();	
	refresh();
    raw();
	getch(); 
}

void deleteScreen(){
	endwin();
}

void printFile(File* file){

}
