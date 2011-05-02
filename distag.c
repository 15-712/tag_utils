#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <tagfs.h>

#define BUFFER_SIZE 25 

int main(int argc, char *argv[]) {
	int result, i, j;
	char **buf;
	struct stat s;

	if(argc != 2) {
		printf("Invalid number of arguments supplied to distag.\nUsage is 'distag filename'\n");
		return -1;
	}
	result = stat(argv[1], &s);
	if(result == -1) {
		printf("Cannot stat file. Error #%d\n", errno);
		exit(0);
	}

	buf = malloc(sizeof(char*)*BUFFER_SIZE);
	if(!buf) {
		printf("Unable to allocate memory\n");
		return 0;
	}
	for(i = 0; i < BUFFER_SIZE; i++) {
		buf[i] = malloc(sizeof(char) * MAX_TAG_LEN);
		if(!buf[i]) {
			printf("Error allocating buffer\n");
			for(j = 0; j < i; j++)
				free(buf[j]);
			return 0;
		}
			
	}
	result = distag(s.st_ino, buf, BUFFER_SIZE, 0);
	
	if(result == -1) {
		switch(errno) {
			case ENOSYS:
				printf("Function has not been implemented. Did you insert the tagfs module?");
				break;
			case ENOENT:
				printf("No tags found!\n");
				break;
			default:
				printf("Function failed with error #%d\n", errno);
				break;
		}
	} else {
		if(result > 0) {
			printf("Tags: ");
			for(i = 0; i < result; i++) {
				printf("%s ", buf[i]);
				free(buf[i]);
			}
			printf("\n");
		} else {
			printf("File has no tags.\n");
		}
	}
}
