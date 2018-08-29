#ifndef ALOCATION_HPP
#define ALOCATION_HPP
#include <vector>

class Alocation{
public:
	int whichvehicle;
	std::vector <int> AlocationData;
	std::vector <int> AlocationHour;
	std::vector <int> DevolutionData;
	std::vector <int> DevolutionHour;
public:
	Alocation(int which);
	Alocation(std::vector <int> alocationData, std::vector <int>  alocationHour,
	 std::vector <int>  devolutionData, std::vector <int>  devolutionHour);
	~Alocation();
	void getAlocation();
};

#endif /* ALOCATION_H */