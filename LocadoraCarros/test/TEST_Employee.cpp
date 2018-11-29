#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "Employee.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
	Employee Pedro("06324683266","Pedro Pereira Blumenau", 29, 5000,"pedroba2s","xablau");
	REQUIRE(&Pedro != NULL);
	REQUIRE((Pedro.CPF).compare("06324683266") == 0);
	REQUIRE(Pedro.Age == 29);
	REQUIRE((Pedro.Name).compare("Pedro Pereira Blumenau") == 0);
    REQUIRE((Pedro.employeelogin).compare("pedroba2s") == 0);
    REQUIRE((Pedro.employeepassword).compare("xablau") == 0);
}