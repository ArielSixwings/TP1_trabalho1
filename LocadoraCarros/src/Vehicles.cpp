#include <iostream>
#include <string>
#include "Vehicles.hpp"

Vehicle::Vehicle(int key, std::string board, std::string color, std::string typefuel, 
	std::string chassi, int year, int howmanydoors, int distance, int RENAVAM){
	this->Alocated = false;
	this->Key = key;
	this->Board = board;
	this->Color = color;
	this->TypeFuel = typefuel;
	this->Chassi = chassi;
	this->Year = year;
	this->Howmanydoors = howmanydoors;
	this->Distance = distance;
	this->RENAVAM = RENAVAM;
}

Vehicle::Vehicle(int i){
	this->Alocated = false;
	this->Key = i;
	std::cout<<"Veículo " << i << std::endl;
	std::cout<<"Placa: ";
	std::cin>>this->Board;
	std::cout<<"Cor: ";
	std::cin>>this->Color;
	std::cout<<"Tipo de Combustível: ";
	std::cin>>this->TypeFuel;
	std::cout<<"Chassi: ";
	std::cin>>this->Chassi;
	std::cout<<"Ano de Fabricação: ";
	std::cin>>this->Year;
	std::cout<<"Número de Portas: ";
	std::cin>>this->Howmanydoors;
	std::cout<<"Quilometragem: ";
	std::cin>>this->Distance;
	std::cout<<"RENAVAM: ";
	std::cin>>this->RENAVAM;
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
	std::cout<<"RENAVAM: " << RENAVAM << std::endl;
	std::cout << std::endl;
}
