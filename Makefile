IDIR =inc
ODIR=obj
SDIR = src

CC=gcc
CFLAGS=-I$(IDIR) -Wall -g

DEPS = $(wildcard $(IDIR)/*.h)
SRC = $(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))
qnote: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ && rm qnote	
