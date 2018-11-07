#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <sqlite3.h>
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

void showComments(Members* member){
	member->getComments();
}
int main(){
	Employee* auxEmp;
	// Menu's Variables
	int option,commenttype,clienteoption;
	std::string check, auxId;;

	// Program
	std::vector <int> who;
	std::vector <Vehicle> Cars;
	int i, which, howmany;
	std::vector <std::string> Brands;
	std::vector <std::vector <std::string>> Models(4, std::vector<std::string>(3));
	std::vector <Alocation> Queue;
	std::vector <Vehicle> Alocated;
	std::vector <Agency> Agencys;
	std::vector<Person*> Emp;
	std::string auxcomments;
	std::string auxagencyid;

	//Creating basic Brands
	Brands.push_back("Chevrolet");
	Brands.push_back("BMW");
	Brands.push_back("Ford");
	Brands.push_back("Tesla");

	//Creating basic Models
	Models[0][0] = "Agile";
	Models[0][1] = "Tigra";
	Models[0][2] = "Camaro";
	Models[1][0] = "X1";
	Models[1][1] = "M5";
	Models[1][2] = "i3";
	Models[2][0] = "Edge";
	Models[2][1] = "Ecosport";
	Models[2][2] = "Fusion";
	Models[3][0] = "ModelS";
	Models[3][1] = "ModelX";
	Models[3][2] = "Model3";

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
		 2015, 4, 923844.0, "00184729834", "Fusion", "Ford", 103.5,93.15);
	Vehicle V2(1, "GTX1070", "BLUE", "GASOLINE", "2MX0P1KL3USKDNZPI",
		 1999, 4, 10000.0, "00948571274", "Agile", "Chevrolet",93.7,84.33);
	Vehicle V3(2, "RTX2080", "PINK WITH GREEN STRIPES", "ELETRIC", "0I59D03HBAMM3JU8K",
		 2018, 7, 0.0, "00937458192", "ModelS", "Tesla", 82.9,74.61);

	Cars.push_back(V1);
	Cars.push_back(V2);
	Cars.push_back(V3);

	// Creating basic people
	std::vector <Person*> People;
	Employee* P00 = new Employee("29085746000", " Cristhian", 29, 10000, "TP1", "123");
	Employee* P01 = new Employee("11111111111", "Eduardo", 19, 5000, "Rhaegal", "autovelores");
	Employee* P02 = new Employee("00000000000", "Ariel", 19, 5000, "Pivosinho", "tururu");
	Client* CL1 = new Client("34956918320", "Pedro", 22, "BJ", "ia");
	Client* CL2 = new Client("28359481723", "Victor", 19, "Cubo", "cachorro");
	Client* CL3 = new Client("23571113171", "Breno", 19, "AvestruzQueTeSeduz", "autovatores");

	People.push_back(P00);
	People.push_back(P01);
	People.push_back(P02);
	People.push_back(CL1);
	People.push_back(CL2);
	People.push_back(CL3);
	
	// Menu
	MENU:
	MainMenu();
	option = VerifyTypeInputs();
	std::cout << std::endl;

	switch(option){
		case 0:
			// SubMenu
			SubMenu();
			option = VerifyTypeInputs();
			std::cout << std::endl;

			switch(option){

			case 0:
				clienteoption = ClientMenu();
				std::cout << std::endl;
				switch(clienteoption){
				case 0:
					who = VerifyRegistration(People);
					if(who[0] == -1){
						std::cout<<"Cadastro do cliente não encontrado!";
						BackToMenu();
						goto MENU;
					}
					
					AvailableVehicles(Cars);
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
						std::cout<< std::endl;
						for(auto a : Agencys){
							
							std::cout<< "Agencia " << auxid << std::endl << "Identificação: "<<a.agencyId<<std::endl;
							auxid++; 
						}
						std::cout<<"Insira a identificação da agência: ";
						
						auxagencyid = ExceptionsInputs::VerifyAgencyId(AgencysIdmap);

						if(option == 0){
							Alocation aux(Alocated[i].Key,auxagencyid,true, People[who[1]]->CPF, Cars[Alocated[i].Key].Priceperperiod);
							Queue.push_back(aux);
							int days = Queue[i].howmanydays();
							double salesrevenue = days * Cars[Alocated[i].Key].Priceperperiod;
							double index = AgencysIdmap.at(Queue[i].Agency);
							Agencys[index].sumRevenue(salesrevenue);
							Cars[Alocated[i].Key].Alocated = true;
						}
						else{
							Alocation aux(Alocated[i].Key,auxagencyid,false, People[who[1]]->CPF, Cars[Alocated[i].Key].Priceperday);
							Queue.push_back(aux);
							Cars[Alocated[i].Key].Alocated = true;	
						}
					}
					Cars.erase(Cars.begin()+ which);
					AvailableAlocations(Queue);
					BackToMenu();
					goto MENU;
				
				case 1:
					commenttype = CommentMenu();
					if(commenttype == 0 ){
						for(auto e : People){
							if(e->ReturnType() == 2){
								auxEmp = (Employee*)e;
								Emp.push_back(auxEmp);
							}	
						}
						std::cout<<"Selecione o funcionario"<<std::endl;
						int auxi = 0;
						for(auto e2: Emp){
							std::cout<<auxi<<"   "<<e2->Name<<std::endl;
							auxi++;
						}
						which = ExceptionsInputs::VerifyInputs(0, Emp.size());
						std::cout<<"Faça o comentario"<<std::endl;
						std::cin.get();
						std::getline(std::cin, auxcomments);
						Emp[which]->comments = auxcomments;
						showComments(Emp[which]);
					}
					else{
						std::cout<<"Selecione a agencia"<<std::endl;
						int auxi = 0;
						for(auto a: Agencys){
							std::cout<<auxi<<"   "<<a.agencyId<<std::endl;
							auxi++;
						}
						auxagencyid = ExceptionsInputs::VerifyAgencyId(AgencysIdmap);
						std::cout<<"Faça o comentario"<<std::endl;
						std::cin.get();
						std::getline(std::cin, auxcomments);
						Agencys[AgencysIdmap.at(auxagencyid)].comments = auxcomments;
						showComments(&Agencys[AgencysIdmap.at(auxagencyid)]);										
					}
				default:
					goto MENU;
				}
			case 1:

				who = VerifyRegistration(People);
				if(who[0] == -1 || who[0] == 0){
					std::cout<<"Cadastro do funcionário não encontrado!";
					BackToMenu();
					goto MENU;
				}

				EmployeeMenu();
				option = VerifyTypeInputs();
				std::cout<< std::endl;

				if(option == 0){
					std::cout<<"Quantos veículos serão inseridos: " << std::endl;
					howmany = VerifyTypeInputs();
					int j = (int)Cars.size();
					for(i = j; i < (j + howmany); i++){
						Vehicle aux(i, Brands, Models);
						Cars.push_back(aux);
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 1){
					option = UserCreation(&People);
					if(option != 0 && option != 1){
						goto MENU;
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 2){
					AvailableVehicles(Cars);
					BackToMenu();
					goto MENU;
				}
				if(option == 3){
					ShowInformation(People);
					BackToMenu();
					goto MENU;
				}
				if(option == 4){
					AvailableAlocations(Queue);
					BackToMenu();
					goto MENU;
				}
				if(option == 5){
					AvailableAlocations(Queue);
					Queue = RemoveAlocation(Queue);
				}
				if(option == 6){
					AvailableAgencys(Agencys);
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