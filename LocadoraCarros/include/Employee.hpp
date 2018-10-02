#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "Person.hpp"
#include <string>
/*!subclasse de pessoa, possui informações de login,senha e salário*/
class Employee : public Person{
public:
    int salary;
    std::string employeelogin;
    std::string employeepassword;
    //!auxiliar chamado pelo construtor para atribuir informações
    void SetEmployee(int salary, std::string employeelogin, std::string employeeassword);
public:
	using Person::Person;
    //!construtor da classe, recebe informações para chamar o construtor da classe pessoa
    Employee(std::string CPF,std::string Name, int Age, int salary,std::string employeelogin,std::string employeepassword);
    //!construtor da classe que recebe informações do terminal
    Employee();
    //!mostra em tela informações do funcionário:
    void ShowInformation() override;
    //!retorna o tipo da subclasse de pessoa, nesse caso,2 para empregado
    int ReturnType() override;
};

#endif //EMPLOYEE_HPP