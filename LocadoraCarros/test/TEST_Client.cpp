#include "catch2.hpp"
#include "Client.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
	Client Ana("06324683266","Ana Pinheiro Alto",29,"plimplim","simsalabim");
	REQUIRE(&Ana != NULL);
	REQUIRE((Ana.CPF).compare("06324683266") == 0);
	REQUIRE((Ana.Age).compare(29) == 0);
	REQUIRE((Ana.Name).compare("Ana Pinheiro Alto") == 0);
    REQUIRE((Ana.CustomerLogin).compare("plimplim") == 0);
    REQUIRE((Ana.CustomerPassword).compare("simsalabim") == 0);
}