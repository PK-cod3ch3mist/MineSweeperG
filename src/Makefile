IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

ODIR = ../obj
BDIR = ../bin

_DEPS = game.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o game.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/minegui : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean :
	rm -f core minegui $(ODIR)/*.o
