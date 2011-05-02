#include <stdio.h>
#include <stdlib.h>
#include <tagfs.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	char line[80];
	int f = 0;
	int n;
	if(argc != 2) {
		printf("Invalid number of arguments supplied to ext2cat.\nUsage is 'tagcat filename'\n");
		exit(1);
	}
	f = open(argv[1], O_RDONLY);
	if(f == -1) {
		printf("Function failed with error #%d\n", errno);
		exit(1);
	}
	while((n = read(f, line, 80)) > 0) {
		write(1, line, n);
	}
	close(f);
	printf("\n");
}
