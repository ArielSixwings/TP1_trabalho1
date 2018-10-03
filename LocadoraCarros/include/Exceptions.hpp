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

	static std::string VerifyAgencyId(std::map<std::string, int> AgencysIdmap);

	static std::string VerifyCPF(std::vector <Person*> People);

	static std::string VerifyBoardLettersInputs(std::string word);

	static std::string VerifyBoardNumbersInputs(std::string word);

	static std::string VerifyOnlyNumbersInputs(std::string word);
};

int VerifyTypeInputs();

#endif /* EXCEPTIONS_HPP */