####################################################################################
# @brief The makefile for the s-expression parser
# @author Nathanaël Beaudoin-Dion
# @date December 27th 2019
####################################################################################

CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=run

all: $(EXEC)

run: sexp-parser.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o