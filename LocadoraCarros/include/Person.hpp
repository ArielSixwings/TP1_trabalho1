#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person{
public:
	int Age;
	std::string CPF;
	std::string Name;
public:
	Person();
	Person(std::string CPF, int Age, std::string Name);
	virtual void ShowInformation();
	virtual int ReturnType();
};

#endif /* PERSON_HPP */