IDIR =../include
CC=g++ -std=c++17
CFLAGS=-I$(IDIR) -Wpedantic -Wall -g -lsqlite3

ODIR=obj
TDIR =../test
LDIR =../lib

LIBS=-lm

_DEPS = Vehicles.hpp Alocation.hpp Person.hpp Client.hpp Agency.hpp Employee.hpp Exceptions.hpp Interface.hpp DataBank.hpp Brand.hpp Model.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Vehicles.o Alocation.o Main.o Person.o Client.o Agency.o Employee.o Exceptions.o Interface.o DataBank.o Brand.o Model.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJAgengy = Agency.o TEST_Agency.o
OBJAgengy = $(patsubst %,$(ODIR)/%,$(_OBJAgengy))

_OBJAlocation = Alocation.o TEST_Alocation.o
OBJAlocation = $(patsubst %,$(ODIR)/%,$(_OBJAlocation))

_OBJClient = Client.o TEST_Client.o
OBJClient = $(patsubst %,$(ODIR)/%,$(_OBJClient))

_OBJEmployee = Employee.o TEST_Employee.o
OBJEmployee = $(patsubst %,$(ODIR)/%,$(_OBJEmployee))

_OBJPerson = Person.o TEST_Person.o
OBJPerson = $(patsubst %,$(ODIR)/%,$(_OBJPerson))

_OBJVehicle = Vehicle.o TEST_Vehicle.o
OBJVehicle = $(patsubst %,$(ODIR)/%,$(_OBJVehicle))

all: TEST_Agency Atividade1

$(ODIR)/%.o: ./%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Atividade1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(TDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

TEST_Agency: $(OBJAgengy)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

TEST_Alocation: $(OBJAlocation)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

TEST_Client: $(OBJClient)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

TEST_Employee: $(OBJEmployee)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

TEST_Person: $(OBJPerson)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

TEST_Vehicle: $(OBJVehicle)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~