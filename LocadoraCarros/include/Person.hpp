#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

/*!classe pessoa, usada como super classe para funcionarios,clientes e etc*/
class Person{
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
};

#endif /* PERSON_HPP */