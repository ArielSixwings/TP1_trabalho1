#ifndef VEHICLES_HPP
#define VEHICLES_HPP
#include "DataBank.hpp"
#include "Brand.hpp"
#include "Model.hpp"
#include <string>
#include <vector>

/*!classe veiculo, possui todas as informações relevantes para a agencia e para o cliente para 
	realizar uma alocação*/
class Vehicle{
public:
	int Key;
	bool Alocated;
	std::string renavam;
	std::string Board;
	std::string Color;
	std::string TypeFuel;
	std::string Chassi;
	int Year;
	int Howmanydoors;
	double Priceperday;
	double Priceperperiod;
	double Distance;
	std::string model;
	std::string brand;
public:
	/*!construtor da classe,recebe como parametro a chave do veículo no array de veículos da agencia 
		e recebe do terminal as demais informações*/
	Vehicle(int i, std::vector <Brand> Brands, std::vector <Model> Models);
	//!construtor da classe, recebe como parametro todas as informações do veiculo
	Vehicle(int key, std::string board, std::string color, std::string typefuel, 
		std::string chassi, int year, int howmanydoors, double distance, 
		std::string RENAVAM,std::string MODEL, std::string BRAND, double Priceperday, double Priceperperiod);
	//!mostra em tela informações do veículo
	void getVehicle();
};
//!mostra em tela as marcas disponiveis
void ShowBrands(std::vector <Brand> Brands);
//!mostra em tela os modelos disponiveis
void ShowModels(std::string Brand, std::vector <Model> Models);

class ModelVehicle{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackvehicle(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Vehicle FindVehicle(int Key, sqlite3 *db);

    static Vehicle GiveVehicles(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableVehicle(Vehicle aux, sqlite3 *db);

    static flags DeleteFromTableVehicle(int Key, sqlite3 *db);

	static flags UpdateFromTableVehicle(int Key, sqlite3 *db);

	static std::vector<Vehicle> GetVehicles(sqlite3 *db);

	static int FindBoard(std::string board, sqlite3 *db);
};

#endif /* VEHICLE_HPP */