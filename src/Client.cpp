#include <iostream>
#include <string>
#include "Client.hpp"

Client::Client(int PurchaseKey, std::string CustomerLogin, std::string CustomerPassword){
	this->PurchaseKey = PurchaseKey;
	this->CustomerLogin = CustomerLogin;
	this->CustomerPassword = CustomerPassword;
}

void Client::ShowInformation(){
	std::cout<<"Valor de Compra: " << this->PurchaseKey << std::endl;
	std::cout<<"Login do Cliente: " << this->CustomerLogin << std::endl;
	std::cout<<"Senha do Cliente: " << this->CustomerPassword << std::endl;
}