#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <iostream>
#include <exception>
#include <string>

const int PLACA   = 1;
const int CHASSI  = 2;
const int RENAVAM = 3;

class ExceptionsInputs{
public:
	int x;
	int y;
	std::string aux;
public:
	ExceptionsInputs(int a, int b);
	static int VerifyInputs(int a, int b);
	static std::string VerifyExactInputs(unsigned int a, int which);
};

int VerifyTypeInputs();

#endif /* EXCEPTIONS_HPP */