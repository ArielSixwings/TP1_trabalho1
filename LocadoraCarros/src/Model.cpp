#include "Model.hpp"
#include "Exceptions.hpp"

Model::Model(int modelid, std::string name, std::string brandname){
	this->ModelId = modelid;
	this->Name = name;
  this->BrandName = brandname;
}

Model::Model(int i, std::vector<Brand> Brands){
  int number;
  std::string string;
  std::cout << "Modelo: " << i << std::endl;
  std::cout << "Insira o Id do modelo: " << std::endl;
  number = VerifyTypeInputs();
  this->ModelId = number;
  std::cout << "Insira o nome do modelo: " << std::endl;
  std::cin >> string;
  this->Name = string;
  std::cout << "Insira o nome do marca do modelo: " << std::endl;
  string = ExceptionsInputs::VerifyBrandsInputs(Brands);
  this->BrandName = string;
}

void Model::getModel(){
	std::cout<<"Id do Modelo: " << this->ModelId << std::endl;
	std::cout<<"Nome do Modelo: " << this->Name << std::endl;
  std::cout<<"Nome da Marca do Modelo: " << this->BrandName << std::endl;
}

void Model::setModel(int modelid, std::string name, std::string brandname){
	this->ModelId = modelid;
	this->Name = name;
  this->BrandName = brandname;
}

// ########################################################################################## //

int ModelModel::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelModel::callbackmodel(void *data, int argc, char **argv, char **szColName){

  Model* aux = static_cast<Model*>(data);
  aux->ModelId = atoi(argv[0]);
  aux->Name =  argv[1];
  aux->BrandName = argv[2];

  return 0;
}

int ModelModel::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}

Model ModelModel::GiveModels(int i, sqlite3 *db){
  Model aux(0, "Error","Error");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Model WHERE rowid = " + std::to_string(i+1));
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackmodel, &aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return aux;
    }
    return aux;
}

int ModelModel::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(ModelId) FROM Model");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Model ModelModel::FindModel(int Id, sqlite3 *db){
  Model aux(0, "Error", "Error");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Model WHERE ModelId = '" + std::to_string(Id) + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackmodel, &aux, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return aux;
  }
  return aux;
}

flags ModelModel::InsertIntoTableModel(Model aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Model(ModelId, Name, Brand) VALUES ("
  + std::to_string(aux.ModelId) + ", '" + aux.Name + "', '" + aux.BrandName + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelModel::DeleteFromTableModel(int ModelId, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Model WHERE ModelId = '" + std::to_string(ModelId) + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}

std::vector<Model> ModelModel::GetModels(sqlite3 *db){
  std::vector<Model> aux;
  for (int i = 0; i < ModelModel::HowMany(db); i++){
    Model auxMdl = ModelModel::GiveModels(i, db);
    aux.push_back(auxMdl);
  }
  return aux;
}

int ModelModel::FindFromName(std::string name, sqlite3 *db){
  char *szErrMsg = nullptr;
  int* key = (int*) malloc(sizeof(int));

  std::string pSQL("SELECT Model.ModelId FROM Brand WHERE Model.Name = '" + name + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, key, &szErrMsg);

  if (rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return -1;
  }
  return (*key);
}