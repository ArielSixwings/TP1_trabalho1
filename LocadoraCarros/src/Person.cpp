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