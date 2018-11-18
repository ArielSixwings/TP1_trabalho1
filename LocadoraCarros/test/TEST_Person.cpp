#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Person.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
	Person Alam("06324683266",19,"Alam Castro Pinto");
	REQUIRE(&Alam != NULL);
	REQUIRE((Alam.CPF).compare("06324683266") == 0);
	REQUIRE((Alam.Age).compare(19) == 0);
	REQUIRE(Alam.Name).compare("Alam Castro Pinto") == 0);
}