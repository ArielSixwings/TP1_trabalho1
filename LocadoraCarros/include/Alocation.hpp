#ifndef ALOCATION_HPP
#define ALOCATION_HPP
#include <vector>
#include <string>
#include <ctime>

class Alocation{
public:
	int whichvehicle;
	std::vector <int> AlocationData;
	std::vector <int> AlocationHour;
	std::vector <int> DevolutionData;
	std::vector <int> DevolutionHour;
	std::string Type; //daily or byperiod
	std::string Agency;
	std::string CustomerId;
public:
	Alocation(int which,std::string Agency,bool byperiod);
	Alocation(std::vector <int> alocationData, std::vector <int>  alocationHour,
	 std::vector <int>  devolutionData, std::vector <int>  devolutionHour);
	~Alocation();
	void getAlocation();
	int howmanydays();
};

#endif /* ALOCATION_HPP */