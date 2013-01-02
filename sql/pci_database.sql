
-- Database creation
CREATE DATABASE pci_database;
USE pci_databse;


-- Application user creation
CREATE USER 'pci_user'@'localhost' IDENTIFIED BY 'pci_user';


-- Table definitions

CREATE TABLE Clarification(
	answer VARCHAR(MAX_CHAR_ANSWER),
	associated_publication_id TIPODEID NOT NULL,
	creator_user_name VARCHAR(MAX_CHAR_USER_NAME) NOT NULL,
	id TIPODEID NOT NULL,
	question VARCHAR(MAX_CHAR_QUESTION) NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(associated_publication_id) REFERENCES Publication(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
);

CREATE TABLE User(
	birth_date DATE NOT NULL,
email VARCHAR(MAX_CHAR_EMAIL) NOT NULL,
	first_name VARCHAR(MAX_CHAR_FIRST_NAME) NOT NULL,
genre CHAR(1) NOT NULL, # M: male / F: female / U: unspecified
	last_name VARCHAR(MAX_CHAR_LAST_NAME) NOT NULL,
	location TIPODELOCATION NOT NULL,
	password TIPODEPASSWORD NOT NULL,
	signup_date DATE NOT NULL,
	user_name VARCHAR(MAX_CHAR_USER_NAME) NOT NULL,
	PRIMARY KEY(user_name)
);

CREATE TABLE Problem(
	accepted_solution_id TIPODEID NOT NULL,
	content VARCHAR(MAX_CHAR_CONTENT),
	creation_datetime DATETIME,
	creator_user_name VARCHAR(MAX_CHAR_USER_NAME) NOT NULL,
	description VARCHAR(MAX_CHAR_DESCRIPTION) NOT NULL,
	id TIPODEID NOT NULL,
	is_anonymous BOOL NOT NULL,
	is_solved BOOL NOT NULL,
	last_edition_datetime DATETIME NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(accepted_solution_id) REFERENCES Solution(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
);

CREATE TABLE Solution(
	content VARCHAR(MAX_CHAR_CONTENT),
	creation_datetime DATETIME,
	creator_user_name VARCHAR(MAX_CHAR_USER_NAME) NOT NULL,
	description VARCHAR(MAX_CHAR_DESCRIPTION) NOT NULL,
	id TIPODEID NOT NULL,
	is_anonymous BOOL NOT NULL,
	last_edition_datetime DATETIME NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
);

CREATE TABLE problem_solutions(
	problem_id TIPODEID NOT NULL,
	solution_id TIPODEID NOT NULL,
	PRIMARY KEY(problem_id, solution_id),
	FOREIGN KEY(problem_id) REFERENCES Problem(id),
	FOREIGN KEY(solution_id) REFERENCES Solution(id)
);
