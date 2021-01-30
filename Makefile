CFLAGS= -Wall -pedantic -std=c99 -g
HOME= /home/andrec/workspace_c/binPathC
CIPHER_DIR= $(HOME)/testCiphers/bin
.PHONY : all clean

include $(HOME)/testCiphers/Makefile
include $(HOME)/src/Makefile

all: printAllCombs bruteForcePlainText encrypt decrypt addPositions

libbinpath.a: $(wildcard *.o) 
	ar -cvq bin/libbinpath.a *.o

util.o: util.c util.h
	cc $(CFLAGS) -c util.c -o bin/util.o
	
encrypt: encrypt.o aes256_lib.o
	cc $(CFLGS) encrypt.o aes256_lib.o -o $(CIPHER_DIR)/encrypt
decrypt: decrypt.o aes256_lib.o
	cc $(CFLGS) decrypt.o aes256_lib.o -o $(CIPHER_DIR)/decrypt	

decrypt.o: decrypt.c aes256.h
	cc $(CFLAGS) $(HOME)/testCiphers/src/decrypt.c -c -o $(CIPHER_DIR)/decrypt.o

encrypt.o: encrypt.c aes256.h 
	cc $(CFLAGS) $(HOME)/tesCiphers/src/encrypt.c -c -o $(CIPHER_DIR)/encrypt.o


addPositions: addPositions.o
	cc $(CFLAGS) addPositions.o -o $(HOME)/bin/addPositions

addPositions.o: addPositions.c
	cc $(CFLAGS) addPositions.c  -c -o $(HOME)/bin/addPositions.o

printAllCombs.o: printAllCombs.c
	cc $(CFLAGS) printAllCombs.c  -c -o $(HOME)/bin/printAllCombs.o

printAllCombs: printAllCombs.o util.o
	cc $(CFLAGS) -lm printAllCombs.o util.o  -o $(HOME)/bin/printAllCombs

	
bruteForcePlainText: bruteForcePlainText.o
	cc $(CFLAGS) bruteForcePlainText.c -o $(HOME)/bin/bruteForcePlainText
	
# cc -Wall -pg binPath.c util.c crypto.c -lm -lcrypt -o binPathProfiler

bruteForcePlainText.o: bruteForcePlainText.c
	cc $(CFLAGS) bruteForcePlainText.c -c -o $(HOME)/bin/bruteForcePlainText.o
	

aes256_lib.o: aes256.h
	cc $(CFLAGS) aes256_lib.c -c -o $(CIPHER_DIR)/bin/aes256_lib.o	
