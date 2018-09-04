#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>
#include "Person.hpp"

class Employee : public Person{
    int salary;
    std::string employeelogin;
    std::string employeepassword;
    Employee(int CPF,std::string Name,int salary,std::string employeelogin,std::string employeepassword);
};

#endif //EMPLOYEE_HPP