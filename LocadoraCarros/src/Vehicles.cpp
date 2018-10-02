#include <iostream>
#include <string>
#include "Vehicles.hpp"
#include "Exceptions.hpp"

Vehicle::Vehicle(int key, std::string board, std::string color,std::string typefuel, 
	std::string chassi, int year, int howmanydoors, double distance, 
	std::string Renavam, double Priceperday, double Priceperperiod)
{
	this->Alocated = false;
	this->Key = key;
	this->Board = board;
	this->Color = color;
	this->TypeFuel = typefuel;
	this->Chassi = chassi;
	this->Year = year;
	this->Howmanydoors = howmanydoors;
	this->Distance = distance;
	this->renavam = Renavam;
	this->Priceperday = Priceperday;
	this->Priceperperiod = Priceperperiod;
}

Vehicle::Vehicle(int i){
	this->Alocated = false;
	this->Key = i;
	std::cout<<"Veículo " << i << std::endl;
	std::cout<<"Placa: ";
	this->Board = ExceptionsInputs::VerifyExactInputs(7, PLACA);
	std::cout<<"Cor: ";
	std::cin>>this->Color;
	std::cout<<"Tipo de Combustível: ";
	std::cin>>this->TypeFuel;
	std::cout<<"Chassi: ";
	this->Chassi = ExceptionsInputs::VerifyExactInputs(17, CHASSI);
	std::cout<<"Ano de Fabricação: ";
	this->Year = VerifyTypeInputs();
	std::cout<<"Número de Portas: ";
	this->Howmanydoors = VerifyTypeInputs();
	std::cout<<"Quilometragem: ";
	this->Distance = VerifyTypeInputs();
	std::cout<<"RENAVAM: ";
	this->renavam = ExceptionsInputs::VerifyExactInputs(11, RENAVAM);
	std::cout<<"Preço de alocação por dia: ";
	std::cin>>this->Priceperday;
	std::cout<<"Preço de alocação por período: ";
	std::cin>>this->Priceperperiod;
	std::cout << std::endl;
}

Alocation Vehicle::Alocate(std::vector <int> AlocationData, std::vector <int> AlocationHour, std::vector <int> DevolutionData, std::vector <int> DevolutionHour){
	Alocated = true;
	Alocation aux(AlocationData, AlocationHour, DevolutionData, DevolutionHour);
	return aux;
}

void Vehicle::getVehicle(){
	std::cout<<"Chave do Veículo: " << Key << std::endl;
	std::cout<<"Está alocado: " << Alocated << std::endl;
	std::cout<<"Placa: " << Board << std::endl;
	std::cout<<"Cor: " << Color << std::endl;
	std::cout<<"Tipo de Combustível: " << TypeFuel << std::endl;
	std::cout<<"Chassi: " << Chassi << std::endl;
	std::cout<<"Ano de Fabricação: " << Year << std::endl;
	std::cout<<"Número de Portas: " << Howmanydoors << std::endl;
	std::cout<<"Quilometragem: " << Distance << std::endl;
	std::cout<<"RENAVAM: " << this->renavam << std::endl;
	std::cout<<"Preço de alocação por dia: "<< Priceperday << std::endl;
	std::cout<<"Preço de alocação por período: "<< Priceperperiod << std::endl;
	std::cout << std::endl;
}
