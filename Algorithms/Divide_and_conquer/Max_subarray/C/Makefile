
#SDIR=src
CC=gcc
#CFLAGS=-I$(SDIR)

ODIR=bin

#LIBS=-lm

_DEPS = max_subarray.h
DEPS = $(patsubst %,%,$(_DEPS))

_OBJ = main.o max_subarray.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< 

main: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o main *~