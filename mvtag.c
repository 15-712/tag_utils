#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int result;
	if(argc != 3) {
		printf("Invalid number of arguments supplied to mvtag.\nUsage is 'mvtag oldtag newtag'\n");
		return -1;
	}
	result = mvtag(argv[1], argv[2]);
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
