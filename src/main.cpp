#include <stdio.h>
#include <sys/ioctl.h>
#include "files.h"


int main(int argc, char** argv){
	File * file =	openFile(argv[1]);
	printf("%s\n",file->content);
	closeFile(file);	

	return 0;
}
