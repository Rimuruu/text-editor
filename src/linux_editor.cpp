#include "linux_editor.h"



int msleep(long msec) {
    struct timespec ts;
    int res;

    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

void loop(Editor* e){
   while(e->isRunning){
	handleEvent(e);
	//printFile(&(e->file));
	//renderScreen();
	msleep(1000/60);
   } 
}


void run(char* source ,Editor* e){
	initEditor(source,e);
	printf("%s",e->file.content);	
	initScreen();
	loop(e);
	closeEditor(e);
	deleteScreen();
}