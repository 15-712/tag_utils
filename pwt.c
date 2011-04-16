#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char buf[255];
	int result;
	result = getcwt(buf, 255);
	if(result == -1) {
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
	printf("%s\n", buf);
}
