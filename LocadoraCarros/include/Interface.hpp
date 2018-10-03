#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include "Person.hpp"
#include "Vehicles.hpp"
#include "Alocation.hpp"
#include "Agency.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "Exceptions.hpp"

void BackToMenu();
void MainMenu();
void SubMenu();
void EmployeeMenu();
void MenuCreation(int i);
void AvailableVehicles(std::vector <Vehicle> Cars);
void AvailableAlocations(std::vector <Alocation> Queue);
void AvailableAgencys(std::vector <Agency> Agencys);
void ShowInformation(std::vector <Person*> People);
int UserCreation(std::vector <Person*> *People);
std::vector <Alocation> RemoveAlocation(std::vector <Alocation> array);

#endif //INTERFACE_HPP