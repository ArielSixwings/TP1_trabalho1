// #include "catch2.hpp"
// #include "Client.hpp"
// #include "Exceptions.hpp"
// #include <string>

// const std::map<std::string, int> AgencysIdmap = {
//   {"074",0},{"893",1},{"182",2}
// };

// TEST_CASE("ConstructorTest") {
//     Vehicle car(0, "VEG4064", "RED", "ALCOHOL", "3KI8S30KMN14IOM40",
// 	 	2015, 4, 923844.0, "00184729834", "Fusion", "Ford", 103.5,93.15);
// 	Client Ana("06324683266",29,"Ana Pinheiro Alto",5000,"plimplim","simsalabim");
//     Agency agency("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
//     auxagencyid = ExceptionsInputs::VerifyAgencyId(AgencysIdmap);
//     Alocation aux(car.Key,auxagencyid,true, Ana.CPF, car.Priceperperiod);
// 	REQUIRE(&Ana != NULL);
// 	REQUIRE((Ana.CPF).compare("06324683266") == 0);
// 	REQUIRE((Ana.Age).compare(29) == 0);
// 	REQUIRE(Ana.Name).compare("Ana Pinheiro Alto") == 0);
//     REQUIRE(Ana.CustomerLogin).compare("plimplim") == 0);
//     REQUIRE(Ana.CustomerPassword).compare("simsalabim") == 0);
// }