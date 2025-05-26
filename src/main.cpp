#include <stdio.h>
#include <sys/ioctl.h>
#include "editor.h"
#include "plateform.h"
int main(int argc, char** argv){
	if(argc < 2){
		return -1;	
	}
	Editor e;	
	run(argv[1],&e);
	
}
