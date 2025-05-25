#include <stdio.h>
#include <sys/ioctl.h>
#include "editor.h"
int main(int argc, char** argv){
	if(argc < 2){
		return -1;	
	}
	Editor e;	
	initEditor(argv[1],&e);
	loop(&e);
	closeEditor(&e);
}
