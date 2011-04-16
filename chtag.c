#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int result;
	int i;
	if(argc > 1) {
		result = chtag(argv[1]);
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
	} else {
		printf("Please specify a tag");
	}
}
