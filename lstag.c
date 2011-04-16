#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

#define MAX_NUM_RESULTS 50

int main(int argc, char *argv[]) {
	int result, i;
	struct inode_entry buf[MAX_NUM_RESULTS];
	if(argc > 2) {
		printf("Invalid number of arguments supplied to lstag.\nUsage is 'lstag [expr]'\n");
		return -1;
	}
	if(argc == 2)
		result = lstag(argv[2], buf, MAX_NUM_RESULTS, 0);
	else
		result = lstag(".", buf, MAX_NUM_RESULTS, 0);
	for(i = 0; i < result; i++) {
		printf("ino: %lu\tfilename: %s\n", buf[i].ino, buf[i].filename);
	}

	if(result == -1) {
		switch(errno) {
			case ENOSYS:
				printf("Function has not been implemented. Did you insert the tagfs module?");
				break;
			default:
				printf("Function failed with error #%d\n", errno);
				break;
		}
	}
}
