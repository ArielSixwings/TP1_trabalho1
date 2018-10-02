#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "Person.hpp"
#include <string>

/*!subclasse de pessoa, possui também informações de login de senha*/
class Client : public Person{
public:
	std::string CustomerLogin;
	std::string CustomerPassword;
	//!auxiliar, chamada pelo construtor para atribuir login e senha
	void SetClient(std::string CustomerLogin, std::string CustomerPassword);
public:
	using Person::Person;
	//!construtor da classe, recebe informações para chamada do construtor da classe pessoa também
	Client(std::string CPF,std::string Name, int Age, std::string CustomerLogin, std::string CustomerPassword);
	//!construtor da classe que recebe informações do terminal
	Client();
	//!mostra em tela informações do cliente
	void ShowInformation() override;
	//!retorna o tipo da subclasse de pessoa, nesse caso, 1 para cliente
	int ReturnType() override;
};

#endif /* CLIENT_HPP */