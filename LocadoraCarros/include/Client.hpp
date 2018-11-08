#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "DataBank.hpp"
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

class ModelClient{
public:

	static int callback(void *NotUsed, int argc, char **argv, char **szColName);

	static int callbackclient(void* data, int argc, char **argv, char **szColName);

	static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Client* FindClient(std::string Login, sqlite3 *db);

    static Client* GiveClients(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableClient(Client aux, sqlite3 *db);

    static flags DeleteFromTableClient(std::string CPF, sqlite3 *db);

};

#endif /* CLIENT_HPP */