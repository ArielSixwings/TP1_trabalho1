#include "Person.hpp"
#include <iostream>
#include <string>

Person::Person(std::string CPF, int Age, std::string Name){
	this->CPF = CPF;
	this->Age = Age;
	this->Name = Name;
}

Person::Person(){
	std::cout<<"Insira seu CPF: " << std::endl;
	std::cin >> this->CPF;
	std::cout<<"Insira sua Idade: " << std::endl;
	std::cin>> this->Age;
	std::cout<<"Insira seu Nome: " << std::endl;
	std::cin>>this->Name;
}

void Person::ShowInformation(){
	std::cout<<"CPF: " << this->CPF << std::endl;
	std::cout<<"Idade: " << this->Age << std::endl;
	std::cout<<"Nome: " << this->Name << std::endl;
}

int Person::ReturnType(){
	return 0;
}