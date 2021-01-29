CFLAGS= -Wall -pedantic -std=c99 -g

libbinpath.a:	*.o 
ar -cv libbinpath.a *.o


.PHONY : all clean
all: printAllCombs bruteForcePlainText aes256 decrypt encrypt addPositions

addPositions: addPositions.o
	cc $(CFLAGS) addPositions.o -o addPositions

addPositions.o: addPostitions.c
	cc $(CFLAGS) addPositions.c -c -o addPositions.o

printAllCombs.o: util.o printAllCombs.c
	cc $(CFLAGS) printAllCombs.c -c -o printAllCombs.o

printAllCombs: printAllCombs.o
	cc $(CFLAGS) printAllCombs.o util.o  -o printAllCombs


aes256.o: aes256.c aes256.h decrypt.o encrypt.o
	cc $(CFLAGS) decrypt.o encrypt.o -c -o aes256.o
	
aes256: aes256.o
	cc $(CFLAGS) aes256.o -o aes256

bruteForcePlainText: bruteForcePlainText.o bruteForcePlainText.h
	cc $(CFLAGS) bruteForcePlainText.c -o bruteForcePlainText
	
# cc -Wall -pg binPath.c util.c crypto.c -lm -lcrypt -o binPathProfiler

bruteForcePlainText.o: bruteForcePlainText.c
	cc $(CFLAGS) bruteForcePlainText.c -c -o bruteForcePlainText.o
	
util.o: util.c 
	cc $(CFLAGS) -c util.c -o util.o
	
aes256_lib.o: aes256.h aes256.o
	cc $(CFLAGS) aes256_lib.c -c -o aes256_lib.o	

decrypt.o: decrypt.c aes256.h aes256_lib.o
	cc $(CFLAGS) decrypt.c -c -o decrypt.o

encrypt.o: encrypt.c aes256.h aes256_lib.o
	cc $(CFLAGS) encrypt.c -c -o encrypt.o
	
clean:
	rm -f *.o 
	rm -f binPathApp
	rm aes256
	rm aes
