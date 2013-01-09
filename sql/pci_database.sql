
/*
 * TODO:
 * 
 * Define share mode on SELECT statements
 * Add remaining procedures
 * 
 */



-- DATABASE CREATION ----------------------------------------------------------

CREATE DATABASE IF NOT EXISTS pci_database
CHARACTER SET ascii;

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
	first_name VARCHAR(31) CHARACTER SET utf8,
	genre ENUM('M', 'F', 'U'), -- M: male / F: female / U: unspecified
	last_name VARCHAR(31) CHARACTER SET utf8,
	location VARCHAR(15),
	password BINARY(64), -- Encrypted password
	sign_up_date DATE,
	user_name VARCHAR(31),
	PRIMARY KEY(user_name)
) ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS Solution (
	content MEDIUMTEXT CHARACTER SET utf8,
	creation_datetime DATETIME,
	creator_user_name VARCHAR(31),
	description TEXT CHARACTER SET utf8,
	id BINARY(17),
	is_anonymous BOOLEAN,
	last_edition_datetime DATETIME,
	PRIMARY KEY(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS Problem (
	accepted_solution_id BINARY(17),
	content MEDIUMTEXT CHARACTER SET utf8,
	creation_datetime DATETIME,
	creator_user_name VARCHAR(31),
	description TEXT CHARACTER SET utf8,
	id BINARY(17),
	is_anonymous BOOLEAN,
	is_solved BOOLEAN,
	last_edition_datetime DATETIME,
	PRIMARY KEY(id),
	FOREIGN KEY(accepted_solution_id) REFERENCES Solution(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS Clarification (
	answer TEXT CHARACTER SET utf8,
	associated_publication_id BINARY(17),
	creator_user_name VARCHAR(31),
	id BINARY(17),
	question TEXT CHARACTER SET utf8,
	PRIMARY KEY(id),
	FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS problem_solutions (
	problem_id BINARY(17),
	solution_id BINARY(17),
	PRIMARY KEY(problem_id, solution_id),
	FOREIGN KEY(problem_id) REFERENCES Problem(id),
	FOREIGN KEY(solution_id) REFERENCES Solution(id)
) ENGINE = InnoDB;



-- VIEWS ----------------------------------------------------------------------

CREATE VIEW User_no_password_view AS
SELECT
	birth_date,
	email,
	first_name,
	genre,
	last_name,
	location,
	sign_up_date,
	user_name
FROM User;



-- STORED PROCEDURES ----------------------------------------------------------

DELIMITER ! -- Changes the current sentence delimiter


/*
 * Checks whether the user name and password entered are valid.
 * Notes:
 * 		At this point, the received password must already be encrypted.
 *		in_encrypted_password must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE sign_in_user(
	IN in_user_name VARCHAR(31),
	IN in_encrypted_password BINARY(128),
	OUT out_success BOOLEAN
)
BEGIN
	DECLARE in_encrypted_password_binary BINARY(64) DEFAULT UNHEX(in_encrypted_password);
	
	SELECT *
	FROM User
	WHERE
		user_name LIKE BINARY in_user_name
		AND
		password LIKE in_encrypted_password_binary
	LIMIT 1;
	
	SET out_success = FOUND_ROWS() = 1;
END; !


/*
 * Signs up a new user.
 * Notes:
 * 		This procedure doesn't validate the received parameters.
 *		in_encrypted_password must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE sign_up_user(
	IN in_birth_date DATE,
	IN in_email VARCHAR(255),
	IN in_first_name VARCHAR(31) CHARACTER SET utf8,
	IN in_genre ENUM('M', 'F', 'U'),
	IN in_last_name VARCHAR(31) CHARACTER SET utf8,
	IN in_location VARCHAR(15),
	IN in_encrypted_password BINARY(128),
	IN in_sign_up_date DATE,
	IN in_user_name VARCHAR(31)
)
BEGIN
	DECLARE in_encrypted_password_binary BINARY(64) DEFAULT UNHEX(in_encrypted_password);
	
	INSERT INTO User(
		birth_date,
		email,
		first_name,
		genre,
		last_name,
		location,
		password,
		sign_up_date,
		user_name
	)
	VALUES (
		in_birth_date,
		in_email,
		in_first_name,
		in_genre,
		in_last_name,
		in_location,
		in_encrypted_password_binary,
		in_sign_up_date,
		in_user_name
	);
END; !


/*
 * Inserts a new problem.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE insert_problem(
	IN in_content MEDIUMTEXT CHARACTER SET utf8,
	IN in_creation_datetime DATETIME,
	IN in_creator_user_name VARCHAR(31),
	IN in_description TEXT CHARACTER SET utf8,
	IN in_id BINARY(34),
	IN in_is_anonymous BOOLEAN
)
BEGIN
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	
	INSERT INTO Problem(
		accepted_solution_id,
		content,
		creation_datetime,
		creator_user_name,
		description,
		id,
		is_anonymous,
		is_solved,
		last_edition_datetime
	)
	VALUES (
		NULL,
		in_content,
		in_creation_datetime,
		in_creator_user_name,
		in_description,
		in_id_binary,
		in_is_anonymous,
		FALSE,
		in_creation_datetime
	);
END; !


/*
 * Atomically deletes a problem and all its associated rows.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE delete_problem(
	IN in_id BINARY(34)
)
BEGIN
	DECLARE found_accepted_solution_id BINARY(17) DEFAULT NULL;
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	
	START TRANSACTION;
	
	-- Searches the value of the accepted_solution_id column
	SELECT accepted_solution_id
	FROM Problem
	WHERE id LIKE in_id_binary
	LIMIT 1
	INTO found_accepted_solution_id;
	
	IF found_accepted_solution_id IS NOT NULL THEN
		-- Deletes the accepted Solution row
		DELETE FROM Solution
		WHERE id LIKE found_accepted_solution_id
		LIMIT 1;
	END IF;
	
	-- Deletes the associated Solution rows
	DELETE FROM Solution
	USING Solution, problem_solutions
	WHERE
		problem_solutions.problem_id LIKE in_id_binary
		AND
		problem_solutions.solution_id LIKE Solution.id;
	
	-- Deletes the associated problem_solutions rows
	DELETE FROM problem_solutions
	WHERE problem_id LIKE in_id_binary;
	
	-- Deletes the Problem row
	DELETE FROM Problem
	WHERE id LIKE in_id_binary
	LIMIT 1;
	
	COMMIT;
END; !


/*
 * Sets the accepted solution of an existing problem.
 * Note: in_problem_id and in_accepted_solution_id must be strings representing hexadecimal numbers.
 */
CREATE PROCEDURE set_accepted_solution(
	IN in_problem_id BINARY(34),
	IN in_solution_id BINARY(34)
)
BEGIN
	DECLARE found_accepted_solution_id BINARY(17) DEFAULT NULL;
	DECLARE in_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
	DECLARE in_solution_id_binary BINARY(17) DEFAULT UNHEX(in_solution_id);
	
	START TRANSACTION;
	
	-- Searches the current accepted solution
	SELECT accepted_solution_id
	FROM Problem
	WHERE id LIKE in_problem_id_binary
	LIMIT 1
	INTO found_accepted_solution_id;
	
	IF found_accepted_solution_id IS NOT NULL THEN
		-- The current accepted solution must be unset
		INSERT INTO problem_solutions(
			problem_id,
			solution_id
		)
		VALUES (
			in_problem_id_binary,
			found_accepted_solution_id
		);
	END IF;
	
	-- Updates the Problem row
	UPDATE Problem
	SET accepted_solution_id = in_solution_id_binary
	WHERE id LIKE in_problem_id_binary
	LIMIT 1;
	
	COMMIT;
END; !


/*
 * Unsets the accepted solution of an existing problem.
 * Note: in_problem_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE unset_accepted_solution(
	IN in_problem_id BINARY(34)
)
BEGIN
	DECLARE found_accepted_solution_id BINARY(17) DEFAULT NULL;
	DECLARE in_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
	
	START TRANSACTION;
	
	-- Searches the current accepted solution
	SELECT accepted_solution_id
	FROM Problem
	WHERE id LIKE in_problem_id_binary
	LIMIT 1
	INTO found_accepted_solution_id;
	
	IF found_accepted_solution_id IS NOT NULL THEN
		-- The current accepted solution must be unset
		INSERT INTO problem_solutions(
			problem_id,
			solution_id
		)
		VALUES (
			in_problem_id_binary,
			found_accepted_solution_id
		);
	END IF;
	
	-- Updates the Problem row
	UPDATE Problem
	SET accepted_solution_id = NULL
	WHERE id LIKE in_problem_id_binary
	LIMIT 1;
	
	COMMIT;
END; !


/*
 * Inserts a new solution and all the necessary associated rows.
 * Note: in_problem_id and in_id must be strings representing hexadecimal numbers.
 */
CREATE PROCEDURE insert_solution(
	IN in_problem_id BINARY(34),
	IN in_content MEDIUMTEXT CHARACTER SET utf8,
	IN in_creation_datetime DATETIME,
	IN in_creator_user_name VARCHAR(31),
	IN in_description TEXT CHARACTER SET utf8,
	IN in_id BINARY(34),
	IN in_is_anonymous BOOLEAN
)
BEGIN
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	DECLARE in_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
	
	START TRANSACTION;
	
	INSERT INTO Solution(
		content,
		creation_datetime,
		creator_user_name,
		description,
		id,
		is_anonymous,
		last_edition_datetime
	)
	VALUES (
		in_content,
		in_creation_datetime,
		in_creator_user_name,
		in_description,
		in_id_binary,
		in_is_anonymous,
		in_creation_datetime
	);
	
	INSERT INTO problem_solutions(
		problem_id,
		solution_id
	)
	VALUES (
		in_problem_id_binary,
		in_id_binary
	);
	
	COMMIT;
END; !


/*
 * Atomically deletes a solution and all its associated rows.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE delete_solution(
	IN in_id BINARY(34)
)
BEGIN
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	
	START TRANSACTION;
	
	-- Updates the associated Problem row (if there's any)
	UPDATE Problem
	SET accepted_solution_id = NULL
	WHERE accepted_solution_id = in_id_binary
	LIMIT 1;
	
	-- If no rows were affected, a problem_solutions row must be deleted
	IF ROW_COUNT() = 0 THEN
		DELETE FROM problem_solutions
		WHERE solution_id LIKE in_id_binary
		LIMIT 1;
	END IF;
	
	-- Deletes the Solution row
	DELETE FROM Solution
	WHERE id LIKE in_id_binary
	LIMIT 1;
	
	COMMIT;
END; !


/*
 * Inserts a new clarification.
 * Note: in_associated_publication_id and in_id must be strings representing hexadecimal numbers.
 */
CREATE PROCEDURE insert_clarification(
	IN in_associated_publication_id BINARY(34),
	IN in_creator_user_name VARCHAR(31),
	IN in_id BINARY(34),
	IN in_question TEXT CHARACTER SET utf8
)
BEGIN
	DECLARE in_associated_publication_id_binary BINARY(17) DEFAULT UNHEX(in_associated_publication_id);
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	
	INSERT INTO Clarification(
		answer,
		associated_publication_id,
		creator_user_name,
		id,
		question
	)
	VALUES (
		NULL,
		in_associated_publication_id_binary,
		in_creator_user_name,
		in_id_binary,
		in_question
	);
END; !


/*
 * Atomically deletes a clarification and all its associated rows.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE delete_clarification(
	IN in_id BINARY(34)
)
BEGIN
	DECLARE in_id_binary BINARY(17) DEFAULT UNHEX(in_id);
	
	DELETE FROM Clarification
	WHERE id LIKE in_id_binary
	LIMIT 1;
END; !


DELIMITER ; -- Changes the current sentence delimiter



-- TRIGGERS -------------------------------------------------------------------

DELIMITER ! -- Changes the current sentence delimiter


/*
 * Triggered before a Problem row is deleted.
 */
CREATE TRIGGER trigger_delete_Problem
BEFORE DELETE ON Problem
FOR EACH ROW
BEGIN
	-- Deletes the associated Clarification rows
	DELETE FROM Clarification
	WHERE associated_publication_id LIKE OLD.id;
END; !


/*
 * Triggered before a Solution row is deleted.
 */
CREATE TRIGGER trigger_delete_Solution
BEFORE DELETE ON Solution
FOR EACH ROW
BEGIN
	-- Deletes the associated Clarification rows
	DELETE FROM Clarification
	WHERE associated_publication_id LIKE OLD.id;
END; !


DELIMITER ; -- Changes the current sentence delimiter



-- USERS ----------------------------------------------------------------------

CREATE USER 'pci_user'@'localhost'
IDENTIFIED BY PASSWORD '*6D4CC5751FA512A297F78B8A892AAF9D051B0231';

REVOKE ALL PRIVILEGES, GRANT OPTION
FROM 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.Solution
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.Problem
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.Clarification
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.problem_solutions
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.User_no_password_view
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.sign_in_user
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.sign_up_user
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.insert_problem
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.delete_problem
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.set_accepted_solution
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.unset_accepted_solution
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.insert_solution
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.delete_solution
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.insert_clarification
TO 'pci_user'@'localhost';

GRANT EXECUTE
ON PROCEDURE pci_database.delete_clarification
TO 'pci_user'@'localhost';
