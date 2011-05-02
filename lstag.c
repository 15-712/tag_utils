#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

#define MAX_NUM_RESULTS 50
#define TAG_BUFFER_SIZE 255 

int main(int argc, char *argv[]) {
	int result, i;
	struct inode_entry buf[MAX_NUM_RESULTS];
	char tags[TAG_BUFFER_SIZE];
	if(argc > 2) {
		printf("Invalid number of arguments supplied to lstag.\nUsage is 'lstag [expr]'\n");
		return -1;
	}
	if(argc == 2) {
		result = lstag(argv[1], &buf, MAX_NUM_RESULTS, 0);
	} else {
		result = lstag(".", &buf, MAX_NUM_RESULTS, 0);
	}

	if(result == -1) 
		goto error;
	
	for(i = 0; i < result; i++) {
		result = distag(buf[i].ino, tags, TAG_BUFFER_SIZE, 0);
		if(result == -1)
			goto error;
		printf("(%lu) %s\t[%s]\n", buf[i].ino, buf[i].filename, tags);
	}
	return 0;
error:
	switch(errno) {
		case ENOSYS:
			printf("Function has not been implemented. Did you insert the tagfs module?");
			exit(0);
			break;
		case ENOENT:
			printf("No files found!\n");
			exit(0);
			break;
		default:
			printf("Function failed with error #%d\n", errno);
			exit(0);
			break;
	}
	return 0;
}
