#ifndef Model_HPP
#define Model_HPP
#include <iostream>
#include <string>
#include "DataBank.hpp"
#include "Brand.hpp"
#include <iostream>
#include <string>


class Model{
public:
    int ModelId;
    std::string Name; 
    std::string BrandName;   
public:
    
    Model();

    Model(int i, std::vector<Brand> Brands);

    Model(int modelId, std::string name, std::string brandname);

    void getModel();

    void setModel(int modelId, std::string name, std::string brandname);
    


};

class ModelModel{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackmodel(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Model FindModel(int Id, sqlite3 *db);

    static Model GiveModels(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableModel(Model aux, sqlite3 *db);

    static flags DeleteFromTableModel(int ModelId, sqlite3 *db);

    static std::vector<Model> GetModels(sqlite3 *db);

    static int FindFromName(std::string name, sqlite3 *db);
};

#endif //Model_HPP