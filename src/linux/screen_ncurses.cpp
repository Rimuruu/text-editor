#include "screen.h"
#include "ncurses.h"
#include <signal.h>
#include <ctype.h>
#define KEY_ESCAPE 27


int rows,cols,scrollX = 0,scrollY = 0;
Editor* editor;
#ifdef TABSIZE
    int tabsize = TABSIZE;
#else
    int tabsize = 8;
#endif
int get_tabsize() {
    return TABSIZE;  
}

void refreshEditor(Editor *e){
    endwin();               
    initscr();	
	refresh();
    noecho();
    nodelay(stdscr,TRUE);
    getmaxyx(stdscr,rows,cols);
    e->maxX = cols;
    e->maxY = rows; 
    cbreak();
    keypad(stdscr, TRUE);
    set_tabsize(TABSIZE);
    refreshCursor(e);

}

void handle_winch(int sig){
   refreshEditor(editor); 
}



void initScreen(Editor* e){
    initscr();	
	refresh();
    noecho();
    nodelay(stdscr,TRUE); 
    getmaxyx(stdscr,rows,cols);
    e->maxX = cols;
    e->maxY = rows; 
    editor = e;
    cbreak();
    keypad(stdscr, TRUE);
    signal(SIGWINCH, handle_winch);
    set_tabsize(TABSIZE);
}

void deleteScreen(){
	endwin();
}

void printFile(Editor* e){
    move(0,0);
    const int start = scrollY;
    const int maxRows = e->file.rows > rows+start ? rows+start : e->file.rows;
 
    for(int i = start; i < maxRows; i++){
        const int startX = scrollX;
        const int textSize = strlen(e->file.content[i]);
        const int maxCols = textSize > cols ? cols+startX: textSize;
        for(int y = startX; y < maxCols; y++){
            printw("%c",e->file.content[i][y]);
        }
        if(startX >= maxCols){
            printw("\n");
        }
      
    }
    for(int i = 0; i < maxRows-start; i++)
        printw("\n");
    int translatedX  = translateX(e);
    move(e->cursorY-scrollY,translatedX);

}


void renderScreen(){
    refresh();
}

int charCountBefore(char * s, char f,int x){
    int r = 0;
    for(int i = x; i >= 0 ; i--){
        if(s[i] == f){
            {
                r++;
            }
        }
    } 
    return r;
}

int  translateX(Editor* e){
    int x = e->cursorX-scrollX;
    int tabsCount = charCountBefore(e->file.content[e->cursorY],'\t',x-1) * (TABSIZE-1);
    x += tabsCount;
    return x;
}

void checkScroll(Editor* e){
    int colsFile = strlen(e->file.content[e->cursorY]);
    if(e->cursorY >= rows+scrollY && rows+scrollY < e->file.rows){

        scrollY++;
    }
    if(e->cursorY < scrollY && scrollY != 0){
        scrollY--;
    }
    if(e->cursorX >= cols+scrollX && cols+scrollX < colsFile){

        scrollX++;
    }
    if(e->cursorX < scrollX && scrollX != 0){
        scrollX--;
    }
}

void moveCursorScreen(Editor* e,int dirX,int dirY){

    
    moveCursor(e,dirX,dirY);
    checkScroll(e);
    move(e->cursorY,translateX(e));
    
}


void handleKey(Editor* e,int key){
    switch(key){
        case KEY_ESCAPE:
            e->isRunning = 0;        
            break;
        case KEY_UP:
            moveCursorScreen(e,0,-1);     
             break;
        case KEY_DOWN:
            moveCursorScreen(e,0,1);
             break;
        case KEY_LEFT:
            moveCursorScreen(e,-1,0); 
            break;
        case KEY_RIGHT:
            moveCursorScreen(e,1,0);
            break;
        case '\n':
            case KEY_ENTER:
            addLine(e);     
            break;
        case KEY_F(1): 
            saveFile(e);
            break;
        default:
            if(isprint(key)){
                addChar(e,(char)key);
            }
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

int get_charsize(char c){
    if(c == '\n'){
        return get_tabsize();
    }
    return 1;
}
