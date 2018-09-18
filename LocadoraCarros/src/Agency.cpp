#include "Agency.hpp"

Agency::Agency(std::string agencyId,std::string locality,double Revenue)
{
    this->agencyId = agencyId;
    this->locality = locality;
    this->Revenue = Revenue;
}
void Agency::SumRevenue(double salesrevenue)
{
    Revenue += salesrevenue;
}

void Agency::getAgency()
{
    std::cout<<"Identificação da agencia: "<<agencyId <<std::endl;
    std::cout<<"Localidade: "<<locality<<std::endl;
    std::cout<<"Receita: "<<Revenue<<std::endl; 
}