#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <string.h>
#include <errno.h>

#define MAX_NUM_RESULTS 50
#define TAG_BUFFER_SIZE 20 

int main(int argc, char *argv[]) {
	int result, i, j, count = 0, iter, iter2;
	struct inode_entry buf[MAX_NUM_RESULTS];
	char **tags;
	if(argc > 2) {
		printf("Invalid number of arguments supplied to lstag.\nUsage is 'lstag [expr]'\n");
		return -1;
	}

	tags = malloc(sizeof(char*)*TAG_BUFFER_SIZE);
	if(!tags) {
		printf("Unable to allocate memory\n");
		return 0;
	}
	for(i = 0; i < TAG_BUFFER_SIZE; i++) {
		tags[i] = malloc(sizeof(char) * MAX_TAG_LEN);
		if(!tags[i]) {
			for(j = 0; j < i; j++)
				free(tags[j]);
			printf("Unable to allocate memory\n");
			return 0;
		}
			
	}
	iter = 0;
	do {
		if(argc == 2) {
			count = lstag(argv[1], &buf, MAX_NUM_RESULTS, count*iter);
		} else {
			count = lstag(".", &buf, MAX_NUM_RESULTS, count*iter);
		}

		if(count < 0) 
			goto error;
		
		for(i = 0; i < count; i++) {
			result = 0;
			iter2 = 0;
			printf("(%lu) %s\t[", buf[i].ino, buf[i].filename);
			do {
				result = distag(buf[i].ino, tags, TAG_BUFFER_SIZE, result*iter2);
				iter2++;
				if(result < 0)
					goto error;
				for(j = 0; j < result-1; j++) 
					printf("%s ", tags[j]);
			} while(result == TAG_BUFFER_SIZE); 
			printf("%s]\n", tags[result-1]);
			
		}
		iter++;
	} while(count == MAX_NUM_RESULTS);
	goto free;
error:
	switch(errno) {
		case ENOSYS:
			printf("Function has not been implemented. Did you insert the tagfs module?\n");
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
free:
	for(i = 0; i < TAG_BUFFER_SIZE; i++)
		free(tags[i]);
	return 0;
}
