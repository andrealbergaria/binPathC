CFLAGS= -Wall -pedantic -std=c99 -g

.PHONY : all clean
all: printAllCombs bruteForcePlainText aes256 addPositions

libbinpath.a: $(wildcard *.o) 
	ar -cvq libbinpath.a *.o

util.o: util.c util.h
	cc $(CFLAGS) -c util.c -o util.o
	

addPositions: addPositions.o
	cc $(CFLAGS) addPositions.o -o addPositions

addPositions.o: addPositions.c
	cc $(CFLAGS) addPositions.c  -c -o addPositions.o

printAllCombs.o: printAllCombs.c
	cc $(CFLAGS) printAllCombs.c  -c -o printAllCombs.o

printAllCombs: printAllCombs.o
	cc $(CFLAGS) -lm printAllCombs.o util.o  -o printAllCombs

decrypt.o: decrypt.c aes256.h
	cc $(CFLAGS) decrypt.c -c -o decrypt.o

encrypt.o: encrypt.c aes256.h
	cc $(CFLAGS) encrypt.c -c -o encrypt.o
	

aes256.o: aes256.c aes256.h 
	cc $(CFLAGS) aes256.c -c -o aes256.o
	
aes256: aes256.o encrypt.o decrypt.o aes256_lib.o
	cc $(CFLAGS) aes256.o encrypt.o decrypt.o aes256_lib.o -o aes256

bruteForcePlainText: bruteForcePlainText.o
	cc $(CFLAGS) bruteForcePlainText.c -o bruteForcePlainText
	
# cc -Wall -pg binPath.c util.c crypto.c -lm -lcrypt -o binPathProfiler

bruteForcePlainText.o: bruteForcePlainText.c
	cc $(CFLAGS) bruteForcePlainText.c -c -o bruteForcePlainText.o
	

aes256_lib.o: aes256.h aes256.c
	cc $(CFLAGS) aes256_lib.c -c -o aes256_lib.o	


clean:
	rm -f *.o 
	
