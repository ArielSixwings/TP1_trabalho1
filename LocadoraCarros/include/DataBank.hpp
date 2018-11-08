#ifndef DATABANK_HPP
#define DATABANK_HPP
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sqlite3.h>

typedef enum{
    RETURNOK,
    RETURNERROR
}flags;

class GeneralBank{
public:
	static int callback(void *NotUsed, int argc, char **argv, char **szColName);

	static sqlite3* CreateSchema();

	static void ExitDataBase(flags X, sqlite3* db);

	static void CheckDataBase(int rc);	
};


#endif //DATABANK_HPP