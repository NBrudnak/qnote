IDIR =inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
#LDIR =../lib

_DEPS = cli.h note.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o note.o cli.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SDIR=src
$(ODIR): $(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
