#include "Exceptions.hpp"

int VerifyInputs(){
	std::string option_aux;
	int option;
	do{
		try{
			std::cin >> option_aux;
			option = stoi(option_aux, 0, 10);
		}
		catch(std::invalid_argument &exc){
			std::cout<<std::endl;
			std::cout<<"Insira alguma das opções: ";
			option = -1;
		}
	}while(option < 0);
	return option;
}