#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Client.hpp"
#include "Agency.hpp"
#include "Alocation.hpp"
#include "Exceptions.hpp"
#include "Vehicles.hpp"
#include <string>

const std::map<int, int> AgencysIdmap = {
  {074,0},{893,1},{182,2}
};

TEST_CASE("ConstructorTest") {
    Vehicle car(0, "VEG4064", "RED", "ALCOHOL", "3KI8S30KMN14IOM40",
	 	2015, 4, 923844.0, "00184729834", "Fusion", "Ford", 103.5,93.15);
	Client Ana("06324683266","Ana Pinheiro Alto", 29,"plimplim","simsalabim");
    Agency agency("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
    int auxagencyid = ExceptionsInputs::VerifyAgencyId(AgencysIdmap);
    Alocation aux(0, car.Key,std::to_string(auxagencyid),true, Ana.CPF, car.Priceperperiod);
	REQUIRE(&Ana != NULL);
	REQUIRE((Ana.CPF).compare("06324683266") == 0);
	REQUIRE((Ana.Name).compare("Ana Pinheiro Alto") == 0);
	REQUIRE(Ana.Age == 29);
    REQUIRE((Ana.CustomerLogin).compare("plimplim") == 0);
    REQUIRE((Ana.CustomerPassword).compare("simsalabim") == 0);
}