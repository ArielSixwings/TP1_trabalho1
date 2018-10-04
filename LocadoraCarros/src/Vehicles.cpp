#include <iostream>
#include <string>
#include "Vehicles.hpp"
#include "Exceptions.hpp"

Vehicle::Vehicle(int key, std::string board, std::string color,std::string typefuel, 
	std::string chassi, int year, int howmanydoors, double distance, 
	std::string Renavam, std::string MODEL, std::string BRAND, double Priceperday, double Priceperperiod)
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
	this->Model = MODEL;
	this->Brand = BRAND;
	this->Priceperday = Priceperday;
	this->Priceperperiod = Priceperperiod;
}

Vehicle::Vehicle(int i, std::vector <std::string> Brands, std::vector <std::vector <std::string>> Models){
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
	ShowBrands(Brands);
	std::cout<<"Marca: ";
	this->Brand = ExceptionsInputs::VerifyBrandsInputs(Brands);
	ShowModels(this->Brand, Models);
	std::cout<<"Modelo: ";
	this->Model = ExceptionsInputs::VerifyModelsInputs(this->Brand, Models);
	std::cout<<"Preço de alocação por dia: ";
	std::cin>>this->Priceperday;
	std::cout<<"Preço de alocação por período: ";
	std::cin>>this->Priceperperiod;
	std::cout << std::endl;
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
	std::cout<<"Marca: " << this->Brand << std::endl;
	std::cout<<"Modelo: " << this->Model << std::endl;
	std::cout<<"Preço de alocação por dia: "<< Priceperday << std::endl;
	std::cout<<"Preço de alocação por período: "<< Priceperperiod << std::endl;
	std::cout << std::endl;
}

void ShowBrands(std::vector <std::string> Brands){
	std::cout << std::endl;
	std::cout<<"Marcas Disponíveis: " << std::endl;
	for(auto c : Brands){
		std::cout<<c << std::endl;
	}
}

void ShowModels(std::string Brand, std::vector <std::vector <std::string>> Models){
	std::cout << std::endl;
	if(Brand == "Chevrolet"){
		std::cout<<"Modelos disponíveis da Marca Chevrolet" << std::endl;
		std::cout<<Models[0][0] << std::endl;
		std::cout<<Models[0][1] << std::endl;
		std::cout<<Models[0][2] << std::endl;
	}
	if(Brand == "BMW"){
		std::cout<<"Modelos disponíveis da Marca BMW" << std::endl;
		std::cout<<Models[1][0] << std::endl;
		std::cout<<Models[1][1] << std::endl;
		std::cout<<Models[1][2] << std::endl;
	}
	if(Brand == "Ford"){
		std::cout<<"Modelos disponíveis da Marca Ford" << std::endl;
		std::cout<<Models[2][0] << std::endl;
		std::cout<<Models[2][1] << std::endl;
		std::cout<<Models[2][2] << std::endl;
	}
	if(Brand == "Tesla"){
		std::cout<<"Modelos disponíveis da Marca Tesla" << std::endl;
		std::cout<<Models[3][0] << std::endl;
		std::cout<<Models[3][1] << std::endl;
		std::cout<<Models[3][2] << std::endl;
	}
}
