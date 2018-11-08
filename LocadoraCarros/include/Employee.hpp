#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "Person.hpp"
#include "members.hpp"
#include "DataBank.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sqlite3.h>

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
    //!mostra em tela comentarios feitos sobre o funcionario
    void getComments() override;
};

class ModelEmployee{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackemployee(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Employee* FindEmployee(std::string Login, sqlite3 *db);

    static Employee* GiveEmployees(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableEmployee(Employee aux, sqlite3 *db);

    static flags DeleteFromTableEmployee(std::string CPF, sqlite3 *db);

};


#endif //EMPLOYEE_HPP