#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <iostream>
#include <string>
class Agency{
public:
    std::string agencyId;
    std::string locality;
    double Revenue;
public:   
    Agency(std::string agencyId, std::string locality,double Revenue);
    void SumRevenue(double salesrevenue);
    void getAgency();
};

#endif //AGENCY_HPP