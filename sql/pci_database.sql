
-- DATABASE CREATION AND CONFIGURATION ----------------------------------------

CREATE DATABASE IF NOT EXISTS pci_database
CHARACTER SET utf8;

USE pci_database;



-- USERS ----------------------------------------------------------------------

-- If the user doesn't exist, it is automatically created
-- Note: NO_AUTO_CREATE_USER mode must be disabled
GRANT SELECT, INSERT, UPDATE, DELETE
ON pci_database.*
TO 'pci_user'@'localhost'
IDENTIFIED BY PASSWORD '*6D4CC5751FA512A297F78B8A892AAF9D051B0231';



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
 * 
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
