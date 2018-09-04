#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person{
public:
	int CPF;
	int Age;
	std::string Name;
public:
	Person();
	Person(int CPF, int Age, std::string Name);
	void ShowInformation();
};

#endif /* PERSON_HPP */