#include <iostream>
#include <string>
#include "Client.hpp"

Client::Client(int CPF,std::string Name, std::string CustomerLogin, std::string CustomerPassword){
	this->CPF = CPF;
	this->Name = Name;
	this->CustomerLogin = CustomerLogin;
	this->CustomerPassword = CustomerPassword;
}

void Client::ShowInformation(){
	std::cout<<"Identificador do cliente: " << this->CPF << std::endl;
	std::cout<<"Login do Cliente: " << this->CustomerLogin << std::endl;
	std::cout<<"Senha do Cliente: " << this->CustomerPassword << std::endl;
}