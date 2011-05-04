#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int result;
	char buf[255];
	if(argc < 3) {
		printf("Invalid number of arguments supplied to addtag.\nUsage is 'addtag filename tag1 [tag2 tag3 ...]'\n");
		return -1;
	}
	//printf("addtag(%s, %s, %d)\n", argv[1], argv[2], argc-2);
	result = addtag(argv[1], (const char **)&argv[2], argc-2);
	if(result == -1) {
		switch(errno) {
			case ENOSYS:
				printf("Function has not been implemented. Did you insert the tagfs module?\n");
				break;
			default:
				printf("Function failed with error #%d\n", errno);
				break;
		}
	}
}
