#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <iostream>
#include <string>
#include "members.hpp"
/*!Representa as agencias da compania, todas as agencias possuem em comum a receita total e o
número total de vendas.
*/ 
class Agency : public Members{
public:
    static double generalrevenue;
    static double generalnumbersales; 
    std::string agencyId;
    std::string locality;
    double revenue;
    
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
    void getComments() override;
};

#endif //AGENCY_HPP