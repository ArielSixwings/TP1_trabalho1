#include "Employee.hpp"

Employee::Employee(int CPF,std::string Name,int salary,std::string employeelogin,std::string employeepassword){
    this->CPF = CPF;
    this->Name = Name;
    this->salary = salary;
    this->employeelogin = employeelogin;
    this->employeepassword = employeepassword;    
}