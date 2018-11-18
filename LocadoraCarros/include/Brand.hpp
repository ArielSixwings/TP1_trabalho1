#ifndef BRAND_HPP
#define BRAND_HPP
#include <iostream>
#include <string>
#include "DataBank.hpp"
#include <iostream>
#include <string>


class Brand{
public:
    std::string Name;    
    int NumberOfModels;
public:
    
    Brand();

    Brand(std::string name, int numberOfModels);
    
    void getBrand();

    void setBrand(std::string name, int numberOfModels);
    


};

class ModelBrand{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackbrand(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Brand FindBrand(std::string Id, sqlite3 *db);

    static Brand GiveBrands(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableBrand(Brand aux, sqlite3 *db);

    static flags DeleteFromTableBrand(std::string Name, sqlite3 *db);

};

#endif //BRAND_HPP