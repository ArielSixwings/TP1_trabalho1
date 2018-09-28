#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "Person.hpp"
#include <string>

class Client : public Person{
public:
	std::string CustomerLogin;
	std::string CustomerPassword;
public:
	using Person::Person;
	Client(std::string CPF,std::string Name, int Age, std::string CustomerLogin, std::string CustomerPassword);
	Client();
	void SetClient(std::string CustomerLogin, std::string CustomerPassword);
	void ShowInformation() override;
	int ReturnType() override;
};

#endif /* CLIENT_HPP */