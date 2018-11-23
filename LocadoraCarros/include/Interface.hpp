#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <sqlite3.h>
#include "Person.hpp"
#include "Brand.hpp"
#include "Model.hpp"
#include "Alocation.hpp"
#include "Vehicles.hpp"
#include "Agency.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "Exceptions.hpp"

//!todas são funções auxiliares para comunicação com o usuario via terminal
void BackToMenu();
void MainMenu();
void SubMenu();
void EmployeeMenu();
void MenuCreation(int i);
void AvailableVehicles(std::vector<Vehicle> Cars);
void AvailableModels(std::vector<Model> Models);
void AvailableBrands(std::vector<Brand> Brands);
void AvailableAlocations(std::vector<Alocation> Queue);
void AvailableAgencys(std::vector <Agency> Agencys);
void ShowInformation(std::vector <Person*> People);
int UserCreation(std::vector <Person*> *People, sqlite3* db);
void EditVehicle();
int ClientMenu();
int CommentMenu();
std::vector <Alocation> RemoveAlocation(std::vector <Alocation> array);

#endif //INTERFACE_HPP