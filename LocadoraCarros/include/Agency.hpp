#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <iostream>
#include <string>

class Agency{
    static double generalrevenue;
    static double generalnumbersales; 
public:
    std::string agencyId;
    std::string locality;
    double revenue;
public:
    Agency(std::string agencyId, std::string locality,double revenue);
    void sumRevenue(double salesrevenue);
    void getAgency();
    static void getGeneralData();
    static void sumGeneralRevenue(double salesrevenue);
    void startSalesMonth();
};

#endif //AGENCY_HPP