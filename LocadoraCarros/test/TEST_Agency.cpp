#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch2.hpp"
#include "Agency.hpp"
#include <string>

TEST_CASE("ConstructorTest") {
	std::cout<< "ConstructorTest" << std::endl;
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	REQUIRE(&A1 != NULL);
	std::cout<<"Testado com sucesso alocação da Agência" << std::endl;
	REQUIRE((A1.agencyId).compare("074") == 0);
	std::cout<<"Testado com sucesso agencyId da Agência" << std::endl;
	REQUIRE((A1.locality).compare("Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil") == 0);
	std::cout<<"Testado com sucesso locality da Agência" << std::endl;
	REQUIRE(A1.revenue == 0.0);
	std::cout<<"Testado correto revenue da Agência" << std::endl;
	std::cout<< std::endl;
}

TEST_CASE("sumGeneralRevenueTest") {
	std::cout<< "sumGeneralRevenueTest" << std::endl;
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	A1.sumGeneralRevenue(10.0);
	REQUIRE(A1.generalrevenue == 10.0);
	std::cout<<"Testado com sucesso generalrevenue da Agência" << std::endl;
	REQUIRE(A1.generalnumbersales == 1);
	std::cout<<"Testado com sucesso generalnumbersales da Agência" << std::endl;
	std::cout<< std::endl;
}

TEST_CASE("sumRevenueTest") {
	std::cout<< "sumRevenueTest" << std::endl;
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	A1.sumRevenue(10.0);
	REQUIRE(A1.revenue == 10.0);
	std::cout<<"Testado com sucesso revenue da Agência" << std::endl;
	std::cout<< std::endl;
}

TEST_CASE("startSalesMonthTest") {
	std::cout<< "startSalesMonthTest" << std::endl;
	Agency A1("074","Aeroporto de Brasília, Juscelino Kubitschek, BSB, Brasil",0.0);
	A1.startSalesMonth();
	REQUIRE(A1.revenue == 0);
	std::cout<<"Testado com sucesso revenue da Agência" << std::endl;
	REQUIRE(A1.generalrevenue == 0);
	std::cout<<"Testado com sucesso generalrevenue da Agência" << std::endl;
	REQUIRE(A1.generalnumbersales == 0);
	std::cout<<"Testado com sucesso generalnumbersales da Agência" << std::endl;
	std::cout<< std::endl;
}