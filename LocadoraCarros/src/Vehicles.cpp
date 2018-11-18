#include <iostream>
#include <string>
#include "Vehicles.hpp"
#include "Exceptions.hpp"

Vehicle::Vehicle(int key, std::string board, std::string color,std::string typefuel, 
	std::string chassi, int year, int howmanydoors, double distance, 
	std::string Renavam, std::string MODEL, std::string BRAND, double Priceperday, double Priceperperiod)
{
	this->Alocated = false;
	this->Key = key;
	this->Board = board;
	this->Color = color;
	this->TypeFuel = typefuel;
	this->Chassi = chassi;
	this->Year = year;
	this->Howmanydoors = howmanydoors;
	this->Distance = distance;
	this->renavam = Renavam;
	this->Model = MODEL;
	this->Brand = BRAND;
	this->Priceperday = Priceperday;
	this->Priceperperiod = Priceperperiod;
}

Vehicle::Vehicle(int i, std::vector <std::string> Brands, std::vector <std::vector <std::string>> Models){
	this->Alocated = false;
	this->Key = i;
	std::cout<<"Veículo " << i << std::endl;
	std::cout<<"Placa: ";
	this->Board = ExceptionsInputs::VerifyExactInputs(7, PLACA);
	std::cout<<"Cor: ";
	std::cin>>this->Color;
	std::cout<<"Tipo de Combustível: ";
	std::cin>>this->TypeFuel;
	std::cout<<"Chassi: ";
	this->Chassi = ExceptionsInputs::VerifyExactInputs(17, CHASSI);
	std::cout<<"Ano de Fabricação: ";
	this->Year = VerifyTypeInputs();
	std::cout<<"Número de Portas: ";
	this->Howmanydoors = VerifyTypeInputs();
	std::cout<<"Quilometragem: ";
	this->Distance = VerifyTypeInputs();
	std::cout<<"RENAVAM: ";
	this->renavam = ExceptionsInputs::VerifyExactInputs(11, RENAVAM);
	ShowBrands(Brands);
	std::cout<<"Marca: ";
	this->Brand = ExceptionsInputs::VerifyBrandsInputs(Brands);
	ShowModels(this->Brand, Models);
	std::cout<<"Modelo: ";
	this->Model = ExceptionsInputs::VerifyModelsInputs(this->Brand, Models);
	std::cout<<"Preço de alocação por dia: ";
	std::cin>>this->Priceperday;
	std::cout<<"Preço de alocação por período: ";
	std::cin>>this->Priceperperiod;
	std::cout << std::endl;
}

void Vehicle::getVehicle(){
	std::cout<<"Chave do Veículo: " << Key << std::endl;
	std::cout<<"Está alocado: " << Alocated << std::endl;
	std::cout<<"Placa: " << Board << std::endl;
	std::cout<<"Cor: " << Color << std::endl;
	std::cout<<"Tipo de Combustível: " << TypeFuel << std::endl;
	std::cout<<"Chassi: " << Chassi << std::endl;
	std::cout<<"Ano de Fabricação: " << Year << std::endl;
	std::cout<<"Número de Portas: " << Howmanydoors << std::endl;
	std::cout<<"Quilometragem: " << Distance << std::endl;
	std::cout<<"RENAVAM: " << this->renavam << std::endl;
	std::cout<<"Marca: " << this->Brand << std::endl;
	std::cout<<"Modelo: " << this->Model << std::endl;
	std::cout<<"Preço de alocação por dia: "<< Priceperday << std::endl;
	std::cout<<"Preço de alocação por período: "<< Priceperperiod << std::endl;
	std::cout << std::endl;
}

void ShowBrands(std::vector <std::string> Brands){
	std::cout << std::endl;
	std::cout<<"Marcas Disponíveis: " << std::endl;
	for(auto c : Brands){
		std::cout<<c << std::endl;
	}
}

void ShowModels(std::string Brand, std::vector <std::vector <std::string>> Models){
	std::cout << std::endl;
	if(Brand == "Chevrolet"){
		std::cout<<"Modelos disponíveis da Marca Chevrolet" << std::endl;
		std::cout<<Models[0][0] << std::endl;
		std::cout<<Models[0][1] << std::endl;
		std::cout<<Models[0][2] << std::endl;
	}
	if(Brand == "BMW"){
		std::cout<<"Modelos disponíveis da Marca BMW" << std::endl;
		std::cout<<Models[1][0] << std::endl;
		std::cout<<Models[1][1] << std::endl;
		std::cout<<Models[1][2] << std::endl;
	}
	if(Brand == "Ford"){
		std::cout<<"Modelos disponíveis da Marca Ford" << std::endl;
		std::cout<<Models[2][0] << std::endl;
		std::cout<<Models[2][1] << std::endl;
		std::cout<<Models[2][2] << std::endl;
	}
	if(Brand == "Tesla"){
		std::cout<<"Modelos disponíveis da Marca Tesla" << std::endl;
		std::cout<<Models[3][0] << std::endl;
		std::cout<<Models[3][1] << std::endl;
		std::cout<<Models[3][2] << std::endl;
	}
}

// ########################################################################################## //

// int ModelVehicle::callback(void *NotUsed, int argc, char **argv, char **szColName){
//   for(int i = 0; i < argc; i++){
//     std::cout << szColName[i] << " = " << argv[i] << std::endl;
//   }

//   std::cout << "\n";

//   return 0;
// }

// int ModelVehicle::callbackVehicle(void *data, int argc, char **argv, char **szColName){

//   Vehicle* aux = static_cast<Vehicle*>(data);
//   aux->CPF = argv[0];
//   aux->Name =  argv[1];
//   aux->Age = atoi(argv[2]);
//   aux->salary = atoi(argv[3]);
//   aux->Vehiclelogin = argv[4];
//   aux->Vehiclepassword = argv[5];

//   return 0;
// }

// int ModelVehicle::callbackcount(void *data, int argc, char **argv, char **szColName){

//   int* aux = static_cast<int*>(data);
//   *aux = (atoi(argv[0]));

//     return 0;
// }

// Vehicle* ModelVehicle::GiveVehicles(int i, sqlite3 *db){
//   Vehicle* aux = new Vehicle("0", "0", 0, 0, "0", "0");
//   char* szErrMsg = nullptr;
//   std::string pSQL("SELECT * FROM Vehicle WHERE rowid = " + std::to_string(i+2));
//   int rc = sqlite3_exec(db, pSQL.c_str(), callbackVehicle, aux, &szErrMsg);
//     if(rc != SQLITE_OK){
//       std::cout << "SQL Error: " << szErrMsg << std::endl;
//       sqlite3_free(szErrMsg);
//       return nullptr;
//     }
//     return aux;
// }

// int ModelVehicle::HowMany(sqlite3 *db){
//   int* countEmp = (int*) malloc(sizeof(int));
//   char* szErrMsg = nullptr;
//   std::string pSQL("SELECT COUNT(CPF) FROM Vehicle");
//   int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
//   if(rc != SQLITE_OK){
//       std::cout << "SQL Error: " << szErrMsg << std::endl;
//       sqlite3_free(szErrMsg);
//       free(countEmp);
//       return 0;
//     }
//   return (*countEmp);
// }

// Vehicle* ModelVehicle::FindVehicle(std::string Login, sqlite3 *db){
//   Vehicle* aux = new Vehicle("0", "0", 0, 0, "0", "0");
//   char* szErrMsg = nullptr;
//   std::string pSQL("SELECT * FROM Vehicle WHERE Vehiclelogin = '" + Login + "'");
//   int rc = sqlite3_exec(db, pSQL.c_str(), callbackVehicle, aux, &szErrMsg);
//   if(rc != SQLITE_OK){
//     std::cout << "SQL Error: " << szErrMsg << std::endl;
//     sqlite3_free(szErrMsg);
//     return nullptr;
//   }
//   return aux;
// }

// flags ModelVehicle::InsertIntoTableVehicle(Vehicle aux, sqlite3 *db){
//   char* szErrMsg = nullptr;
//   std::string pSQL("INSERT OR IGNORE INTO Vehicle(CPF, Name, Age, salary, Vehiclelogin, Vehiclepassword) VALUES ('"
//   + aux.CPF + "', '" + aux.Name + "', " + std::to_string(aux.Age) + ", " + std::to_string(aux.salary) + ", '" 
//   + aux.Vehiclelogin + "', '" + aux.Vehiclepassword + "')");
//   int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
//   if(rc != SQLITE_OK){
//     std::cout << "SQL Error: " << szErrMsg << std::endl;
//     sqlite3_free(szErrMsg);
//     return RETURNERROR;
//   }
//   return RETURNOK;
// }

// flags ModelVehicle::DeleteFromTableVehicle(std::string CPF, sqlite3 *db){
// 	char* szErrMsg = nullptr;
//   	std::string pSQL("DELETE FROM Vehicle WHERE CPF = '" + CPF + "'");
//   	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
//   	if(rc != SQLITE_OK){
//   	  std::cout << "SQL Error: " << szErrMsg << std::endl;
//   	  sqlite3_free(szErrMsg);
//   	  return RETURNERROR;
//   	}
//   	return RETURNOK;	
// }
