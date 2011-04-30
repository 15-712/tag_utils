#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char line[80];
	int f = 0;
	int n;
	if(argc != 3) {
		printf("Invalid number of arguments supplied to tagwrite.\nUsage is 'tagwrite tags string'\n");
		exit(1);
	}
	f = opentag(argv[1], O_WRONLY);
	if(f == -1) {
		switch(errno) {
			case ENOSYS:
				printf("Function has not been implemented. Did you insert the tagfs module?\n");
				break;
			default:
				printf("Function failed with error #%d\n", errno);
				break;
		}
		exit(1);
	}
	write(f, argv[2], strlen(argv[2]));
}
