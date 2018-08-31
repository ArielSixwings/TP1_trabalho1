#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "Person.hpp"
#include <string>

class Client : public Person{
public:
	std::string CustomerLogin;
	std::string CustomerPassword;
public:
	Client(int CPF,std::string Name, std::string CustomerLogin, std::string CustomerPassword);
	void ShowInformation();
};

#endif /* CLIENT_HPP */