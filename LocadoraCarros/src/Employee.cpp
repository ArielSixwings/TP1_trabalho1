#include <iostream>
#include <string>
#include "Employee.hpp"

void Employee::SetEmployee(int salary,std::string employeelogin,std::string employeepassword){
    this->salary = salary;
    this->employeelogin = employeelogin;
    this->employeepassword = employeepassword;
}

Employee::Employee(std::string CPF,std::string Name, int Age, int salary,std::string employeelogin,std::string employeepassword) : Person(CPF, Age, Name){
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