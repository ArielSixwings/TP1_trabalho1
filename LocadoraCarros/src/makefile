IDIR =../include
CC=g++ -std=c++17
CFLAGS=-I$(IDIR) -Wpedantic -Wall -g -lsqlite3

ODIR=obj
TDIR =../test
LDIR =../lib

LIBS=-lm

_DEPS = Vehicles.hpp Alocation.hpp Person.hpp Client.hpp Agency.hpp Employee.hpp Exceptions.hpp Interface.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Vehicles.o Alocation.o Main.o Person.o Client.o Agency.o Employee.o Exceptions.o Interface.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = Agency.o TEST_Agency.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

all: TEST_Agency Atividade1

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Atividade1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(TDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

TEST_Agency: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~