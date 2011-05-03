#ifndef _TAGFS
#define _TAGFS

#define MAX_FILENAME_LEN 255
#define MAX_TAG_LEN 255

#define ADDTAG 303
#define RMTAG 304
#define LSTAG 305
#define CHTAG 306
#define GETCWT 307
#define OPENTAG 308
#define MVTAG 309
#define DISTAG 310

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
