#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <iostream>
#include <exception>
#include <string>

class ExceptionsInputs{
public:
	int x;
	int y;
public:
	ExceptionsInputs(int a, int b);
	static int VerifyInputs(int a, int b);
};

int VerifyTypeInputs();

#endif /* EXCEPTIONS_HPP */