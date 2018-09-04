#include <iostream>
#include <vector>
#include <string>
#include "Vehicles.hpp"
#include "Alocation.hpp"
#include "Agency.hpp"
int main(){
	// Menu Variables
	std::string check;
	int option;

	// Program
	int i, which, howmany;
	std::vector <Vehicle> Cars;
	std::vector <int> Chosen;
	std::vector <Alocation> Queue;

	// Creating minimal vehicles
	Vehicle ex(0, "GTX1080", "RED", "ALCOHOL", "3KD73S9R0IIII9876", 1990, 3, 10000, 0);
	Cars.push_back(ex);

	// Menu
	std::cout <<"Escolha o tipo de usuário:" << std::endl;
	std::cout << std::endl;
	std::cout <<"CLIENTE     - 0" << std::endl;
	std::cout <<"FUNCIONÁRIO - 1" << std::endl;
	std::cout << std::endl;
	std::cout << "Opção: ";
	std::cin>>option;
	std::cout << std::endl;
	switch(option){
		case 0:
		for(auto c : Cars){
			c.getVehicle();
		}

		std::cout<<"Quantos veículos desejam-se alugar?" << std::endl;
		std::cin>>howmany;


		for(i = 0; i < howmany; i++){
			std::cout<<"Insira o veículo: ";
			std::cin>>which;
			Chosen.push_back(which);
		}


		for(i = 0; i < howmany; i++){
			Alocation aux(Chosen[i],true);
			Queue.push_back(aux);
		}
		
		for(auto c : Queue){
			c.getAlocation();
		}

		return 0;
	case 1:

		std::cout<<"Insira a Senha de Acesso: ";
		std::cout << std::endl;
		std::cin >>check;
		if(check == "ECEM"){
			std::cout<<"Quantos veículos serão criados: " << std::endl;
			std::cin>>howmany;
				
			for(i = 0; i < howmany; i++){
				Vehicle aux(i);
				Cars.push_back(aux);
			}				
		}

		return 0;
	default:
		return 0;
	}

	// ex.getVehicle();
	// int* AlocationData = new int[3];
	// AlocationData[0] = 12;
	// AlocationData[1] = 06;
	// AlocationData[2] = 1206;
	// int* AlocationHour = new int[2];
	// AlocationHour[0] = 15;
	// AlocationHour[1] = 45;
	// int* DevolutionData = new int[3];
	// DevolutionData[0] = 12;
	// DevolutionData[1] = 06;
	// DevolutionData[2] = 1306;
	// int* DevolutionHour = new int[2];
	// DevolutionHour[0] = 15;
	// DevolutionHour[1] = 46;
	// Alocation ExState = ex.Alocate(AlocationData, AlocationHour, DevolutionData, DevolutionHour);
	// ex.getVehicle();
	// ExState.getAlocation();
	return 0;
}