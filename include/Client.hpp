#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "Person.hpp"
#include <string>

class Client : public Person{
public:
	int PurchaseKey;
	std::string CustomerLogin;
	std::string CustomerPassword;
public:
	Client(int PurchaseKey, std::string CustomerLogin, std::string CustomerPassword);
	void ShowInformation();
};

#endif /* CLIENT_HPP */