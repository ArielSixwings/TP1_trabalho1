#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <iostream>
#include <exception>
#include <string>
#include <map>

const int PLACA   = 1;
const int CHASSI  = 2;
const int RENAVAM = 3;

/*!classe dedicada a verificar entradas e lidar com exeções*/
class ExceptionsInputs{
public:
	int x;
	int y;
	std::string aux;
public:
	//!construtor da classe, atribui valores mínimo e máximo aceitados
	ExceptionsInputs(int a, int b);
	//!verifica se a entrada esta na faixa aceitada, entre a e b
	static int VerifyInputs(int a, int b);
	//!verifica se a uma entrada do tipo string tem exatamente o número de caraacteres desejados
	static std::string VerifyExactInputs(unsigned int a, int which);

	static std::string VerifyAgencyId(std::map<std::string, int> AgencysIdmap);
};

int VerifyTypeInputs();

#endif /* EXCEPTIONS_HPP */