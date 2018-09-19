#include "Agency.hpp"

double Agency::generalrevenue;
double Agency::generalnumbersales;

Agency::Agency(std::string agencyId,std::string locality,double revenue)
{
    this->agencyId = agencyId;
    this->locality = locality;
    this->revenue = revenue;
}
void Agency::sumRevenue(double salesrevenue)
{
    revenue += salesrevenue;
}

void Agency::getAgency()
{
    std::cout<<"Identificação da agencia: "<<agencyId <<std::endl;
    std::cout<<"Localidade: "<<locality<<std::endl;
    std::cout<<"Receita: "<<revenue<<std::endl;
}
void Agency::getGeneralData()
{
    std::cout<<"Receita geral da soma das agencias: "<< generalrevenue << std::endl;
    std::cout<<"Numero total de vendas: "<<generalnumbersales << std::endl;
}
void Agency::sumGeneralRevenue(double salesrevenue)
{
    generalrevenue += salesrevenue;
    generalnumbersales++; 
}

void Agency::startSalesMonth()
{
    revenue = 0;
    generalrevenue = 0;
    generalnumbersales = 0;
}