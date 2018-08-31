IDIR =../include
CC=g++ -std=c++17
CFLAGS=-I$(IDIR) -Wpedantic -Wall

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Vehicles.hpp Alocation.hpp Person.hpp Client.hpp Agency.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Vehicles.o Alocation.o Main.o Person.o Client.o Agency.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: Atividade1

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Atividade1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -Wall
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~