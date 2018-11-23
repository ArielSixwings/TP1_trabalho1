#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <sqlite3.h>
#include "DataBank.hpp"
#include "Brand.hpp"
#include "Model.hpp"
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
	sqlite3 *db = GeneralBank::CreateSchema();
	// Menu's Variables
	int option,commenttype,clienteoption;
	std::string check, auxId;;

	// Program
	flags X;
	Employee* auxEmp;
	std::vector <Employee*> Emp;
	std::vector <int> who;
	int i, which, howmany;
	std::vector <Vehicle> Alocated;
	std::string auxcomments;
	std::string auxagencyid;
	std::string genericaux;

	std::vector <Alocation> Queue = ModelAlocation::GetAlocations(db);

	//Creating basic Brands
	std::vector <Brand> Brands = ModelBrand::GetBrands(db);

	
	// //Creating basic Models
	std::vector <Model> Models = ModelModel::GetModels(db);

	// Creating basic Vehicles
	std::vector <Vehicle> Cars = ModelVehicle::GetVehicles(db);


	//Creating basic Agencys
	std::vector <Agency> Agencys = ModelAgency::GetAgencys(db);


	// Creating basic people
	std::vector <Person*> People = ModelPerson::GetPeople(db);

		
// Menu
	MENU:
		Queue = ModelAlocation::GetAlocations(db);

		//Creating basic Brands
		Brands = ModelBrand::GetBrands(db);

		// //Creating basic Models
		Models = ModelModel::GetModels(db);

		// Creating basic Vehicles
		Cars = ModelVehicle::GetVehicles(db);

		//Creating basic Agencys
		Agencys = ModelAgency::GetAgencys(db);

		// Creating basic people
		People = ModelPerson::GetPeople(db);

		MainMenu();
		option = VerifyTypeInputs();
		std::cout << std::endl;

		switch (option){
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
						ExceptionsInputs::VerifyCar(Alocated, Cars, db);
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
							Alocation aux(ModelAlocation::HowMany(db) + 1, Alocated[i].Key,auxagencyid,true, People[who[1]]->CPF, Cars[Alocated[i].Key].Priceperperiod);
                         	X = ModelAlocation::InsertIntoTableAlocation(true, aux, db);
                     		GeneralBank::ExitDataBase(X, db);
							Queue.push_back(aux);
							int days = Queue[i].howmanydays();
							double salesrevenue = days * Cars[Alocated[i].Key].Priceperperiod;
							double index = AgencysIdmap.at(Queue[i].Agency);
							Agencys[index].sumRevenue(salesrevenue);
							Cars[Alocated[i].Key].Alocated = true;
						}
						else{
							Alocation aux(ModelAlocation::HowMany(db) + 1, Alocated [i].Key, auxagencyid, false, People[who[1]]->CPF, Cars[Alocated[i].Key].Priceperday);
							Queue.push_back(aux);
							X = ModelAlocation::InsertIntoTableAlocation(false, aux, db);
                     		GeneralBank::ExitDataBase(X, db);
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
					AvailableVehicles(Cars);
					BackToMenu();
					goto MENU;
				}
				if(option == 1){
					std::cout<<"Quantos veículos serão inseridos: " << std::endl;
					howmany = VerifyTypeInputs();
					int j = (int)Cars.size();
					for(i = j; i < (j + howmany); i++){
						Vehicle aux(i, Brands, Models);
                     	X = ModelVehicle::InsertIntoTableVehicle(aux, db);
                     	GeneralBank::ExitDataBase(X, db);
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 2){
					AvailableVehicles(Cars);
					std::cout << "Quantos veículos serão eliminados: " << std::endl;
					howmany = VerifyTypeInputs();
					for (i = 0; i < howmany; i++){
						std::cout << "Insira a placa do veículo que será eliminado: " << std::endl;
						std::cout << "Placa: ";
						genericaux = ExceptionsInputs::VerifyExactInputs(7, PLACA);
						int key = ModelVehicle::FindBoard(genericaux, db);
						
						X = ModelVehicle::DeleteFromTableVehicle(key, db);
						GeneralBank::ExitDataBase(X, db);
						
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 3){
					AvailableBrands(Brands);
					BackToMenu();
					goto MENU;
				}
				if(option == 4){
					std::cout << "Quantos marcas serão inseridas: " << std::endl;
					howmany = VerifyTypeInputs();
					int j = (int)Brands.size();
					for (i = j; i < (j + howmany); i++){
						Brand aux(i);
						X = ModelBrand::InsertIntoTableBrand(aux, db);
						GeneralBank::ExitDataBase(X, db);
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 5){
					AvailableBrands(Brands);
					std::cout << "Quantas marcas serão eliminadas: " << std::endl;
					howmany = VerifyTypeInputs();
					for (i = 0; i < howmany; i++){
						std::cout << "Insira o nome da marca que será eliminada: " << std::endl;
						std::cout << "Nome: ";
						std::cin >> genericaux;

						X = ModelBrand::DeleteFromTableBrand(genericaux, db);
						GeneralBank::ExitDataBase(X, db);
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 6){
					AvailableModels(Models);
					BackToMenu();
					goto MENU;
				}
				if(option == 7){
					AvailableBrands(Brands);
					std::cout << "Quantos modelos serão inseridas: " << std::endl;
					howmany = VerifyTypeInputs();
					int j = (int)Models.size();
					for (i = j; i < (j + howmany); i++){
						Model aux(i, Brands);
						X = ModelModel::InsertIntoTableModel(aux, db);
						GeneralBank::ExitDataBase(X, db);
					}
					BackToMenu();
					goto MENU;
				}
				if (option == 8){
					AvailableModels(Models);
					std::cout << "Quantos modelos serão eliminados: " << std::endl;
					howmany = VerifyTypeInputs();
					for (i = 0; i < howmany; i++){
						
						std::cout << "Insira o nome do modelo que será eliminado: " << std::endl;
						std::cout << "Nome: ";
						std::cin >> genericaux;
						int key = ModelModel::FindFromName(genericaux, db);

						X = ModelModel::DeleteFromTableModel(key, db);
						GeneralBank::ExitDataBase(X, db);
					}
					BackToMenu();
					goto MENU;
				}
				if (option == 9){
					ShowInformation(People);
					BackToMenu();
					goto MENU;
				}
				if(option == 10){
					option = UserCreation(&People, db);
					if(option != 0 && option != 1){
						goto MENU;
					}
					BackToMenu();
					goto MENU;
				}
				if(option == 11){
					ShowInformation(People);
					std::cout << "Insira o CPF do usuário que deseja ser removido: ";
					genericaux = ExceptionsInputs::VerifyExactInputs(11, cpf);
					X = ModelPerson::DeleteFromTablePerson(genericaux, db);
					GeneralBank::ExitDataBase(X, db);
					X = ModelEmployee::DeleteFromTableEmployee(genericaux, db);
					GeneralBank::ExitDataBase(X, db);
					X = ModelClient::DeleteFromTableClient(genericaux, db);
					GeneralBank::ExitDataBase(X, db);
					BackToMenu();
					goto MENU;
				}
				if(option == 12){
					AvailableAlocations(Queue);
					BackToMenu();
					goto MENU;
				}
				if(option == 13){
					AvailableAlocations(Queue);
					std::cout << "Insira a chave da alocação que deseja ser removida: ";
					which = VerifyTypeInputs();
					X = ModelAlocation::DeleteFromTableAlocation(which, db);
					GeneralBank::ExitDataBase(X, db);
					BackToMenu();
					goto MENU;
				}
				if(option == 14){
					AvailableAgencys(Agencys);
					BackToMenu();
					goto MENU;
				}
				if(option == 15){
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