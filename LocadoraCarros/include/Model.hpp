#ifndef Model_HPP
#define Model_HPP
#include <iostream>
#include <string>
#include "DataBank.hpp"
#include <iostream>
#include <string>


class Model{
public:
    std::string ModelId;
    std::string Name; 
    std::string BrandName;   
public:
    
    Model();

    Model(std::string modelId, std::string name, std::string brandname);
    
    void getModel();

    void setModel(std::string modelId, std::string name, std::string brandname);
    


};

class ModelModel{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackmodel(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Model FindModel(std::string Id, sqlite3 *db);

    static Model GiveModels(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableModel(Model aux, sqlite3 *db);

    static flags DeleteFromTableModel(std::string ModelId, sqlite3 *db);

};

#endif //Model_HPP