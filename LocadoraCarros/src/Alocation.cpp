#include "Alocation.hpp"
#include "Vehicles.hpp"
#include "Exceptions.hpp"

Alocation::Alocation(std::vector <int>  alocationData, std::vector <int>  alocationHour, std::vector <int>  devolutionData, std::vector <int>  devolutionHour){
	this->AlocationData = alocationData;
	this->DevolutionData = devolutionData;
	this->AlocationHour = alocationHour;
	this->DevolutionHour = devolutionHour;
}

// se a alocação for por dia, a data e hora de devolução são inseridas posteriormente
Alocation::Alocation(int which,std::string Agency,bool byperiod, std::string cpf, double price){
	int day, month, year, hour, minutes;
	whichvehicle = which;
	this->Agency = Agency;
	this->cost = price;

	CustomerId = cpf;
	std::cout<<"Insira a o dia da data de alocação: ";
	day = VerifyTypeInputs();
	AlocationData.push_back(day);
	std::cout<<"Insira a o mês da data de alocação: ";
	month = VerifyTypeInputs();
	AlocationData.push_back(month);
	std::cout<<"Insira a o ano da data de alocação: ";
	year = VerifyTypeInputs();
	AlocationData.push_back(year);
	std::cout<<"Insira a hora de alocação: ";
	hour = VerifyTypeInputs();
	AlocationHour.push_back(hour);
	std::cout<<"Insira os minutos de alocação: ";
	minutes = VerifyTypeInputs();
	AlocationHour.push_back(minutes);

	if(byperiod){
		Type = "byperiod";

		std::cout<<"Insira a o dia da data de devolução: ";
		day = VerifyTypeInputs();
		DevolutionData.push_back(day);
		std::cout<<"Insira a o mês da data de devolução: ";
		month = VerifyTypeInputs();
		DevolutionData.push_back(month);
		std::cout<<"Insira a o ano da data de devolução: ";
		year = VerifyTypeInputs();
		DevolutionData.push_back(year);
		std::cout<<"Insira a hora de devolução: ";
		hour = VerifyTypeInputs();
		DevolutionHour.push_back(hour);
		std::cout<<"Insira os minutos de devolução: ";
		minutes = VerifyTypeInputs();
		DevolutionHour.push_back(minutes);
		std::cout<<"Valor Total: " << (double)CalculateCost(price, 1)  << " reais" << std::endl;
	}
	else{
		Type = "daily";
		std::cout<<"Insira a quantidade de dias que se pretende alugar o veículo: ";
		days = VerifyTypeInputs();
		std::cout<<"Valor Total: " << (double)CalculateCost(price, 0) << " reais" << std::endl;
	}


}

Alocation::~Alocation(){
}

void Alocation::getAlocation(){
	std::cout << std::endl;
	std::cout<<"Chave do Veículo: " << whichvehicle << std::endl;
	std::cout<<"CPF do cliente: " << CustomerId << std::endl;
	std::cout<<"Data de Alocação: " << AlocationData[0] << "/" << AlocationData[1] << "/" << AlocationData[2] << std::endl;
	std::cout<<"Hora de Alocação: " << AlocationHour[0] << ":" << AlocationHour[1] << std::endl;

	if(Type.compare(0,5,"daily") == 0){
		std::cout<<"Carro alugado por diária"<<std::endl;
		std::cout<<days<<" Dias"<<std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(cost, 0) << " reais" << std::endl;
	}
	else{
		std::cout<<"Data de Devolução: " << DevolutionData[0] << "/" << DevolutionData[1] << "/" << DevolutionData[2] << std::endl;
		std::cout<<"Hora de Devolução: " << DevolutionHour[0] << ":" << DevolutionHour[1] << std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(cost, 1)  << " reais" << std::endl;
	}
}

double Alocation::CalculateCost(double Price, int byperiod){
	if(byperiod){
		return howmanydays() * Price;
	}
	else{
		return days * Price;
	}
}

int Alocation::howmanydays(){
	struct std::tm timeAlocation = {0,0,0,AlocationData[0],
	(AlocationData[1]-1),(AlocationData[2] - 1900)}; /* 000 is 1900 */
	struct std::tm timeDevolution = {0,0,0,DevolutionData[0],
	(DevolutionData[1]-1),(DevolutionData[2] - 1900)};
	    
	std::time_t x = std::mktime(&timeAlocation);
	std::time_t y = std::mktime(&timeDevolution);
	double difference;
	if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) ){
	    difference = std::difftime(y, x) / (60 * 60 * 24);
	}
	return difference;
}

std::vector <Alocation> RemoveAlocation(std::vector <Alocation> array){
	int carkey, i;
	std::cout<<"Insira a chave do veículo que deseja-se ser liberado: ";
	carkey = VerifyTypeInputs();
	for(i = 0; i < (int)array.size(); i++){
		if(carkey == array[i].whichvehicle){
			array.erase(array.begin() + i);
			break;;
		}
	}
	return array;
}