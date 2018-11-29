#include "Exceptions.hpp"
#include "Alocation.hpp"
#include "Vehicles.hpp"

Alocation::Alocation(int id){
	this->AlocationId = id;
}

Alocation::Alocation(int id, std::vector <int>  alocationData, std::vector <int>  alocationHour, std::vector <int>  devolutionData, std::vector <int>  devolutionHour){
	this->AlocationId = id;
	this->AlocationData = alocationData;
	this->DevolutionData = devolutionData;
	this->AlocationHour = alocationHour;
	this->DevolutionHour = devolutionHour;
}

// se a alocação for por dia, a data e hora de devolução são inseridas posteriormente
Alocation::Alocation(int id, int which,std::string agency,bool byperiod, std::string cpf, double price){
	int day, month, year, hour, minutes;

	whichvehicle = which;
	this->AlocationId = id;
	this->agency = agency;
	this->cost = price;

	CustomerId = cpf;
	std::cout<<"Insira a o dia da data de alocação: ";
	day = VerifyTypeInputs();
	AlocationData.push_back(day);
	std::cout<<"Insira a o mês da data de alocação: ";
	month = VerifyTypeInputs();
	AlocationData.push_back(month);
	std::cout<<"Insira a o ano da data de alocação: ";
	year = VerifyTypeInputs();
	AlocationData.push_back(year);
	std::cout<<"Insira a hora de alocação: ";
	hour = VerifyTypeInputs();
	AlocationHour.push_back(hour);
	std::cout<<"Insira os minutos de alocação: ";
	minutes = VerifyTypeInputs();
	AlocationHour.push_back(minutes);

	if(byperiod){
		Type = "byperiod";

		std::cout<<"Insira a o dia da data de devolução: ";
		day = VerifyTypeInputs();
		DevolutionData.push_back(day);
		std::cout<<"Insira a o mês da data de devolução: ";
		month = VerifyTypeInputs();
		DevolutionData.push_back(month);
		std::cout<<"Insira a o ano da data de devolução: ";
		year = VerifyTypeInputs();
		DevolutionData.push_back(year);
		std::cout<<"Insira a hora de devolução: ";
		hour = VerifyTypeInputs();
		DevolutionHour.push_back(hour);
		std::cout<<"Insira os minutos de devolução: ";
		minutes = VerifyTypeInputs();
		DevolutionHour.push_back(minutes);
		std::cout<< std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(price, 1)  << " reais" << std::endl;
	}
	else{
		Type = "daily";
		std::cout<<"Insira a quantidade de dias que se pretende alugar o veículo: ";
		days = VerifyTypeInputs();
		std::cout<< std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(price, 0) << " reais" << std::endl;
	}


}

Alocation::~Alocation(){
}

void Alocation::getAlocation(){
	std::cout << std::endl;
	std::cout<<"Chave do Veículo: " << whichvehicle << std::endl;
	std::cout<<"CPF do cliente: " << CustomerId << std::endl;
	std::cout<<"Data de Alocação: " << AlocationData[0] << "/" << AlocationData[1] << "/" << AlocationData[2] << std::endl;
	std::cout<<"Hora de Alocação: " << AlocationHour[0] << ":" << AlocationHour[1] << std::endl;

	if(Type.compare(0,5,"daily") == 0){
		std::cout<<"Carro alugado por diária"<<std::endl;
		std::cout<<days<<" Dias"<<std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(cost, 0) << " reais" << std::endl;
	}
	else{
		std::cout<<"Data de Devolução: " << DevolutionData[0] << "/" << DevolutionData[1] << "/" << DevolutionData[2] << std::endl;
		std::cout<<"Hora de Devolução: " << DevolutionHour[0] << ":" << DevolutionHour[1] << std::endl;
		std::cout<<"Valor Total: " << (double)CalculateCost(cost, 1)  << " reais" << std::endl;
	}
}

double Alocation::CalculateCost(double Price, int byperiod){
	if(byperiod){
		return howmanydays() * Price;
	}
	else{
		return days * Price;
	}
}

int Alocation::howmanydays(){
	struct std::tm timeAlocation = {0,0,0,AlocationData[0],
	(AlocationData[1]-1),(AlocationData[2] - 1900)}; /* 000 is 1900 */
	struct std::tm timeDevolution = {0,0,0,DevolutionData[0],
	(DevolutionData[1]-1),(DevolutionData[2] - 1900)};
	    
	std::time_t x = std::mktime(&timeAlocation);
	std::time_t y = std::mktime(&timeDevolution);
	double difference;
	if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) ){
	    difference = std::difftime(y, x) / (60 * 60 * 24);
	}
	return difference;
}

std::vector <int> String_to_vecInt(std::string arg, int type){
	char capture;
	std::string auxcapture = "";
	std::stringstream saux(arg);
	std::vector <int> aux;
	switch (type){
		case 0:
			while (saux.get(capture)){
				if (capture == '/'){
					aux.push_back(stoi(auxcapture));
					auxcapture = "";
				}
				else{
					auxcapture += capture;
				}
			}
			aux.push_back(stoi(auxcapture));
			break;
		case 1:
			while (saux.get(capture)){
				if (capture == ':'){
					aux.push_back(stoi(auxcapture));
					auxcapture = "";
				}
				else{
					auxcapture += capture;
				}
			}
			aux.push_back(stoi(auxcapture));
			break;
	}
	return aux;
}

// ########################################################################################## //

int ModelAlocation::callback(void *NotUsed, int argc, char **argv, char **szColName){
	for (int i = 0; i < argc; i++){
		std::cout << szColName[i] << " = " << argv[i] << std::endl;
	}

	std::cout << "\n";

	return 0;
}

int ModelAlocation::callbackalocation(void *data, int argc, char **argv, char **szColName){

	Alocation *aux = static_cast<Alocation*>(data);
	aux->AlocationId = atoi(argv[0]);
	aux->whichvehicle = atoi(argv[1]);
	aux->Type = argv[2];
	aux->CustomerId = argv[3];
	aux->cost = atof(argv[4]);

	
	aux->AlocationData = String_to_vecInt(argv[5], 0);
	aux->AlocationHour = String_to_vecInt(argv[6], 1);
	aux->DevolutionData = String_to_vecInt(argv[7], 0);
	aux->DevolutionHour = String_to_vecInt(argv[8], 1);
	aux->agency = argv[9];
	

	return 0;
}

int ModelAlocation::callbackcount(void *data, int argc, char **argv, char **szColName){

	int *aux = static_cast<int *>(data);
	*aux = (atoi(argv[0]));

	return 0;
}

Alocation ModelAlocation::GiveAlocations(int i, sqlite3 *db){
	Alocation aux(0);
	char *szErrMsg = nullptr;
	std::string pSQL("SELECT * FROM Alocation WHERE rowid = " + std::to_string(i));
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackalocation, &aux, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return aux;
	}
	return aux;
}

int ModelAlocation::HowMany(sqlite3 *db){
	int *countEmp = (int *)malloc(sizeof(int));
	char *szErrMsg = nullptr;
	std::string pSQL("SELECT COUNT(AlocationId) FROM Alocation");
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackcount, countEmp, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		free(countEmp);
		return 0;
	}
	return (*countEmp);
}

Alocation ModelAlocation::FindAlocation(int AlocationId, sqlite3 *db){
	Alocation aux(0);
	char *szErrMsg = nullptr;
	std::string pSQL("SELECT * FROM Alocation WHERE AlocationId = " + std::to_string(AlocationId));
	int rc = sqlite3_exec(db, pSQL.c_str(), callbackalocation, &aux, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return aux;
	}
	return aux;
}

flags ModelAlocation::InsertIntoTableAlocation(bool type, Alocation aux, sqlite3 *db){
	char *szErrMsg = nullptr;

	std::string AlocData = std::to_string(aux.AlocationData[0]) + "/" 
	+ std::to_string(aux.AlocationData[1]) + "/" + std::to_string(aux.AlocationData[2]);
	std::string AlocHour = std::to_string(aux.AlocationHour[0]) + ":" 
	+ std::to_string(aux.AlocationHour[1]);

	if(type){
		std::string DevData = std::to_string(aux.DevolutionData[0]) + "/" 
		+ std::to_string(aux.DevolutionData[1]) + "/" + std::to_string(aux.DevolutionData[2]);
		std::string DevHour = std::to_string(aux.DevolutionHour[0]) + ":" 
		+ std::to_string(aux.DevolutionHour[1]);

		std::string pSQL("INSERT OR IGNORE INTO Alocation(AlocationId, Vehicle, TypeAloc, CustomerCPF, Price,\
		AlocationData, AlocationHour, DevolutionData, DevolutionHour, Agency) VALUES (" 
		+ std::to_string(aux.AlocationId) + ", " + std::to_string(aux.whichvehicle)
		+ ", '" + aux.Type + "', '" + aux.CustomerId + "', " 
		+ std::to_string(aux.cost) + ", '" + AlocData + "', '" + AlocHour + "', '" + DevData 
		+ "', '" + DevHour + "', '" + aux.agency + "')");
		int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
		if (rc != SQLITE_OK){
			std::cout << "SQL Error: " << szErrMsg << std::endl;
			sqlite3_free(szErrMsg);
			return RETURNERROR;
		}
		return RETURNOK;
	}
	else{
		std::string pSQL("INSERT OR IGNORE INTO Alocation(AlocationId, Vehicle, TypeAloc, CustomerCPF, Price,\
		AlocationData, AlocationHour, Agency) VALUES (" 
		+ std::to_string(aux.AlocationId) + ", " + std::to_string(aux.whichvehicle) + ", '" 
		+ aux.Type + "', '" + aux.CustomerId + "', " + std::to_string(aux.cost) + ", '" 
		+ AlocData + "', '" + AlocHour + "', '" + aux.agency + "')");
		int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
		if (rc != SQLITE_OK){
			std::cout << "SQL Error: " << szErrMsg << std::endl;
			sqlite3_free(szErrMsg);
			return RETURNERROR;
		}
		return RETURNOK;
	}

}

flags ModelAlocation::DeleteFromTableAlocation(int Id, sqlite3 *db){
	char *szErrMsg = nullptr;
	std::string pSQL("DELETE FROM Alocation WHERE AlocationId = " + std::to_string(Id));
	int rc = sqlite3_exec(db, pSQL.c_str(), callback, 0, &szErrMsg);
	if (rc != SQLITE_OK){
		std::cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);
		return RETURNERROR;
	}
	return RETURNOK;
}

std::vector<Alocation> ModelAlocation::GetAlocations(sqlite3 *db){
	int i;
	std::vector<Alocation> aux;
	for (i = 0; i < ModelAlocation::HowMany(db); i++){
		Alocation auxAlo = ModelAlocation::GiveAlocations(i, db);
		aux.push_back(auxAlo);
	}
	return aux;
}