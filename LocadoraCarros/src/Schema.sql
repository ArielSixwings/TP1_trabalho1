CREATE TABLE IF NOT EXISTS Employee(
	CPF char(11) PRIMARY KEY,
	Name varchar(100),
    Age INTEGER,
	salary INTEGER,
    employeelogin varchar(50) UNIQUE,
    employeepassword varchar(50)
	);

CREATE TABLE IF NOT EXISTS Client(
	CPF char(11) PRIMARY KEY,
	Name varchar(100),
    Age INTEGER,
    CustomerLogin varchar(50) UNIQUE,
    CustomerPassword varchar(50)
	);

CREATE TABLE IF NOT EXISTS Person(
	CPF char(11) PRIMARY KEY,
    Age INTEGER,
	Name varchar(100)
	);

CREATE TABLE IF NOT EXISTS Agency(
	agencyId VARCHAR(3) PRIMARY KEY,
    locality VARCHAR(150) NOT NULL,
	revenue REAL NOT NULL
	);

CREATE TABLE IF NOT EXISTS Brand(
	Name VARCHAR(150) PRIMARY KEY,
	NumberOfModels INTEGER NOT NULL
	);

CREATE TABLE IF NOT EXISTS Model(
	ModelId VARCHAR(3) PRIMARY KEY,
    Name VARCHAR(150) NOT NULL,
    Brand VARCHAR(150) NOT NULL,
    FOREIGN KEY(Brand) REFERENCES Brand(Name)
	);

-- CREATE TABLE IF NOT EXISTS Vehicle(
-- 	VehicleKey INTEGER PRIMARY KEY,
-- 	Alocated INTEGER NOT NULL,
-- 	RENAVAM CHAR(11) NOT NULL,
-- 	Board CHAR(7) NOT NULL,
-- 	Color VARCHAR(10) NOT NULL,
-- 	TypeFuel VARCHAR(15) NOT NULL,
-- 	CHASSI CHAR(17) NOT NULL,
-- 	Year INTEGER NOT NULL,
-- 	Doors INTEGER NOT NULL,
-- 	PerDay REAL NOT NULL,
-- 	PerPeriod REAL NOT NULL,
-- 	ModelId VARCHAR(3) NOT NULL,
-- 	FOREIGN KEY(Model) REFERENCES Model(ModelId)
-- 	);

