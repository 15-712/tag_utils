#ifndef _TAGFS
#define _TAGFS

#define MAX_FILENAME_LEN 255
#define MAX_TAG_LEN 255

#define ADDTAG 341
#define RMTAG 342
#define LSTAG 343
#define CHTAG 344
#define GETCWT 345
#define OPENTAG 346
#define MVTAG 347
#define DISTAG 348

struct inode_entry {
	unsigned long ino;
	char filename[MAX_FILENAME_LEN+1];
	unsigned int count;
};

int opentag(const char *filename, int flags) {
	return syscall(OPENTAG, filename, flags);
}
int addtag(const char *filename, const char **tag, unsigned int size) {
	return syscall(ADDTAG, filename, tag, size);
}

int rmtag(const char *filename, const char **tag, unsigned int size) {
	return syscall(RMTAG, filename, tag, size);
}
int chtag(const char *tagex) {
	return syscall(CHTAG, tagex);
}
int mvtag(const char *tag1, const char *tag2) {
	return syscall(MVTAG, tag1, tag2);
}
int getcwt(char *buf, unsigned long len) {
	return syscall(GETCWT, buf, len);
}
int lstag(const char  *expr, void  *buf, unsigned long size, int offset) {
	return syscall(LSTAG, expr, buf, size, offset);
}
int distag(unsigned long ino, char  **buf, unsigned long size, unsigned long tag_offset) {
	return syscall(DISTAG, ino, buf, size, tag_offset);
}
#endif
