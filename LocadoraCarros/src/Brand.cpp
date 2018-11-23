#include "Brand.hpp"
#include "Exceptions.hpp"
#include <cstring>

Brand::Brand(std::string name, int numberOfModels){
	this->Name = name;
	this->NumberOfModels = numberOfModels;
}

Brand::Brand(int i){
  std::string string;
  std::cout << "Marca: " << i << std::endl;
  std::cout << "Insira o nome da Marca: " << std::endl;
  std::cin >> string;
  this->Name = string;
  std::cout << "Insira o número de modelos da Marca: " << std::endl;
  int number = VerifyTypeInputs();
  this->NumberOfModels = number;
}

void Brand::getBrand(){
	std::cout<<"Nome da Marca: " << this->Name << std::endl;
	std::cout<<"Número de modelos da Marca: " << this->NumberOfModels << std::endl;
}

void Brand::setBrand(std::string name, int numberOfModels){
	this->Name = name;	
	this->NumberOfModels = numberOfModels;
}

// ########################################################################################## //

int ModelBrand::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelBrand::callbackbrand(void *data, int argc, char **argv, char **szColName){

  Brand* aux = static_cast<Brand*>(data);
  aux->Name =  argv[0];
  aux->NumberOfModels = atoi(argv[1]);

  return 0;
}

int ModelBrand::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}

int ModelBrand::callbackname(void *data, int argc, char **argv, char **szColName){

  memcpy(data, argv[0], 15*sizeof(char));

  return 0;
}

Brand ModelBrand::GiveBrands(int i, sqlite3 *db){
  Brand aux("Error", 0);
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Brand WHERE rowid = " + std::to_string(i+1));
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackbrand, &aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return aux;
    }
    return aux;
}

int ModelBrand::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(Name) FROM Brand");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Brand ModelBrand::FindBrand(std::string Id, sqlite3 *db){
  Brand aux("Error", 0);
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Brand WHERE Name = '" + Id + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackbrand, &aux, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return aux;
  }
  return aux;
}

flags ModelBrand::InsertIntoTableBrand(Brand aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Brand(Name, NumberOfModels) VALUES ('"
  + aux.Name + "', '" + std::to_string(aux.NumberOfModels) + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelBrand::DeleteFromTableBrand(std::string Name, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Brand WHERE Name = '" + Name + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}

std::vector <Brand> ModelBrand::GetBrands(sqlite3 *db){
  std::vector<Brand> aux;
  for (int i = 0; i < ModelBrand::HowMany(db); i++){
    Brand auxBrd = ModelBrand::GiveBrands(i, db);
    aux.push_back(auxBrd);
  }
  return aux;
}

char* ModelBrand::FindFromName(std::string name, sqlite3 *db){
  char *szErrMsg = nullptr;
  char* key = (char*) malloc(15*sizeof(char));

  std::string pSQL("SELECT Brand.Name FROM Brand WHERE Brand.Name = '" + name + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackname, key, &szErrMsg);
  
  if (rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return nullptr;
  }
  return key;
}