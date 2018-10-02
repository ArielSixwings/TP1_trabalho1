#include <iostream>
#include "Alocation.hpp"
#include "Exceptions.hpp"

Alocation::Alocation(std::vector <int>  alocationData, std::vector <int>  alocationHour, std::vector <int>  devolutionData, std::vector <int>  devolutionHour){
	this->AlocationData = alocationData;
	this->DevolutionData = devolutionData;
	this->AlocationHour = alocationHour;
	this->DevolutionHour = devolutionHour;
}

// se a alocação for por dia, a data e hora de devolução são inseridas posteriormente
Alocation::Alocation(int which,std::string Agency,bool byperiod, std::vector <Person*> People)
{
	int day, month, year, hour, minutes;
	whichvehicle = which;
	this->Agency = Agency;

	std::cout<<"Insira a identificação do cliente(CPF): " ;
	CustomerId = ExceptionsInputs::VerifyCPF(People);
	std::cout<<"Insira a o dia da data de alocação: ";
	std::cin>>day;
	AlocationData.push_back(day);
	std::cout<<"Insira a o mês da data de alocação: ";
	std::cin>>month;
	AlocationData.push_back(month);
	std::cout<<"Insira a o ano da data de alocação: ";
	std::cin>>year;
	AlocationData.push_back(year);
	std::cout<<"Insira a hora de alocação: ";
	std::cin>>hour;
	AlocationHour.push_back(hour);
	std::cout<<"Insira os minutos de alocação: ";
	std::cin>>minutes;
	AlocationHour.push_back(minutes);

	if(byperiod){
		Type = "byperiod";

		std::cout<<"Insira a o dia da data de devolução: ";
		std::cin>>day;
		DevolutionData.push_back(day);
		std::cout<<"Insira a o mês da data de devolução: ";
		std::cin>>month;
		DevolutionData.push_back(month);
		std::cout<<"Insira a o ano da data de devolução: ";
		std::cin>>year;
		DevolutionData.push_back(year);
		std::cout<<"Insira a hora de devolução: ";
		std::cin>>hour;
		DevolutionHour.push_back(hour);
		std::cout<<"Insira os minutos de devolução: ";
		std::cin>>minutes;
		DevolutionHour.push_back(minutes);
	}
	else{
		Type = "daily";
	}


}

Alocation::~Alocation(){
}

void Alocation::getAlocation(){
	std::cout << std::endl;
	std::cout<<"Chave do Veículo: " << whichvehicle << std::endl;
	std::cout<<"Data de Alocação: " << AlocationData[0] << "/" << AlocationData[1] << "/" << AlocationData[2] << std::endl;
	std::cout<<"Hora de Alocação: " << AlocationHour[0] << ":" << AlocationHour[1] << std::endl;

	if(Type.compare(0,5,"daily") == 0){
		std::cout<<"Carro alugado por diária"<<std::endl;
	}
	else{
		std::cout<<"Data de Devolução: " << DevolutionData[0] << "/" << DevolutionData[1] << "/" << DevolutionData[2] << std::endl;
		std::cout<<"Hora de Devolução: " << DevolutionHour[0] << ":" << DevolutionHour[1] << std::endl;
	}

}

int Alocation::howmanydays()
{
    struct std::tm timeAlocation = {0,0,0,AlocationData[0],
		(AlocationData[1]-1),(AlocationData[2] - 1900)}; /* 000 is 1900 */
    struct std::tm timeDevolution = {0,0,0,DevolutionData[0],
		(DevolutionData[1]-1),(DevolutionData[2] - 1900)};
    
	std::time_t x = std::mktime(&timeAlocation);
    std::time_t y = std::mktime(&timeDevolution);
    double difference;
	if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        difference = std::difftime(y, x) / (60 * 60 * 24);
    }
	return difference;
}