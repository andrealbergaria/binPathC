CFLAGS= -Wall -pedantic -std=c99 -g

.PHONY : all clean
all: printAllCombs bruteForcePlainText encrypt decrypt addPositions

libbinpath.a: $(wildcard *.o) 
	ar -cvq bin/libbinpath.a *.o

util.o: util.c util.h
	cc $(CFLAGS) -c util.c -o bin/util.o
	
encrypt: encrypt.o aes256_lib.o
	cc $(CFLGS) encrypt.o aes256_lib.o -o bin/encrypt
decrypt: decrypt.o aes256_lib.o
	cc $(CFLGS) decrypt.o aes256_lib.o -o bin/decrypt	

addPositions: addPositions.o
	cc $(CFLAGS) addPositions.o -o bin/addPositions

addPositions.o: addPositions.c
	cc $(CFLAGS) addPositions.c  -c -o bin/addPositions.o

printAllCombs.o: printAllCombs.c
	cc $(CFLAGS) printAllCombs.c  -c -o bin/printAllCombs.o

printAllCombs: printAllCombs.o util.o
	cc $(CFLAGS) -lm printAllCombs.o util.o  -o bin/printAllCombs

decrypt.o: decrypt.c aes256.h
	cc $(CFLAGS) decrypt.c -c -o decrypt.o

encrypt.o: encrypt.c aes256.h 
	cc $(CFLAGS) encrypt.c -c -o encrypt.o
	
bruteForcePlainText: bruteForcePlainText.o
	cc $(CFLAGS) bruteForcePlainText.c -o bruteForcePlainText
	
# cc -Wall -pg binPath.c util.c crypto.c -lm -lcrypt -o binPathProfiler

bruteForcePlainText.o: bruteForcePlainText.c
	cc $(CFLAGS) bruteForcePlainText.c -c -o bruteForcePlainText.o
	

aes256_lib.o: aes256.h
	cc $(CFLAGS) aes256_lib.c -c -o aes256_lib.o	


clean:
	rm -f *.o 
	
