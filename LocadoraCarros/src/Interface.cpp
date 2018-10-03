#include "Interface.hpp"
#include <iostream>

void BackToMenu(){
	std::cout << std::endl;
	std::cout<<"Pressione qualquer tecla para continuar...";
	getchar();
	getchar();
	system("clear");
}

void MainMenu(){
	std::cout <<"Menu" << std::endl;
	std::cout << std::endl;
	std::cout <<"Executar Programa     - 0" << std::endl;
	std::cout <<"Finalizar Programa    - 1" << std::endl;
	std::cout << std::endl;
	std::cout << "Opção: ";
}

void SubMenu(){
	std::cout <<"Escolha o tipo de usuário:" << std::endl;
	std::cout << std::endl;
	std::cout <<"Cliente     - 0" << std::endl;
	std::cout <<"Funcionário - 1" << std::endl;
	std::cout << std::endl;
	std::cout << "Opção: ";
}

void EmployeeMenu(){
	std::cout<<"\nAções disponíveis"<< std::endl;
	std::cout<<"Inserir veículos            -  0" <<std::endl;
	std::cout<<"Inserir usuários            -  1" <<std::endl;
	std::cout<<"Ver lista de veículos       -  2" <<std::endl;
	std::cout<<"Ver lista de usuários       -  3" <<std::endl;
	std::cout<<"Ver alocações               -  4" <<std::endl;
	std::cout<<"Remover Alocações           -  5" <<std::endl;
	std::cout<<"Ver Agências                -  6" <<std::endl;
	std::cout<<"Opção: ";
}

void MenuCreation(int i){
	std::cout << std::endl;
	std::cout<<"Usuário " << i << std::endl;
	std::cout<<"Cliente         -  0" <<std::endl;
	std::cout<<"Funcionário     -  1" <<std::endl;
	std::cout<<"Tipo de usuário: ";
}

void AvailableVehicles(std::vector <Vehicle> Cars){
	std::cout<< "Veículos Disponíveis: " << std::endl << std::endl;
	for(auto c : Cars){
		c.getVehicle();
	}
}

void AvailableAlocations(std::vector <Alocation> Queue){
	for(auto c : Queue){
		c.getAlocation();
	}
}

void AvailableAgencys(std::vector <Agency> Agencys){
	for(auto a : Agencys){
		a.getAgency();
	}
	Agency::getGeneralData();
}

void ShowInformation(std::vector <Person*> People){
	int i;
	for(i = 0; i < (int)People.size(); i++){
		if(People[i]->ReturnType() == 1){
			Client* c1 = (Client*)People[i];
			c1->ShowInformation();
			std::cout << std::endl;
		}
		if(People[i]->ReturnType() == 2){
			Employee* c1 = (Employee*)People[i];
			c1->ShowInformation();
			std::cout << std::endl;
		}
	}
}

int UserCreation(std::vector <Person*> *People){
	int howmany, option, i;
	std::cout<<"Quantos usuários serão inseridos: " << std::endl;
	std::cin>>howmany;
	for(i = 0; i < howmany; i++){
		MenuCreation(i);
		option = VerifyTypeInputs();
		if(option == 0){
			std::cout << std::endl;
			Client* aux = new Client();
			People->push_back(aux);
		}
		if(option == 1){
			std::cout << std::endl;
			Employee* aux = new Employee();
			People->push_back(aux);
		}
	}
	return option;			
}