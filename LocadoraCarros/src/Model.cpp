#include "Model.hpp"

Model::Model(std::string modelid, std::string name, std::string brandname){
	this->ModelId = modelid;
	this->Name = name;
  this->BrandName = brandname;
}

void Model::getModel(){
	std::cout<<"Id do Modelo: " << this->ModelId << std::endl;
	std::cout<<"Nome do Modelo: " << this->Name << std::endl;
  std::cout<<"Nome da Marca do Modelo: " << this->BrandName << std::endl;
}

void Model::setModel(std::string modelid, std::string name, std::string brandname){
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
  aux->ModelId = argv[0];
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
  Model aux("Error", "Error","Error");
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

Model ModelModel::FindModel(std::string Id, sqlite3 *db){
  Model aux("Error", "Error", "Error");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Model WHERE ModelId = '" + Id + "'");
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
  std::string pSQL("INSERT OR IGNORE INTO Model(ModelId, Name, Brand) VALUES ('"
  + aux.ModelId + "', '" + aux.Name + "', '" + aux.BrandName + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelModel::DeleteFromTableModel(std::string ModelId, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Model WHERE ModelId = '" + ModelId + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}