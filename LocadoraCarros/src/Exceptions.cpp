#include "Exceptions.hpp"
#include "Person.hpp"

ExceptionsInputs::ExceptionsInputs(int a, int b){
	this->x = a;
	this->y = b;
}

ExceptionsInputs::ExceptionsInputs(std::string AUX){
	this->aux = AUX;
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
			while(1){
				try{
					std::cin >>word;
					ExceptionsInputs::VerifyBoardInputs(word, a);
				}
				catch(ExceptionsInputs& ex){
					continue;
				}
				break;
			}
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
						word = ExceptionsInputs::VerifyOnlyNumbersInputs(word);
						if(word.length() < a || word.length() > a){
							throw ExceptionsInputs(a, 0);
						}
						aux = 0;
					}
				}
				catch(ExceptionsInputs& ex){
					std::cout<<"Insira algo com " << a << " caracteres: ";
					aux = -1;
				}
			}while(aux < 0);
			return word;
		case cpf:
			do{
				try{
					std::cin>>word;
					if(word.length() < a || word.length() > a){
						throw ExceptionsInputs(a, 0);
					}
					else{
						word = ExceptionsInputs::VerifyOnlyNumbersInputs(word);
						if(word.length() < a || word.length() > a){
							throw ExceptionsInputs(a, 0);
						}
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
			std::cout<<"Insira um valor valido para a agência: ";
			aux = -1;
		}
	}while(aux < 0);
	return agencyid;		
}

std::string ExceptionsInputs::VerifyCPF(std::vector <Person*> People){
	int aux;
	std::string cpf;
	do{
		try{
			std::cin>>cpf;
			if(SearchInList(People, cpf) == 0){
				throw ExceptionsInputs(cpf);
			}
			else{
				aux = 0;
			}
		}
		catch(ExceptionsInputs& ex){
			std::cout<<"CPF não cadastrado, insira alguém cadastrado: "<<std::endl;
			aux = -1;
		}
	}while(aux < 0);
	return cpf;
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

void ExceptionsInputs::VerifyBoardInputs(std::string word, unsigned int a){
	if(word.length() < a || word.length() > a){
		std::cout<<"Insira algo com 7 caracteres: ";
		throw ExceptionsInputs(a, 0);
	}
	for(int i = 0; i < 3; i++){
		if(!std::isupper(word[i])){
			std::cout<<"Algum dos 3 primeiros dígitos não é uma letra maiúscula! Insira a placa novamente: ";
			throw ExceptionsInputs(a, 0);		
		}
	}
	for(int i = 3; i < 7; i++){
		if(!std::isdigit(word[i])){
			std::cout<<"Algum dos 4 últimos dígitos não é um número! Insira a placa novamente: ";
			throw ExceptionsInputs(a, 0);		
		}
	}
}

std::string ExceptionsInputs::VerifyOnlyNumbersInputs(std::string word){
	int aux;
	do{
		try{
			int i;
			for(i = 0; i < (int)word.size(); i++){
				if((int)word[i] < 48 || (int)word[i] > 57){
					throw ExceptionsInputs(word);
				}
			}
			aux = 0;
		}
		catch(ExceptionsInputs &ex){
			std::cout<<std::endl;
			std::cout<<"Insira apenas números: ";
			std::cin >>word;
		}
	}while(aux < 0);
	return word;
}

std::string ExceptionsInputs::VerifyBrandsInputs(std::vector <std::string> Brands){
	int aux = -1;
	std::string word;
	do{
		try{
			int i;
			std::cin>>word;
			for(i = 0; i < (int)Brands.size(); i++){
				if(word == Brands[i]){
					aux = 0;
					break;
				}
			}
			if(aux == -1){
				throw ExceptionsInputs(word);
			}
		}
		catch(ExceptionsInputs &ex){
			std::cout<<std::endl;
			std::cout<<"Insira uma marca listada: ";
		}
	}while(aux < 0);
	return word;	
}

std::string ExceptionsInputs::VerifyModelsInputs(std::string Brand, std::vector <std::vector <std::string>> Models){
	int aux = -1;
	std::string word;
	do{
		try{
			std::cin>>word;
			if(Brand == "Chevrolet"){
				if(word == Models[0][0] || word == Models[0][1] || word == Models[0][2]){
					aux = 0;
				}
				else{
					throw ExceptionsInputs(word);
				}
			}
			if(Brand == "BMW"){
				if(word == Models[1][0] || word == Models[1][1] || word == Models[1][2]){
					aux = 0;
				}
				else{
					throw ExceptionsInputs(word);
				}
			}
			if(Brand == "Ford"){
				if(word == Models[2][0] || word == Models[2][1] || word == Models[2][2]){
					aux = 0;
				}
				else{
					throw ExceptionsInputs(word);
				}
			}
			if(Brand == "Tesla"){
				if(word == Models[3][0] || word == Models[3][1] || word == Models[3][2]){
					aux = 0;
				}
				else{
					throw ExceptionsInputs(word);
				}
			}
		}
		catch(ExceptionsInputs &ex){
			std::cout<<std::endl;
			std::cout<<"Modelo " << ex.aux << " inserido não pertence a marca " << Brand << "!" << std::endl;
			std::cout<<"Insira um modelo válido: ";
			aux = -1;
		}
	}while(aux < 0);
	return word;	
}