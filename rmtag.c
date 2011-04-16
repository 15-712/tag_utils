#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int result;
	char buf[255];
	if(argc != 3) {
		printf("Invalid number of arguments supplied to rmtag.\nUsage is 'rmtag filename tag'\n");
		return -1;
	}
	result = getcwd(buf, 255);
	if(result == -1)
		printf("Cannot get current working directory. error #%d\n", errno);
	strncat(buf, "/", strlen(buf)-255);
	strncat(buf, argv[1], strlen(buf)-255);
	printf("%s\n", buf);
	result = rmtag(buf, argv[2]);
	if(result == -1)
		printf("rmtag failed with error #%d\n", errno);
}
