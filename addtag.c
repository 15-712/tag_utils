#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int result;
	char buf[255];
	if(argc != 3) {
		printf("Invalid number of arguments supplied to addtag.\nUsage is 'addtag filename tag'\n");
		return -1;
	}
	if(argv[1][0] != '/' && argv[1][0] != '.') {
		result = getcwd(buf, 255);
		if(result == -1)
			printf("Cannot get current working directory. error #%d\n", errno);
		strncat(buf, "/", strlen(buf)-255);
		strncat(buf, argv[1], strlen(buf)-255);
	} else {
		strncpy(buf, argv[1], 255);
	}
	printf("%s\n", buf);
	result = addtag(buf, argv[2]);
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
