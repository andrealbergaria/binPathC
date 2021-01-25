all: printAllCombs binPath aes256

printAllCombs: printAllCombs.o
	cc printAllCombs.o util.o -lm -g -o printAllCombs

printAllCombs.o: util.o printAllCombs.c
	gcc printAllCombs.c -g -c -o printAllCombs.o

aes256: aes256.o libbinpath.a
	cc aes256.o -lbinpath -g -L. -o aes
	

binPath: binPath.o libbinpath.a
	cc binPath.o -lbinpath -L. -lm -o binPath
# cc -Wall -pg binPath.c util.c crypto.c -lm -lcrypt -o binPathProfiler

binPath.o: binPath.c
	cc binPath.c -g -c -o binPath.o

getValues: getBinariesFromDecimals.o
	cc getBinariesFromDecimals.o -lbinpath -L. -o getValues
	
util.o: util.c util.h
	cc -c util.c -g -o util.o

aes256.o: aes256.c aes256.h
	cc aes256.c -c -g -o aes256.o
	
aes256_lib.o: aes256_lib.c
	cc aes256_lib.c -c -g -o aes256_lib.o	
clean:
	rm -f binPath.o util.o aes256.o 
	rm -f libbinpath.o
	rm -f libbinpath.a
	rm -f binPathApp
	
	
libbinpath.a: util.o aes256.o aes256_lib.o
	ar -cvr libbinpath.a util.o aes256.o aes256_lib.o

getBinariesFromDecimals.o: getBinariesFromDecimals.c
	cc -c getBinariesFromDecimals.c -g -lbinpath -o getBinariesFromDecimals.o
