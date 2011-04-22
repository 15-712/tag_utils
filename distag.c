#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 255 

int main(int argc, char *argv[]) {
	int result, i;
	char buf[BUFFER_SIZE];
	if(argc != 2) {
		printf("Invalid number of arguments supplied to distag.\nUsage is 'distag filename'\n");
		return -1;
	}
	result = distag(argv[1], buf, BUFFER_SIZE);
	
	if(result == -1) {
		switch(errno) {
			case ENOSYS:
				printf("Function has not been implemented. Did you insert the tagfs module?");
				break;
			case ENOENT:
				printf("No files found!\n");
				break;
			default:
				printf("Function failed with error #%d\n", errno);
				break;
		}
	} else {
		printf("Tags: %s\n", buf);
	}
}
