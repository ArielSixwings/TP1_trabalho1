#include "Agency.hpp"

double Agency::generalrevenue;
double Agency::generalnumbersales;

Agency::Agency(std::string agencyId,std::string locality,double revenue){
    this->agencyId = agencyId;
    this->locality = locality;
    this->revenue = revenue;
}

void Agency::sumRevenue(double salesrevenue){
    revenue += salesrevenue;
}

void Agency::getAgency(){
    std::cout<<"Identificação da agencia: "<<agencyId <<std::endl;
    std::cout<<"Localidade: "<<locality<<std::endl;
    std::cout<<"Receita: "<<revenue<<std::endl;
}

void Agency::getGeneralData(){
    std::cout<<"Receita geral da soma das agencias: "<< generalrevenue << std::endl;
    std::cout<<"Numero total de vendas: "<<generalnumbersales << std::endl;
}

void Agency::sumGeneralRevenue(double salesrevenue){
    generalrevenue += salesrevenue;
    generalnumbersales++; 
}

void Agency::startSalesMonth(){
    revenue = 0;
    generalrevenue = 0;
    generalnumbersales = 0;
}

void Agency::getComments(){
	std::cout << this->comments << std::endl;
}

// ########################################################################################## //

int ModelAgency::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelAgency::callbackagency(void *data, int argc, char **argv, char **szColName){

  Agency* aux = static_cast<Agency*>(data);
  aux->agencyId = argv[0];
  aux->locality =  argv[1];
  aux->revenue = atoi(argv[2]);

  return 0;
}

int ModelAgency::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}

Agency ModelAgency::GiveAgencys(int i, sqlite3 *db){
  Agency aux("0", "Error", 0);
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Agency WHERE rowid = " + std::to_string(i+1));
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackagency, &aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return aux;
    }
    return aux;
}

int ModelAgency::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(agencyId) FROM Agency");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Agency ModelAgency::FindAgency(std::string Id, sqlite3 *db){
  Agency aux("0", "Error", 0);
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Agency WHERE agencyId = '" + Id + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackagency, &aux, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return aux;
  }
  return aux;
}

flags ModelAgency::InsertIntoTableAgency(Agency aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Agency(agencyId, locality, revenue) VALUES ('"
  + aux.agencyId + "', '" + aux.locality + "', " + std::to_string(aux.revenue) + ")");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelAgency::DeleteFromTableAgency(std::string agencyId, sqlite3 *db){
    char* szErrMsg = nullptr;
    std::string pSQL("DELETE FROM Agency WHERE agencyId = '" + agencyId + "'");
    int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return RETURNERROR;
    }
    return RETURNOK;    
}

std::vector<Agency> ModelAgency::GetAgencys(sqlite3 *db){
  std::vector<Agency> aux;
  for (int i = 0; i < ModelAgency::HowMany(db); i++){
    Agency auxAgy = ModelAgency::GiveAgencys(i, db);
    aux.push_back(auxAgy);
  }
  return aux;
}