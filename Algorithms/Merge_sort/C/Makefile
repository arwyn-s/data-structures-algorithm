
#SDIR=src
CC=gcc
#CFLAGS=-I$(SDIR)

ODIR=bin

#LIBS=-lm

_DEPS = sort.h
DEPS = $(patsubst %,%,$(_DEPS))

_OBJ = main.o sort.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< 

main: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o main *~