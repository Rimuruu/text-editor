#include "linux_editor.h"

const int64_t FPS = 60;
const int64_t frameTime = 1000/FPS;

int64_t millis() {
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return ((int64_t) now.tv_sec) * 1000 + ((int64_t) now.tv_nsec) / 1000000;
}

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
   int64_t timeSpend,timeStart = millis(),timeEnd = millis(),timeStartLoop = millis();
   int64_t frameCount = 0;
   while(e->isRunning){

   	timeStart = millis();
	handleEvent(e);
	printFile(e);
	renderScreen();
	timeEnd = millis();
	timeSpend =timeEnd - timeStart; 		
	if(timeSpend < frameTime)
		msleep(frameTime - (timeSpend));
	timeSpend = timeEnd - timeStartLoop;
	if(timeSpend >= 1000){
		frameCount = 0;
		timeStartLoop = millis();
	}
	frameCount++;
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