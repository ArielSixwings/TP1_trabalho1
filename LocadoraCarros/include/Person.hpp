#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "members.hpp"

/*!classe pessoa, usada como super classe para funcionarios,clientes e etc*/
class Person : public Members{
public:
	int Age;
	std::string CPF;
	std::string Name;
public:
	Person();
	//!construtor com dados da classe
	Person(std::string CPF, int Age, std::string Name);
	//!metodo virtual para poder mostrar informações de subclasses
	virtual void ShowInformation();
	//!metodo virtual para identificar para qual subclasse um objeto do tipo pessoa foi atribuido
	virtual int ReturnType();
	void getComments() override;
};

std::vector <int> VerifyRegistration(std::vector <Person*> People);
int SearchInList(std::vector <Person*> People, std::string cpf);

#endif /* PERSON_HPP */