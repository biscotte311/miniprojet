CC = gcc
CFLAGS = -g
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})

main : ${BINAIRES}
	${CC} ${CFLAGS} -o $@ $^

main.o : library.h

chiffragecesar.o : library.h

dechiffragecesar.o : library.h

verifier.o : library.h

affichage.o : library.h

chiffrement_vigenere.o : library.h

dechiffrement_vigenere.o : library.h

clean :
	rm -f main
	rm -f *.o

