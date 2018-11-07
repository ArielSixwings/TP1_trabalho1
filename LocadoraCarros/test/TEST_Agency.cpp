#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Agency.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	REQUIRE(&A1 != NULL);
	REQUIRE((A1.agencyId).compare("074") == 0);
	REQUIRE((A1.locality).compare("Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil") == 0);
	REQUIRE(A1.revenue == 0.0);
}