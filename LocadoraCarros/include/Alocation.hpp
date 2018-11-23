#ifndef ALOCATION_HPP
#define ALOCATION_HPP
#include "DataBank.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

/*!guarda informações da alocação de um carro, relacionando veiculo, agencia e cliente*/
class Alocation{
public:
	int AlocationId;
	int whichvehicle;
	double days;
	double cost;
	std::vector <int> AlocationData;
	std::vector <int> AlocationHour;
	std::vector <int> DevolutionData;
	std::vector <int> DevolutionHour;
	std::string Type; //!daily or byperiod
	std::string Agency;
	std::string CustomerId;//!CPF
public:
	/*!construtor da classe,recebe informações do veículo, agencia e tipo de alocação 
	e pede as demais informações ao cliente*/
	Alocation(int id, int which,std::string Agency,bool byperiod, std::string cpf, double price);
	//!construtor da classe que já recebe todas as informações sobre a alocação
	Alocation(int id, std::vector <int> alocationData, std::vector <int>  alocationHour,
	 std::vector <int>  devolutionData, std::vector <int>  devolutionHour);
	~Alocation();
	Alocation();
	Alocation(int id);
	//!mostra em tela informações da alocação
	void getAlocation();
	//!retorna o número de dias da alocação
	int howmanydays();
	//!calcula valor total da alocação
	double CalculateCost(double Price, int byperiod);

	std::vector <int> String_to_vecInt(std::string arg, int type);

};

class ModelAlocation{
  public:
	static int callback(void *NotUsed, int argc, char **argv, char **szColName);

	static int callbackalocation(void *data, int argc, char **argv, char **szColName);

	static int callbackcount(void *data, int argc, char **argv, char **szColName);

	static Alocation FindAlocation(int AlocationId, sqlite3 *db);

	static Alocation GiveAlocations(int i, sqlite3 *db);

	static int HowMany(sqlite3 *db);

	static flags InsertIntoTableAlocation(bool type, Alocation aux, sqlite3 *db);

	static flags DeleteFromTableAlocation(int Id, sqlite3 *db);

	static std::vector<Alocation> GetAlocations(sqlite3 *db);
};

#endif /* ALOCATION_HPP */