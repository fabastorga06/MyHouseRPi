IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc

EXEC = MyHouse

_DEPS = libmanager.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(EXEC).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: main.c $(DEPS)
	$(CC) -c -o $@ $< 

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(EXEC)