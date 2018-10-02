#ifndef ALOCATION_HPP
#define ALOCATION_HPP
#include "Person.hpp"
#include <vector>
#include <string>
#include <ctime>

/*!guarda informações da alocação de um carro, relacionando veiculo, agencia e cliente*/
class Alocation{
public:
	int whichvehicle;
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
	Alocation(int which,std::string Agency,bool byperiod, std::vector <Person*> People);
	//!construtor da classe que já recebe todas as informações sobre a alocação
	Alocation(std::vector <int> alocationData, std::vector <int>  alocationHour,
	 std::vector <int>  devolutionData, std::vector <int>  devolutionHour);
	~Alocation();
	//!mostra em tela informações da alocação
	void getAlocation();
	//!retorna o número de dias da alocação
	int howmanydays();
};

#endif /* ALOCATION_HPP */