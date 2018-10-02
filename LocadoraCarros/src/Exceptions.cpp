#include "Exceptions.hpp"

ExceptionsInputs::ExceptionsInputs(int a, int b){
	this->x = a;
	this->y = b;
}

int ExceptionsInputs::VerifyInputs(int a, int b){
	int given, aux;
	do{
		try{
			std::cin>>given;
			if(given < a || given > b){
				throw ExceptionsInputs(a, b);
			}else{
				aux = 0;
			}
		}
		catch(ExceptionsInputs& ex){
			std::cout<<"Insira um valor dentro do intervalo: ";
			aux = -1;
		}
	}while(aux < 0);
	return given;
}

std::string ExceptionsInputs::VerifyExactInputs(unsigned int a, int which){
	int aux;
	std::string word;
	switch (which){
		case PLACA:
			do{
				try{
					std::cin>>word;
					if(word.length() < a || word.length() > a){
						throw ExceptionsInputs(a, 0);
					}else{
						aux = 0;
					}
				}
				catch(ExceptionsInputs& ex){
					std::cout<<"Insira algo com " << a << " caracteres: ";
					aux = -1;
				}
			}while(aux < 0);
			return word;
		case CHASSI:
			do{
				try{
					std::cin>>word;
					if(word.length() < a || word.length() > a){
						throw ExceptionsInputs(a, 0);
					}else{
						aux = 0;
					}
				}
				catch(ExceptionsInputs& ex){
					std::cout<<"Insira algo com " << a << " caracteres: ";
					aux = -1;
				}
			}while(aux < 0);
			return word;
		case RENAVAM:
			do{
				try{
					std::cin>>word;
					if(word.length() < a || word.length() > a){
						throw ExceptionsInputs(a, 0);
					}else{
						aux = 0;
					}
				}
				catch(ExceptionsInputs& ex){
					std::cout<<"Insira algo com " << a << " caracteres: ";
					aux = -1;
				}
			}while(aux < 0);
			return word;
	}
	return "0";
}

std::string ExceptionsInputs::VerifyAgencyId(std::map<std::string, int> AgencysIdmap){
	int aux;
	std::string agencyid;
	do{
		try{
			std::cin>>agencyid;
			if(AgencysIdmap.find(agencyid) == AgencysIdmap.end()){
				throw ExceptionsInputs(0,0);
			}else{
				aux = 0;
			}
		}
		catch(ExceptionsInputs& ex){
			std::cout<<"Insira um valor valido para a agencia "<<std::endl;
			aux = -1;
		}
	}while(aux < 0);
	return agencyid;		
}

int VerifyTypeInputs(){
	std::string option_aux;
	int option;
	do{
		try{
			std::cin >> option_aux;
			option = stoi(option_aux, 0, 10);
		}
		catch(std::invalid_argument &exc){
			std::cout<<std::endl;
			std::cout<<"Insira algo do tipo inteiro: ";
			option = -1;
		}
	}while(option < 0);
	return option;
}

