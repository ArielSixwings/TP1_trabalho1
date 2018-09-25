#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "Alocation.hpp"
#include <string>

class Vehicle{
public:
	int Key;
	int AlocationPrice;
	bool Alocated;
	std::string Board;
	std::string Color;
	std::string TypeFuel;
	std::string Chassi;
	int Year;
	int Howmanydoors;
	double Distance;
	std::string Renavam;
	double Priceperday;
	double Priceperperiod;
public:
	Vehicle(int i);
	Vehicle(int key, std::string board, std::string color, std::string typefuel, 
		std::string chassi, int year, int howmanydoors, double distance, 
		std::string RENAVAM,double Priceperday, double Priceperperiod);
	Alocation Alocate(std::vector <int> AlocationData, std::vector <int> AlocationHour, std::vector <int> DevolutionData, std::vector <int> DevolutionHour);
	void getVehicle();
};


#endif /* VEHICLE_HPP */