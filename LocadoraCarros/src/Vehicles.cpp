#include <iostream>
#include <string>
#include "Alocation.hpp"
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
	this->model = MODEL;
	this->brand = BRAND;
	this->Priceperday = Priceperday;
	this->Priceperperiod = Priceperperiod;
}

Vehicle::Vehicle(int i, std::vector <Brand> Brands, std::vector <Model> Models){
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
	this->brand = ExceptionsInputs::VerifyBrandsInputs(Brands);
	ShowModels(this->brand, Models);
	std::cout<<"Modelo: ";
	this->model = ExceptionsInputs::VerifyModelsInputs(this->brand, Models);
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
	std::cout<<"Marca: " << this->brand << std::endl;
	std::cout<<"Modelo: " << this->model << std::endl;
	std::cout<<"Preço de alocação por dia: "<< Priceperday << std::endl;
	std::cout<<"Preço de alocação por período: "<< Priceperperiod << std::endl;
	std::cout << std::endl;
}

void ShowBrands(std::vector <Brand> Brands){
	std::cout << std::endl;
	std::cout<<"Marcas Disponíveis: " << std::endl;
	for(auto c : Brands){
		std::cout<<c.Name << std::endl;
	}
}

void ShowModels(std::string Brand, std::vector <Model> Models){
	std::cout << std::endl;
	std::cout << "Modelos disponíveis da Marca " << Brand << std::endl;
	for(auto c : Models){
		if(Brand == c.BrandName){
			std::cout << c.Name << std::endl;
		}
	}
}

// ########################################################################################## //

int ModelVehicle::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelVehicle::callbackvehicle(void *data, int argc, char **argv, char **szColName){

  Vehicle* aux = static_cast<Vehicle*>(data);
  aux->Key = atoi(argv[0]);
  aux->Alocated =(argv[1][0] == '0' ? false : true);
  aux->renavam = argv[2];
  aux->Board = argv[3];
  aux->Color = argv[4];
  aux->TypeFuel = argv[5];
  aux->Chassi = argv[6];
  aux->Year = atoi(argv[7]);
  aux->Howmanydoors = atoi(argv[8]);
  aux->Priceperday = atof(argv[9]);
  aux->Priceperperiod = atof(argv[10]);
  aux->Distance = atof(argv[11]);
  aux->model = argv[12];
  aux->brand = argv[13];

  return 0;
}

int ModelVehicle::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}


Vehicle ModelVehicle::GiveVehicles(int i, sqlite3 *db){
	Vehicle aux(0, "Error", "Error", "Error", "Error", 0, 0, 0, "Error", "Error", "Error", 0, 0);
	char *szErrMsg = nullptr;
	std::string pSQL("SELECT Vehicle.*, Model.Brand FROM Vehicle\
	 INNER JOIN Model ON Vehicle.Model = Model.Name Where Vehicle.rowid = " + std::to_string(i));
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackvehicle, &aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return aux;
    }
    return aux;
}

int ModelVehicle::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(VehicleKey) FROM Vehicle");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Vehicle ModelVehicle::FindVehicle(int Key, sqlite3 *db){
	Vehicle aux(0, "Error", "Error", "Error", "Error", 0, 0, 0, "Error", "Error", "Error", 0, 0);
	char *szErrMsg = nullptr;
	//std::string pSQL("SELECT * FROM Vehicle WHERE VehicleKey = " + std::to_string(Key));
	std::string pSQL("SELECT Vehicle.*, Model.Brand from Vehicle\
	 INNER JOIN Model ON Vehicle.Model = Model.Name WHERE Vehicle.rowid = " + std::to_string(Key));
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackvehicle, &aux, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return aux;
  }
  return aux;
}

flags ModelVehicle::InsertIntoTableVehicle(Vehicle aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Vehicle(VehicleKey, Alocated, RENAVAM, Board, Color, TypeFuel, CHASSI, Year, Doors, PerDay, PerPeriod, Distance, Model) VALUES (" 
  + std::to_string(aux.Key) + ", " + std::to_string(aux.Alocated) + ", '" + aux.renavam + "', '" + aux.Board + "', '" 
  + aux.Color + "', '" + aux.TypeFuel + "', '" + aux.Chassi + "', " + std::to_string(aux.Year) + ", " + std::to_string(aux.Howmanydoors) + ", "
  + std::to_string(aux.Priceperday) + ", " + std::to_string(aux.Priceperperiod) + ", " + std::to_string(aux.Distance) + ", '" + aux.model + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelVehicle::DeleteFromTableVehicle(int Key, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Vehicle WHERE VehicleKey = " + std::to_string(Key));
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}

flags ModelVehicle::UpdateFromTableVehicle(int Key, sqlite3 *db){
	char *szErrMsg = nullptr;
	std::string pSQL("UPDATE Vehicle SET Alocated = 1 WHERE VehicleKey = " + std::to_string(Key));
	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return RETURNERROR;
	}
	return RETURNOK;
}

std::vector<Vehicle> ModelVehicle::GetVehicles(sqlite3 *db){
	std::vector<Vehicle> aux;
	for (int i = 0; i < ModelVehicle::HowMany(db); i++){
		Vehicle auxVeh = ModelVehicle::GiveVehicles(i, db);
		aux.push_back(auxVeh);
	}
	return aux;
}

int ModelVehicle::FindBoard(std::string board, sqlite3 *db){
	char *szErrMsg = nullptr;
	int *key = (int*)malloc(sizeof(int));
	std::string pSQL("SELECT Vehicle.VehicleKey FROM Vehicle WHERE Vehicle.Board = '" + board + "'");
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, key, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return -1;
	}
	return (*key);
}
