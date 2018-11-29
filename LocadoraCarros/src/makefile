IDIR =../include
CC=g++ -std=c++17
CFLAGS=-I$(IDIR) -Wpedantic -Wall -g -lsqlite3
GCOVFLAGS = -fprofile-arcs -ftest-coverage -lgcov --coverage

ODIR=obj
ODIRTEST=objT
TDIR =../test
LDIR =../lib

LIBS=-lm

_DEPS = Exceptions.hpp Vehicles.hpp Alocation.hpp Person.hpp Client.hpp Agency.hpp Employee.hpp Interface.hpp DataBank.hpp Brand.hpp Model.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Exceptions.o Vehicles.o Alocation.o Person.o Client.o Agency.o Employee.o Interface.o DataBank.o Brand.o Model.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: Atividade1 TEST_Agency TEST_Alocation TEST_Client TEST_Employee TEST_Person TEST_Vehicle

$(ODIR)/%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS) $(GCOVFLAGS)

Atividade1: $(ODIR)/Main.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)


$(ODIRTEST)/%.o: $(TDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

TEST_Agency: $(ODIRTEST)/TEST_Agency.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

TEST_Alocation: $(ODIRTEST)/TEST_Alocation.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

TEST_Client: $(ODIRTEST)/TEST_Client.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

TEST_Employee: $(ODIRTEST)/TEST_Employee.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

TEST_Person: $(ODIRTEST)/TEST_Person.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

TEST_Vehicle: $(ODIRTEST)/TEST_Vehicle.o $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(GCOVFLAGS)

.PHONY: clean

clean:
	rm -f  $(ODIR)/*.o $(ODIR)/*.gcno $(ODIR)/*.gcda $(ODIRTEST)/*.o $(ODIRTEST)/*.gcno $(ODIRTEST)/*.gcda *~ $(IDIR)/*~ main *.o

.PHONY: gcov

gcov: gcov_Agency gcov_Alocation gcov_Client gcov_Employee gcov_Person gcov_Vehicle

gcov_Agency:
	./TEST_Agency
	gcov -abcfu Agency.cpp -o obj > gcov_Agency.txt

gcov_Alocation:
	./TEST_Alocation
	gcov -abcfu Alocation.cpp -o obj > gcov_Alocation.txt

gcov_Client:
	./TEST_Client
	gcov -abcfu Client.cpp -o obj > gcov_Client.txt

gcov_Employee:
	./TEST_Agency
	gcov -abcfu Employee.cpp -o obj > gcov_Employee.txt

gcov_Person:
	./TEST_Person
	gcov -abcfu Person.cpp -o obj > gcov_Person.txt

gcov_Vehicle:
	./TEST_Agency
	gcov -abcfu Vehicles.cpp -o obj > gcov_Vehicles.txt

.PHONY: clean_gcov

clean_gcov:
	rm -f *.gcno *.gcov