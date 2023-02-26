IDIR =inc
CC=gcc
CFLAGS=-I$(IDIR) -Wall -g

ODIR=obj
LDIR =../lib

_DEPS = cli.h note.h user.h lex.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o note.o cli.o user.o lex.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SDIR = src
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

qlex: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
