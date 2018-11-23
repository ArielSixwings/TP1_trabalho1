#include "Person.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "Exceptions.hpp"

Person::Person(std::string CPF, int Age, std::string Name){
	this->CPF = CPF;
	this->Age = Age;
	this->Name = Name;
}

Person::Person(){
	std::cout<<"CPF: ";
	this->CPF = ExceptionsInputs::VerifyExactInputs(11, cpf);
	std::cout<<"Idade: ";
	std::cin>> this->Age;
	std::cout<<"Nome: ";
	std::cin>>this->Name;
}

void Person::ShowInformation(){
	std::cout<<"CPF: " << this->CPF << std::endl;
	std::cout<<"Idade: " << this->Age << std::endl;
	std::cout<<"Nome: " << this->Name << std::endl;
}

int Person::ReturnType(){
	return 0;
}

std::vector <int> VerifyRegistration(std::vector <Person*> People){
	int i;
	std::vector <int> aux;
	aux.push_back(-1);
	std::string user, password;
	std::cout<<"Por favor insira seu Login: ";
	std::cin >> user;
	std::cout<<"Por favor insira sua Senha: ";
	std::cin >> password;
	for(i = 0; i < (int)People.size(); i++){
		if(People[i]->ReturnType() == 1){
			Client* c1 = (Client*)People[i];
			if(c1->CustomerLogin == user){
				if(c1->CustomerPassword == password){
					aux[0] = 0;
					aux.push_back(i);
					return aux;
				}
				else{
					std::cout<<"Senha Incorreta!";
					std::cout << std::endl;
					return aux;
				}
			}
		}
		if(People[i]->ReturnType() == 2){
			Employee* c1 = (Employee*)People[i];
			if(c1->employeelogin == user){
				if(c1->employeepassword == password){
					aux[0] = 1;
					aux.push_back(i);
					return aux;
				}
				else{
					std::cout<<"Senha Incorreta!";
					std::cout << std::endl;
					return aux;
				}
			}
		}
	}
	return aux;
}

int SearchInList(std::vector <Person*> People, std::string cpf){
	for(auto c : People){
		if(c->CPF == cpf){
			return 1;
		}
	}
	return 0;
}
void Person::getComments(){
	std::cout<<"no comments for this class"<<std::endl;
}

// ########################################################################################## //

int ModelPerson::callback(void *NotUsed, int argc, char **argv, char **szColName){

	for(int i = 0; i < argc; i++){
    	std::cout << szColName[i] << " = " << argv[i] << std::endl;
  	}

  	std::cout << "\n";

  	return 0;
}

int ModelPerson::callbackcount(void *data, int argc, char **argv, char **szColName){

	int* aux = static_cast<int*>(data);
	*aux = (atoi(argv[0]));

  	return 0;
}

int ModelPerson::callbackperson(void *data, int argc, char **argv, char **szColName){

  Person* aux = static_cast<Person*>(data);
  aux->CPF = argv[0];
  aux->Name =  argv[1];
  aux->Age = atoi(argv[2]);

  return 0;
}

int ModelPerson::HowMany(sqlite3 *db){
	int* countEmp = (int*) malloc(sizeof(int));
	int* countCli = (int*) malloc(sizeof(int));
	char* szErrMsg = nullptr;
	std::string pSQL("SELECT COUNT(CPF) FROM Employee");
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
	if(rc != SQLITE_OK){
    	std::cout << "SQL Error: " << szErrMsg << std::endl;
    	sqlite3_free(szErrMsg);
    	free(countEmp);
    	free(countCli);
    	return 0;
  	}
  	std::string pSQL1("SELECT COUNT(CPF) FROM Client");
	rc = sqlite3_exec(db, pSQL1.c_str(), callbackcount, countCli, &szErrMsg);
	if(rc != SQLITE_OK){
    	std::cout << "SQL Error: " << szErrMsg << std::endl;
    	sqlite3_free(szErrMsg);
    	free(countEmp);
    	free(countCli);
    	return 0;
  	}
  	return (*countEmp + *countCli);
}

flags ModelPerson::InsertIntoTablePerson(Person* aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Person(CPF, Age, Name) VALUES ('"
  + aux->CPF + "', " + std::to_string(aux->Age) + ", '" 
  + aux->Name + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelPerson::DeleteFromTablePerson(std::string CPF, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Person WHERE CPF = '" + CPF + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}

std::vector<Person*> ModelPerson::GetPeople(sqlite3 *db){
	int i;
	std::vector<Person*> aux;
	for (i = 0; i < ModelEmployee::HowMany(db); i++){
		Employee *auxEmp = ModelEmployee::GiveEmployees(i, db);
		aux.push_back(auxEmp);
	}

	for (i = 0; i < ModelClient::HowMany(db); i++){
		Client *auxCli = ModelClient::GiveClients(i, db);
		aux.push_back(auxCli);
	}
	return aux;
}