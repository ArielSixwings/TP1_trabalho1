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