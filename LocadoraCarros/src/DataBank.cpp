#include "DataBank.hpp"

int GeneralBank::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

void GeneralBank::CheckDataBase(int rc){
  if(rc){
      std::cout << "Can't open database\n";
    }else{
      std::cout << "Open database successfully\n";
    }
}

void GeneralBank::ExitDataBase(flags X, sqlite3* db){
  if(X != RETURNOK){
    std::cout << "Erro! Saindo" << std::endl;
    if(db){
      sqlite3_close(db);
    }
    exit(0);
  } else if (X == RETURNOK){
  	std::cout << "Operação efetuada com sucesso" << std::endl;
  }
}

sqlite3* GeneralBank::CreateSchema(){
  sqlite3 *db;
  int rc;
  char *szErrMsg = nullptr;
  std::string content;
  std::ifstream myfile;
  
  myfile.open("Schema.sql");
  if(!myfile.is_open()){
    std::cout << "Não pode abrir arquivo" << std::endl;
    ExitDataBase(RETURNERROR, db);
  }
  content.assign( (std::istreambuf_iterator<char>(myfile) ), (std::istreambuf_iterator<char>())   );
  std::replace( content.begin(), content.end(), '\n', ' ');
  std::replace( content.begin(), content.end(), '\t', ' ');
  std::replace( content.begin(), content.end(), '\r', ' ');

  rc = sqlite3_open("AllocatorDataBank.db", &db);
  CheckDataBase(rc);
  if(rc != SQLITE_OK){
    return nullptr;
  }
  rc = sqlite3_exec(db, content.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return nullptr;
  }

  return db;
}