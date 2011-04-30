CC = gcc
OBJS = pwt chtag addtag rmtag mvtag lstag tagcat distag tagwrite
BIN_DIR = bin

all:
	make $(OBJS)

pwt: pwt.c 
	$(CC) -o $(BIN_DIR)/$@ $^

chtag: chtag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

addtag: addtag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

rmtag: rmtag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

mvtag: mvtag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

lstag: lstag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

tagcat: tagcat.c 
	$(CC) -o $(BIN_DIR)/$@ $^

distag: distag.c 
	$(CC) -o $(BIN_DIR)/$@ $^

tagwrite: tagwrite.c 
	$(CC) -o $(BIN_DIR)/$@ $^

clean:
	rm $(BIN_DIR)/*
