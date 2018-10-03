#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "Alocation.hpp"
#include <string>
#include <vector>

/*!classe veiculo, possui todas as informações relevantes para a agencia e para o cliente para 
	realizar uma alocação*/
class Vehicle{
public:
	int Key;
	int AlocationPrice;
	bool Alocated;
	std::string renavam;
	std::string Board;
	std::string Color;
	std::string TypeFuel;
	std::string Chassi;
	std::string Model;
	std::string Brand;
	int Year;
	int Howmanydoors;
	double Distance;
	double Priceperday;
	double Priceperperiod;
public:
	/*!construtor da classe,recebe como parametro a chave do veículo no array de veículos da agencia 
		e recebe do terminal as demais informações*/
	Vehicle(int i, std::vector <std::string> Brands, std::vector <std::vector <std::string>> Models);
	//!construtor da classe, recebe como parametro todas as informações do veiculo
	Vehicle(int key, std::string board, std::string color, std::string typefuel, 
		std::string chassi, int year, int howmanydoors, double distance, 
		std::string RENAVAM,std::string MODEL, std::string BRAND, double Priceperday, double Priceperperiod);
	//!retorna um objeto do tipo alocação e recebe como parametro arrays com as informações de alocação e devolução
	Alocation Alocate(std::vector <int> AlocationData, std::vector <int> AlocationHour, 
						std::vector <int> DevolutionData, std::vector <int> DevolutionHour);
	//!mostra em tela informações do veículo
	void getVehicle();
};

void ShowBrands(std::vector <std::string> Brands);

void ShowModels(std::string Brand, std::vector <std::vector <std::string>> Models);

#endif /* VEHICLE_HPP */