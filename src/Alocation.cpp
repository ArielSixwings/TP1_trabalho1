#include <iostream>
#include "Alocation.hpp"

Alocation::Alocation(std::vector <int>  alocationData, std::vector <int>  alocationHour, std::vector <int>  devolutionData, std::vector <int>  devolutionHour){
	this->AlocationData = alocationData;
	this->DevolutionData = devolutionData;
	this->AlocationHour = alocationHour;
	this->DevolutionHour = devolutionHour;
}

// se a alocação for por dia, a data e hora de devolução são inseridas posteriormente
Alocation::Alocation(int which,bool byperiod)
{
	int day, month, year, hour, minutes;
	this->whichvehicle = which;

	std::cout<<"Insira a identificação do cliente: " ;
	std::cin>>this->CustomerId;
	std::cout<<"Insira a identificação da agencia: ";
	std::cin>>this->Agency;
	
	std::cout<<"Insira a o dia da data de alocação: ";
	std::cin>>day;
	this->AlocationData.push_back(day);
	std::cout<<"Insira a o mês da data de alocação: ";
	std::cin>>month;
	this->AlocationData.push_back(month);
	std::cout<<"Insira a o ano da data de alocação: ";
	std::cin>>year;
	this->AlocationData.push_back(year);
	std::cout<<"Insira a hora de alocação: ";
	std::cin>>hour;
	this->AlocationHour.push_back(hour);
	std::cout<<"Insira os minutos de alocação: ";
	std::cin>>minutes;
	this->AlocationHour.push_back(minutes);

	if(byperiod){
		std::cout<<"Insira a o dia da data de devolução: ";
		std::cin>>day;
		this->DevolutionData.push_back(day);
		std::cout<<"Insira a o mês da data de devolução: ";
		std::cin>>month;
		this->DevolutionData.push_back(month);
		std::cout<<"Insira a o ano da data de devolução: ";
		std::cin>>year;
		this->DevolutionData.push_back(year);
		std::cout<<"Insira a hora de devolução: ";
		std::cin>>hour;
		this->DevolutionHour.push_back(hour);
		std::cout<<"Insira os minutos de devolução: ";
		std::cin>>minutes;
		this->DevolutionHour.push_back(minutes);
	}


}

Alocation::~Alocation(){
}

void Alocation::getAlocation(){
	std::cout<<"Data de Alocação: " << AlocationData[0] << "/" << AlocationData[1] << "/" << AlocationData[2] << std::endl;
	std::cout<<"Hora de Alocação: " << AlocationHour[0] << ":" << AlocationHour[1] << std::endl;
	std::cout<<"Data de Devolução: " << DevolutionData[0] << "/" << DevolutionData[1] << "/" << DevolutionData[2] << std::endl;
	std::cout<<"Hora de Devolução: " << DevolutionHour[0] << ":" << DevolutionHour[1] << std::endl;
}