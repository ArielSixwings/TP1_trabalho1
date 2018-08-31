#include <iostream>
#include <string>
#include "Client.hpp"

Client::Client(int CustomerId, std::string CustomerLogin, std::string CustomerPassword){
	this->CustomerId = CustomerId;
	this->CustomerLogin = CustomerLogin;
	this->CustomerPassword = CustomerPassword;
}

void Client::ShowInformation(){
	std::cout<<"Identificador do cliente: " << this->CustomerId << std::endl;
	std::cout<<"Login do Cliente: " << this->CustomerLogin << std::endl;
	std::cout<<"Senha do Cliente: " << this->CustomerPassword << std::endl;
}