#include <iostream>
#include <vector>
#include "Vehicles.hpp"
#include "Alocation.hpp"
#include "Agency.hpp"
int main(){
	int i, which, howmany;
	std::vector <Vehicle> Cars;

	std::cout<<"Quantos veículos serão criados: " << std::endl;
	std::cin>>howmany;
	
	for(i = 0; i < howmany; i++){
		Vehicle aux(i);
		Cars.push_back(aux);
	}

	for(auto c : Cars){
		c.getVehicle();
	}

	std::cout<<"Quantos veículos desejam-se alugar?" << std::endl;
	std::cin>>howmany;

	std::vector <int> Chosen;

	for(i = 0; i < howmany; i++){
		std::cout<<"Insira o veículo: ";
		std::cin>>which;
		Chosen.push_back(which);
	}

	std::vector <Alocation> Queue;

	for(i = 0; i < howmany; i++){
		Alocation aux(Chosen[i],true);
		Queue.push_back(aux);
	}
	
	for(auto c : Queue){
		c.getAlocation();
	}	
	// Vehicle ex("GTX1080", "RED", "ALCOHOL", "3KD73S9R0IIII9876", 1990, 3, 10000, 0);
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