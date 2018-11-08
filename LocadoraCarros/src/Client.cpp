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

// ########################################################################################## //

int ModelClient::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelClient::callbackclient(void *data, int argc, char **argv, char **szColName){

  Client* aux = static_cast<Client*>(data);
  aux->CPF = argv[0];
  aux->Name =  argv[1];
  aux->Age = atoi(argv[2]);
  aux->CustomerLogin = argv[3];
  aux->CustomerPassword = argv[4];

  return 0;
}

int ModelClient::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}

Client* ModelClient::GiveClients(int i, sqlite3 *db){
  Client* aux = new Client("0", "0", 0, "0", "0");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Client WHERE rowid = " + std::to_string(i+1));
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackclient, aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return nullptr;
    }
    return aux;
}

int ModelClient::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(CPF) FROM Client");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Client* ModelClient::FindClient(std::string Login, sqlite3 *db){
  Client* aux = new Client("0", "0", 0, "0", "0");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Client WHERE CustomerLogin = '" + Login + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackclient, aux, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return nullptr;
  }
  return aux;
}

flags ModelClient::InsertIntoTableClient(Client aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Client(CPF, Name, Age, CustomerLogin, CustomerPassword) VALUES ('"
  + aux.CPF + "', '" + aux.Name + "', " + std::to_string(aux.Age) + ", '" + aux.CustomerLogin + "', '" 
  + aux.CustomerPassword + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelClient::DeleteFromTableClient(std::string CPF, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Client WHERE CPF = '" + CPF + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}