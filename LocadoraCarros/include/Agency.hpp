#ifndef AGENCY_HPP
#define AGENCY_HPP
#include <iostream>
#include <string>
#include "DataBank.hpp"
#include "members.hpp"
/*!Representa as agencias da compania, todas as agencias possuem em comum a receita total e o
número total de vendas.
*/ 
class Agency : public Members{
public:
    std::string agencyId;
    std::string locality;
    double revenue;
    static double generalrevenue;
    static double generalnumbersales; 
    
    //!soma à receita geral da compania a receita da ultima venda, é chamada por sumRevenue
    static void sumGeneralRevenue(double salesrevenue);    
public:
    //!construtor da classe, não atribui valor à receita total e ao numero total de vendas
    Agency(std::string agencyId, std::string locality,double revenue);
    //!soma à receita da agencia a receita da venda atual, em seguida chama sumGeneralRevenue
    void sumRevenue(double salesrevenue);
    //!mostra na tela informações específicas da agencia
    void getAgency();
    //!mostra em tela dados compartilhados entre as agencias
    static void getGeneralData();
    //!zera a receita de todas as receitas e a receita geral
    void startSalesMonth();
    //!mostra em tela os comentarios feitos pelos clientes sobre a agencia
    void getComments() override;
};

class ModelAgency{
public:

    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

    static int callbackagency(void* data, int argc, char **argv, char **szColName);

    static int callbackcount(void *data, int argc, char **argv, char **szColName);

    static Agency FindAgency(std::string Id, sqlite3 *db);

    static Agency GiveAgencys(int i, sqlite3 *db);

    static int HowMany(sqlite3 *db);

    static flags InsertIntoTableAgency(Agency aux, sqlite3 *db);

    static flags DeleteFromTableAgency(std::string agencyId, sqlite3 *db);

    static std::vector<Agency> GetAgencys(sqlite3 *db);
};

#endif //AGENCY_HPP