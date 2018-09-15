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