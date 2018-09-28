#include <iostream>
#include <string>
#include "Client.hpp"

void Client::SetClient(std::string CustomerLogin, std::string CustomerPassword){
	this->CustomerLogin = CustomerLogin;
	this->CustomerPassword = CustomerPassword;
}

Client::Client(std::string CPF,std::string Name, int Age, std::string CustomerLogin, std::string CustomerPassword)
	: Person(CPF, Age, Name){
	SetClient(CustomerLogin, CustomerPassword);
}

void Client::ShowInformation(){
	std::cout<<"Cliente" << std::endl;
	Person::ShowInformation();
	std::cout<<"Login do Cliente: " << this->CustomerLogin << std::endl;
	std::cout<<"Senha do Cliente: " << this->CustomerPassword << std::endl;
}

int Client::ReturnType(){
	return 1;
}

Client::Client(){
	std::cout<<"Login de Cliente: ";
	std::cin>>this->CustomerLogin;
	std::cout<<"Senha de Cliente: ";
	std::cin>>this->CustomerPassword;
}