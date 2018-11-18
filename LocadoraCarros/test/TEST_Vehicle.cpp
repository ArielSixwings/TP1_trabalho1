#include "catch2.hpp"
#include "Vehicle.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
    Vehicle car(0, "VEG4064", "RED", "ALCOHOL", "3KI8S30KMN14IOM40",
        2015, 4, 923844.0, "00184729834", "Fusion", "Ford", 103.5,93.15);
	REQUIRE(&car != NULL);
    REQUIRE(car.Key).compare(0) == 0);
	REQUIRE(car.Board).compare("VEG4064") == 0);
	REQUIRE(car.Color).compare("RED") == 0);
	REQUIRE(car.TypeFuel).compare("ALCOHOL") == 0);
    REQUIRE(car.Chassi).compare("3KI8S30KMN14IOM40") == 0);
    REQUIRE(car.Year).compare(2015) == 0);
    REQUIRE(car.howmanydays).compare(4) == 0);
    REQUIRE(car.Distance).compare(923844.0) == 0);
    REQUIRE(car.renavam.compare("00184729834") == 0);
    REQUIRE(car.Model).compare("Fusion") == 0);
    REQUIRE(car.Brand).compare("Ford") == 0);
    REQUIRE(car.Priceperday).compare(103.5) == 0);
    REQUIRE(car.Priceperperiod).compare(93.15) == 0);
}