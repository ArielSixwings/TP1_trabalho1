#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include "Person.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <map>

const int PLACA   = 1;
const int CHASSI  = 2;
const int RENAVAM = 3;
const int cpf = 4;

/*!classe dedicada a verificar entradas e lidar com exeções*/
class ExceptionsInputs{
public:
	std::string aux;
	int x;
	int y;
public:
	//!construtor da classe, atribui valores mínimo e máximo aceitados
	ExceptionsInputs(int a, int b);
	ExceptionsInputs(std::string AUX);
	//!verifica se a entrada esta na faixa aceitada, entre a e b
	static int VerifyInputs(int a, int b);
	//!verifica se a uma entrada do tipo string tem exatamente o número de caraacteres desejados
	static std::string VerifyExactInputs(unsigned int a, int which);
	//!verifica se o identificador da agencia é valido(esta no array de agencias)
	static std::string VerifyAgencyId(std::map<std::string, int> AgencysIdmap);
	//!verifica se o CPF esta cadastrado
	static std::string VerifyCPF(std::vector <Person*> People);
	//!Verifica se a placa foi escrita em um formato correto, numero certo de letras e etc
	static void VerifyBoardInputs(std::string word, unsigned int a);
	//!Verifica se a entrada recebida são numeros
	static std::string VerifyOnlyNumbersInputs(std::string word);
	//!verifica se a marca esta na lista de marcas
	static std::string VerifyBrandsInputs(std::vector <std::string> Brands);
	//!verifica se o veiculo escolhido pertence à marca
	static std::string VerifyModelsInputs(std::string Brand, std::vector <std::vector <std::string>> Models);
};

int VerifyTypeInputs();

#endif /* EXCEPTIONS_HPP */