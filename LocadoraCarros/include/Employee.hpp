#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "Person.hpp"
#include <string>

class Employee : public Person{
public:
    int salary;
    std::string employeelogin;
    std::string employeepassword;
public:
	using Person::Person;
    Employee(std::string CPF,std::string Name, int Age, int salary,std::string employeelogin,std::string employeepassword);
    Employee();
    void SetEmployee(int salary, std::string employeelogin, std::string employeeassword);
    void ShowInformation() override;
    int ReturnType() override;
};

#endif //EMPLOYEE_HPP