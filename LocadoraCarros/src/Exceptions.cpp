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
			do{
				try{
					std::cin>>word;
					if(word.length() < a || word.length() > a){
						throw ExceptionsInputs(a, 0);
					}
					else{
						word = ExceptionsInputs::VerifyBoardLettersInputs(word);
						if(word.length() < a || word.length() > a){
							throw ExceptionsInputs(a, 0);
						}
						word = ExceptionsInputs::VerifyBoardNumbersInputs(word);
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
			std::cout<<"Insira um valor valido para a agencia "<<std::endl;
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

std::string ExceptionsInputs::VerifyBoardLettersInputs(std::string word){
	int aux;
	do{
		try{
			if(((int)word[0] < 65 || (int)word[0] > 90) || ((int)word[1] < 65 || (int)word[1] > 90) || ((int)word[2] < 65 || (int)word[2] > 90)){
				throw ExceptionsInputs(0, 0);
			}
			else{
				aux = 0;
			}
		}
		catch(ExceptionsInputs &ex){
			std::cout<<std::endl;
			std::cout<<"Algum dos 3 primeiros dígitos não é uma letra maiúscula! Insira novamente: ";
			std::cin >>word;
			aux = -1;
		}
	}while(aux < 0);
	return word;
}

std::string ExceptionsInputs::VerifyBoardNumbersInputs(std::string word){
	int aux;
	do{
		try{
			if(((int)word[3] < 48 || (int)word[3] > 57) || ((int)word[4] < 48 || (int)word[4] > 57) || ((int)word[5] < 48 || (int)word[5] > 57) || ((int)word[6] < 48 || (int)word[6] > 57)){
				throw ExceptionsInputs(word);
			}
			else{
				aux = 0;
			}
		}
		catch(ExceptionsInputs &ex){
			std::cout<<std::endl;
			std::cout<<"Algum dos 4 últimos dígitos não é um número! Insira novamente: ";
			std::cin >>word;
			aux = -1;
		}
	}while(aux < 0);
	return word;
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
