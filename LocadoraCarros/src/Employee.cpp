#include "Employee.hpp"

void Employee::SetEmployee(int salary,std::string employeelogin,std::string employeepassword){
    this->salary = salary;
    this->employeelogin = employeelogin;
    this->employeepassword = employeepassword;
}

Employee::Employee(std::string CPF,std::string Name, int Age, 
	int salary,std::string employeelogin,std::string employeepassword) 
	: Person(CPF, Age, Name){
	SetEmployee(salary, employeelogin, employeepassword);
}

void Employee::ShowInformation(){
	std::cout<<"Funcionário" << std::endl;
	Person::ShowInformation();
	std::cout<<"Salário: " << salary << std::endl;
	std::cout<<"Login do Funcionário: " << employeelogin << std::endl;
	std::cout<<"Senha do Funcionário: " << employeepassword << std::endl;
}

int Employee::ReturnType(){
	return 2;
}

Employee::Employee(){
  std::cout<<"Salário: ";
  std::cin>>this->salary;
  std::cout<<"Login de Funcionário: ";
  std::cin>>this->employeelogin;
  std::cout<<"Senha de Funcionário: ";
  std::cin>>this->employeepassword;
}

void Employee::getComments(){
	std::cout << comments << std::endl;
}

// ########################################################################################## //

int ModelEmployee::callback(void *NotUsed, int argc, char **argv, char **szColName){
  for(int i = 0; i < argc; i++){
    std::cout << szColName[i] << " = " << argv[i] << std::endl;
  }

  std::cout << "\n";

  return 0;
}

int ModelEmployee::callbackemployee(void *data, int argc, char **argv, char **szColName){

  Employee* aux = static_cast<Employee*>(data);
  aux->CPF = argv[0];
  aux->Name =  argv[1];
  aux->Age = atoi(argv[2]);
  aux->salary = atoi(argv[3]);
  aux->employeelogin = argv[4];
  aux->employeepassword = argv[5];

  return 0;
}

int ModelEmployee::callbackcount(void *data, int argc, char **argv, char **szColName){

  int* aux = static_cast<int*>(data);
  *aux = (atoi(argv[0]));

    return 0;
}

Employee* ModelEmployee::GiveEmployees(int i, sqlite3 *db){
  Employee* aux = new Employee("0", "0", 0, 0, "0", "0");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Employee WHERE rowid = " + std::to_string(i+1));
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackemployee, aux, &szErrMsg);
    if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      return nullptr;
    }
    return aux;
}

int ModelEmployee::HowMany(sqlite3 *db){
  int* countEmp = (int*) malloc(sizeof(int));
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT COUNT(CPF) FROM Employee");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
  if(rc != SQLITE_OK){
      std::cout << "SQL Error: " << szErrMsg << std::endl;
      sqlite3_free(szErrMsg);
      free(countEmp);
      return 0;
    }
  return (*countEmp);
}

Employee* ModelEmployee::FindEmployee(std::string Login, sqlite3 *db){
  Employee* aux = new Employee("0", "0", 0, 0, "0", "0");
  char* szErrMsg = nullptr;
  std::string pSQL("SELECT * FROM Employee WHERE employeelogin = '" + Login + "'");
  int rc = sqlite3_exec(db, pSQL.c_str(), callbackemployee, aux, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return nullptr;
  }
  return aux;
}

flags ModelEmployee::InsertIntoTableEmployee(Employee aux, sqlite3 *db){
  char* szErrMsg = nullptr;
  std::string pSQL("INSERT OR IGNORE INTO Employee(CPF, Name, Age, salary, employeelogin, employeepassword) VALUES ('"
  + aux.CPF + "', '" + aux.Name + "', " + std::to_string(aux.Age) + ", " + std::to_string(aux.salary) + ", '" 
  + aux.employeelogin + "', '" + aux.employeepassword + "')");
  int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  if(rc != SQLITE_OK){
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
    return RETURNERROR;
  }
  return RETURNOK;
}

flags ModelEmployee::DeleteFromTableEmployee(std::string CPF, sqlite3 *db){
	char* szErrMsg = nullptr;
  	std::string pSQL("DELETE FROM Employee WHERE CPF = '" + CPF + "'");
  	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
  	if(rc != SQLITE_OK){
  	  std::cout << "SQL Error: " << szErrMsg << std::endl;
  	  sqlite3_free(szErrMsg);
  	  return RETURNERROR;
  	}
  	return RETURNOK;	
}