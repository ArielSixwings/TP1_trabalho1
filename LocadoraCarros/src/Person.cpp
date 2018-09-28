#include "Person.hpp"
#include <iostream>
#include <string>

Person::Person(std::string CPF, int Age, std::string Name){
	this->CPF = CPF;
	this->Age = Age;
	this->Name = Name;
}

Person::Person(){
	std::cout<<"CPF: ";
	std::cin >> this->CPF;
	std::cout<<"Idade: ";
	std::cin>> this->Age;
	std::cout<<"Nome: ";
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