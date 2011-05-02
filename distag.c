#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <tagfs.h>

#define BUFFER_SIZE 255 

int main(int argc, char *argv[]) {
	int result, i;
	char buf[BUFFER_SIZE];
	struct stat s;
	if(argc != 2) {
		printf("Invalid number of arguments supplied to distag.\nUsage is 'distag filename'\n");
		return -1;
	}
	printf("Stating file: %s\n", argv[1]);
	result = stat(argv[1], &s);
	if(result == -1) {
		printf("Cannot stat file. Error #%d\n", errno);
		exit(0);
	}

	result = distag(s.st_ino, buf, BUFFER_SIZE, 0);
	
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
