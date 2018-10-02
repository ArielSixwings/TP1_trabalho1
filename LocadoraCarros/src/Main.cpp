#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include "Person.hpp"
#include "Employee.hpp"
#include "Client.hpp"
#include "Vehicles.hpp"
#include "Alocation.hpp"
#include "Agency.hpp"
#include "Exceptions.hpp"
#include "Interface.hpp"

const std::map<std::string, int> AgencysIdmap = {
  {"074",0},{"893",1},{"182",2}
};

int main(){

	// Menu's Variables
	int option;
	std::string check, auxId;;

	// Program
	std::vector <Vehicle> Cars;
	//std::vector <int> 
	int i, which, howmany;
	std::vector <Alocation> Queue;
	std::vector <Vehicle> Alocated;
	std::vector <Agency> Agencys;

	//Creating basic Agencys
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	Agency A2("893","Q CSD 06 LOTE 34 LOJA 01, St. D Sul - TAGUATINGA SUL, Brasília - DF, 72020-065",0.0);
	Agency A3("182","St. A Sul QSA 20 - Taguatinga, Brasília - DF, 72015-200",0.0);
	
	A1.startSalesMonth();
	Agencys.push_back(A1);
	Agencys.push_back(A2);
	Agencys.push_back(A3);

	// Creating basic vehicles
	Vehicle V1(0, "VEG4064", "RED", "ALCOHOL", "3KI8S30KMN14IOM40",
		 2015, 4, 923844.0, "00184729834",103.5,93.15);
	Vehicle V2(1, "GTX1070", "BLUE", "GASOLINE", "2MX0P1KL3USKDNZPI",
		 1999, 4, 10000.0, "00948571274",93.7,84.33);
	Vehicle V3(2, "RTX2080", "PINK WITH GREEN STRIPES", "ELETRIC", "0I59D03HBAMM3JU8K",
		 2018, 7, 0.0, "00937458192",82.9,74.61);

	Cars.push_back(V1);
	Cars.push_back(V2);
	Cars.push_back(V3);

	// Creating basic people
	std::vector <Person*> People;
	Employee* P01 = new Employee("06462981199", "Eduardo", 19, 5000, "Rhaegal", "autovelores");
	Employee* P02 = new Employee("00000000000", "Ariel", 19, 5000, "Pivosinho", "tururu");
	Client* CL1 = new Client("34956918320", "Pedro", 22, "BJ", "ia");
	Client* CL2 = new Client("28359481723", "Victor", 19, "Cubo", "cachorro");
	Client* CL3 = new Client("23571113171", "Breno", 19, "AvestruzQueTeSeduz", "autovatores");

	People.push_back(P01);
	People.push_back(P02);
	People.push_back(CL1);
	People.push_back(CL2);
	People.push_back(CL3);
	
	// Menu
	MENU:
	std::cout <<"Menu" << std::endl;
	std::cout << std::endl;
	std::cout <<"Executar Programa     - 0" << std::endl;
	std::cout <<"Finalizar Programa    - 1" << std::endl;
	std::cout << std::endl;
	std::cout << "Opção: ";
	option = VerifyTypeInputs();
	std::cout << std::endl;

	switch(option){
		case 0:
			// SubMenu
			std::cout <<"Escolha o tipo de usuário:" << std::endl;
			std::cout << std::endl;
			std::cout <<"Cliente     - 0" << std::endl;
			std::cout <<"Funcionário - 1" << std::endl;
			std::cout << std::endl;
			std::cout << "Opção: ";
			option = VerifyTypeInputs();
			std::cout << std::endl;

			switch(option){

			case 0:

				option = VerifyRegistration(People);
				if(option == -1 || option == 1){
					std::cout<<"Cadastro do cliente não encontrado!";
					BackToMenu();
					goto MENU;
				}

				std::cout<< "Veículos Disponíveis: " << std::endl << std::endl;
				for(auto c : Cars){
					c.getVehicle();
				}

				std::cout<<"Quantos veículos desejam-se alugar?" << std::endl;
				std::cin>>howmany;


				for(i = 0; i < howmany; i++){
					std::cout<<"Insira a chave do veículo: ";
					which = ExceptionsInputs::VerifyInputs(0, Cars.size());
					Alocated.push_back(Cars[which]);
				}


				for(i = 0; i < howmany; i++){
					std::cout<<"\nEscolha o tipo de alocação para o carro "<< Alocated[i].Key <<std::endl;
					std::cout<<"Período  -  0" <<std::endl;
					std::cout<<"Diária   -  1" <<std::endl;
					std::cout<<"Opção: ";
					option = VerifyTypeInputs();
					int auxid = 0;
					std::string auxagencyid;
					for(auto a : Agencys){
						 
						std::cout<< "Agencia: " << auxid <<" identificação: "<<a.agencyId<<std::endl;
						auxid++; 
					}
					std::cout<<"Insira a identificação da agencia: ";
					
					auxagencyid = ExceptionsInputs::VerifyAgencyId(AgencysIdmap);

					if(option == 0){
						Alocation aux(Alocated[i].Key,auxagencyid,true, People);
						Queue.push_back(aux);
						int days = Queue[i].howmanydays();
						double salesrevenue = days * Cars[Alocated[i].Key].Priceperperiod;
						double index = AgencysIdmap.at(Queue[i].Agency);
						Agencys[index].sumRevenue(salesrevenue);
						Cars[Alocated[i].Key].Alocated = true;
					}
					else{
						Alocation aux(Alocated[i].Key,auxagencyid,false, People);
						Queue.push_back(aux);
						Cars[Alocated[i].Key].Alocated = true;	
					}
				}
				
				for(auto c : Queue){
					c.getAlocation();
				}
				// for(auto a : Agencys){
				// 	a.getAgency();
				// }
				// Agency::getGeneralData();
				BackToMenu();
				goto MENU;
			case 1:

				option = VerifyRegistration(People);
				if(option == -1 || option == 0){
					std::cout<<"Cadastro do funcionário não encontrado!";
					BackToMenu();
					goto MENU;
				}

				
				std::cout<<"\nAções disponíveis"<< std::endl;
				std::cout<<"Inserir veículos            -  0" <<std::endl;
				std::cout<<"Inserir usuários            -  1" <<std::endl;
				std::cout<<"Ver lista de veículos       -  2" <<std::endl;
				std::cout<<"Ver lista de usuários       -  3" <<std::endl;
				std::cout<<"Ver alocações               -  4" <<std::endl;
				std::cout<<"Opção: ";
				option = VerifyTypeInputs();
				std::cout<< std::endl;
				if(option == 0){
					std::cout<<"Quantos veículos serão inseridos: " << std::endl;
					std::cin>>howmany;
					for(i = 0; i < howmany; i++){
						Vehicle aux(i);
						Cars.push_back(aux);
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 1){
					std::cout<<"Quantos usuários serão inseridos: " << std::endl;
					std::cin>>howmany;
					for(i = 0; i < howmany; i++){
						std::cout << std::endl;
						std::cout<<"Usuário " << i << std::endl;
						std::cout<<"Cliente         -  0" <<std::endl;
						std::cout<<"Funcionário     -  1" <<std::endl;
						std::cout<<"Tipo de usuário: ";
						option = VerifyTypeInputs();
						if(option == 0){
							std::cout << std::endl;
							Client* aux = new Client();
							People.push_back(aux);
						}
						if(option == 1){
							std::cout << std::endl;
							Employee* aux = new Employee();
							People.push_back(aux);
						}
						if(option != 0 && option != 1){
							goto MENU;
						}
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 2){
					std::cout<< "Veículos Disponíveis: " << std::endl << std::endl;
					for(auto c : Cars){
						c.getVehicle();
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 3){
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
					BackToMenu();
					goto MENU;
				}
				if(option == 4){
						for(auto c : Queue){
						c.getAlocation();
					}
					BackToMenu();
					goto MENU;
				}
				else{
					goto MENU;
				}
			default:
				goto MENU;
			}
		case 1:
			return 0;
		default:
			return 0;
	}
}