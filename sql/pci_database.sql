
-- DATABASE CREATION ----------------------------------------------------------

CREATE DATABASE IF NOT EXISTS pci_database
CHARACTER SET utf8;

USE pci_database;



-- TABLES ---------------------------------------------------------------------

/*
 * Storage requirements
 * 
 * VARCHAR(M) L+1 bytes if column values require 0 – 255 bytes
 *            L+2 bytes if values may require more than 255 bytes
 * 
 * TINYTEXT   L+1 bytes, where L < 2^8  = 256 bytes
 * TEXT       L+2 bytes, where L < 2^16 = 65.536 bytes = 64 KB
 * MEDIUMTEXT L+3 bytes, where L < 2^24 = 16.777.216 bytes = 16 MB
 * LONGTEXT   L+4 bytes, where L < 2^32 = 4.294.967.296 bytes = 4 GB
 * 
 * 
 * Variable-length string types are stored using a length prefix plus data.
 * The length prefix requires from one to three bytes depending on the data
 * type, and the value of the prefix is L (the byte length of the string).
 * 
 * To calculate the number of bytes used to store a particular CHAR, VARCHAR,
 * or TEXT column value, you must take into account the character set used
 * for that column and whether the value contains multi-byte characters. In
 * particular, when using the utf8 Unicode character set, you must keep in
 * mind that not all characters use the same number of bytes and can require
 * up to four bytes per character.
 * 
 * Each TEXT value is represented internally by a separately allocated
 * object. This is in contrast to the VARCHAR data type, for which storage
 * is allocated once per column when the table is opened.
 */

CREATE TABLE IF NOT EXISTS User (
	birth_date DATE,
	email VARCHAR(255),
	first_name VARCHAR(31),
	genre ENUM('M', 'F', 'U'), -- M: male / F: female / U: unspecified
	last_name VARCHAR(31),
	location VARCHAR(15),
	password VARCHAR(127), -- Encrypted password
	signup_date DATE,
	user_name VARCHAR(31),
	PRIMARY KEY(user_name)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Solution (
	content MEDIUMTEXT,
	creation_datetime DATETIME,
	creator_user_name VARCHAR(31),
	description TEXT,
	id BIGINT,
	is_anonymous BOOLEAN,
	last_edition_datetime DATETIME,
	PRIMARY KEY(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Problem (
	accepted_solution_id BIGINT,
	content MEDIUMTEXT,
	creation_datetime DATETIME,
	creator_user_name VARCHAR(31),
	description TEXT,
	id BIGINT,
	is_anonymous BOOLEAN,
	is_solved BOOLEAN,
	last_edition_datetime DATETIME,
	PRIMARY KEY(id),
	FOREIGN KEY(accepted_solution_id) REFERENCES Solution(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Clarification (
	answer TEXT,
	associated_publication_id BIGINT,
	creator_user_name VARCHAR(31),
	id BIGINT,
	question TEXT,
	PRIMARY KEY(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS problem_solutions (
	problem_id BIGINT,
	solution_id BIGINT,
	PRIMARY KEY(problem_id, solution_id),
	FOREIGN KEY(problem_id) REFERENCES Problem(id),
	FOREIGN KEY(solution_id) REFERENCES Solution(id)
) ENGINE = InnoDB;



-- VIEWS ----------------------------------------------------------------------

CREATE VIEW User_no_password_view AS
SELECT 	birth_date,
		email,
		first_name,
		genre,
		last_name,
		location,
		signup_date,
		user_name
FROM User;



-- STORED PROCEDURES ----------------------------------------------------------

DELIMITER ! -- Changes the current sentence delimiter

/*
 * Checks whether the user and password entered are valid.
 * Note: at this point, the received password should already be encrypted.
 */
CREATE PROCEDURE sign_in_check(IN in_user_name VARCHAR(31), IN in_password VARCHAR(127), OUT out_success BOOLEAN)
BEGIN
	DECLARE found_password VARCHAR(127) DEFAULT NULL;
	
	SELECT password
	FROM User
	WHERE user_name LIKE BINARY in_user_name
	INTO found_password;
	
	SET out_success = found_password IS NOT NULL AND in_password LIKE BINARY found_password;
END; !

/*
 * Signs up a new user.
 * Note: this procedure doesn't validate the received parameters.
 */
CREATE PROCEDURE sign_up
(
	/*IN in_birth_date DATE,
	IN in_email VARCHAR(255),
	IN in_first_name VARCHAR(31),
	IN in_genre ENUM('M', 'F', 'U'),
	IN in_last_name VARCHAR(31),
	IN in_location VARCHAR(15),
	IN in_password VARCHAR(127),
	IN in_signup_date DATE,*/
	IN in_user_name VARCHAR(31)
)
BEGIN
	INSERT INTO User(
		/*birth_date,
		email,
		first_name,
		genre,
		last_name,
		location,
		password,
		signup_date,*/
		user_name
	)
	VALUES (
		/*in_birth_date,
		in_email,
		in_first_name,
		in_genre,
		in_last_name,
		in_location,
		in_password,
		in_signup_date,*/
		in_user_name
	);
END; !

DELIMITER ; -- Changes the current sentence delimiter



-- USERS ----------------------------------------------------------------------

CREATE USER 'pci_user'@'localhost'
IDENTIFIED BY PASSWORD '*6D4CC5751FA512A297F78B8A892AAF9D051B0231';

REVOKE ALL PRIVILEGES, GRANT OPTION
FROM 'pci_user'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE
ON TABLE pci_database.Solution
TO 'pci_user'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE
ON TABLE pci_database.Problem
TO 'pci_user'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE
ON TABLE pci_database.Clarification
TO 'pci_user'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE
ON TABLE pci_database.problem_solutions
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.User_no_password_view
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.sign_in_check
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.sign_up
TO 'pci_user'@'localhost';
