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
        preferences TEXT CHARACTER SET utf8,
        profile_content MEDIUMTEXT CHARACTER SET utf8,
        profile_picture_url MEDIUMTEXT CHARACTER SET utf8,
		rank INT,
        sign_up_datetime TIMESTAMP,
        user_name VARCHAR(31),
        PRIMARY KEY(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS user_password (
        user_name VARCHAR(31),
        password BINARY(64), -- Encrypted password
        PRIMARY KEY(user_name),
        FOREIGN KEY(user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;
  
CREATE TABLE IF NOT EXISTS Problem (
        content MEDIUMTEXT CHARACTER SET utf8,
        creation_datetime TIMESTAMP,
        creator_user_name VARCHAR(31),
        description TEXT CHARACTER SET utf8,
        id BINARY(17),
        is_anonymous BOOLEAN,
        is_solved BOOLEAN,
        last_edition_datetime TIMESTAMP,
        vote_balance INT,
        PRIMARY KEY(id),
        FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
CREATE TABLE IF NOT EXISTS Solution (
        content MEDIUMTEXT CHARACTER SET utf8,
        creation_datetime TIMESTAMP,
        creator_user_name VARCHAR(31),
        description TEXT CHARACTER SET utf8,
        id BINARY(17),
        is_anonymous BOOLEAN,
        last_edition_datetime TIMESTAMP,
        problem_id BINARY(17),
        vote_balance INT,
        PRIMARY KEY(id),
        FOREIGN KEY(creator_user_name) REFERENCES User(user_name),
        FOREIGN KEY(problem_id) REFERENCES Problem(id)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS Proposal (
        content MEDIUMTEXT CHARACTER SET utf8,
        creation_datetime TIMESTAMP,
        creator_user_name VARCHAR(31),
        id BINARY(17),
        is_anonymous BOOLEAN,
        last_edition_datetime TIMESTAMP,
        vote_balance INT,
        PRIMARY KEY(id),
        FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;
 

CREATE TABLE IF NOT EXISTS Notification (
        user_name VARCHAR(31),
        seen BOOLEAN,
        url VARCHAR(255),
        message VARCHAR(255) CHARACTER SET utf8,
        FOREIGN KEY(user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS problem_solutions (
        problem_id BINARY(17),
        solution_id BINARY(17),
        PRIMARY KEY(problem_id, solution_id),
        FOREIGN KEY(problem_id) REFERENCES Problem(id),
        FOREIGN KEY(solution_id) REFERENCES Solution(id)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS Clarification (
        answer TEXT CHARACTER SET utf8,
        publication_id BINARY(17),
        creator_user_name VARCHAR(31),
        id BINARY(17),
        question TEXT CHARACTER SET utf8,
        PRIMARY KEY(id),
        FOREIGN KEY(creator_user_name) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS problem_solved (
        problem_id BINARY(17),
        solution_id BINARY(17),
        PRIMARY KEY(problem_id),
        FOREIGN KEY(problem_id) REFERENCES Problem(id),
        FOREIGN KEY(solution_id) REFERENCES Solution(id)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS problem_votes (
        problem_id BINARY(17),
        username VARCHAR(31),
        is_positive BOOLEAN,
        PRIMARY KEY(problem_id,username),
        FOREIGN KEY(problem_id) REFERENCES Problem(id),
        FOREIGN KEY(username) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS solution_votes (
        solution_id BINARY(17),
        username VARCHAR(31),
        is_positive BOOLEAN,
        PRIMARY KEY(solution_id,username),
        FOREIGN KEY(solution_id) REFERENCES Solution(id),
        FOREIGN KEY(username) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS proposal_votes (
        proposal_id BINARY(17),
        username VARCHAR(31),
        is_positive BOOLEAN,
        PRIMARY KEY(proposal_id,username),
        FOREIGN KEY(proposal_id) REFERENCES Proposal(id),
        FOREIGN KEY(username) REFERENCES User(user_name)
) ENGINE = InnoDB;
 
 
CREATE TABLE IF NOT EXISTS solution_proposals (
        proposal_id BINARY(17),
        solution_id BINARY(17),
        PRIMARY KEY(solution_id,proposal_id),
        FOREIGN KEY(proposal_id) REFERENCES Proposal(id),
        FOREIGN KEY(solution_id) REFERENCES Solution(id)
) ENGINE = InnoDB;
 
 
 
-- VIEWS ----------------------------------------------------------------------
 
/*
 * Printable views are provided for debugging purposes.
 * This is to avoid that binary non-printable characters are display on the terminal.
 */
 
CREATE VIEW User_printable_view AS
SELECT
        birth_date,
        email,
        first_name,
        genre,
        last_name,
        location,
        sign_up_datetime,
        user_name
FROM User;
 
 
CREATE VIEW user_password_printable_view AS
SELECT
        user_name,
        HEX(password) AS password
FROM user_password;
 
 
CREATE VIEW Problem_printable_view AS
SELECT
        content,
        creation_datetime,
        creator_user_name,
        description,
        HEX(id) AS id,
        is_anonymous,
        is_solved,
        last_edition_datetime
FROM Problem;
 
 
CREATE VIEW Solution_printable_view AS
SELECT
        content,
        creation_datetime,
        creator_user_name,
        description,
        HEX(id) AS id,
        is_anonymous,
        last_edition_datetime
FROM Solution;

CREATE VIEW problem_solved_printable_view AS
SELECT
        HEX(problem_id) AS problem_id,
        HEX(solution_id) AS solution_id
FROM problem_solved;
 
CREATE VIEW problem_solutions_printable_view AS
SELECT
        HEX(problem_id) AS problem_id,
        HEX(solution_id) AS solution_id
FROM problem_solutions;
 
 
CREATE VIEW Clarification_printable_view AS
SELECT
        answer,
        HEX(publication_id) AS publication_id,
        creator_user_name,
        HEX(id) AS id,
        question
FROM Clarification;
 
 
 
-- STORED PROCEDURES ----------------------------------------------------------
 
DELIMITER !
 
 
/*
 * Checks whether the user name and password entered are valid.
 * Notes:
 *              At this point, the received password must already be encrypted.
 *              in_encrypted_password must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE sign_in_user(
        IN in_user_name VARCHAR(31),
        IN in_encrypted_password BINARY(128),
        OUT out_success BOOLEAN
)
BEGIN
        DECLARE v_encrypted_password_binary BINARY(64) DEFAULT UNHEX(in_encrypted_password);
       
        SELECT EXISTS (
                SELECT *
                FROM user_password
                WHERE
                        user_name LIKE BINARY in_user_name
                        AND
                        password = v_encrypted_password_binary
                LIMIT 1
        ) INTO out_success;
END; !
 
 
/*
 * Signs up a new user.
 * Notes:
 *              This procedure doesn't validate the received parameters.
 *              At this point, the received password must already be encrypted.
 *              in_encrypted_password must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE sign_up_user(
        IN in_birth_date DATE,
        IN in_email VARCHAR(255),
        IN in_first_name VARCHAR(31) CHARACTER SET utf8,
        IN in_genre ENUM('M', 'F', 'U'),
        IN in_last_name VARCHAR(31) CHARACTER SET utf8,
        IN in_location VARCHAR(15),
        IN in_user_name VARCHAR(31),
        IN in_encrypted_password BINARY(128)
)
BEGIN
        DECLARE v_encrypted_password_binary BINARY(64) DEFAULT UNHEX(in_encrypted_password);
        DECLARE v_sign_up_datetime TIMESTAMP DEFAULT UTC_TIMESTAMP();
       
        START TRANSACTION;
       
        INSERT INTO User(
                birth_date,
                email,
                first_name,
                genre,
                last_name,
                location,
				preferences,
				profile_content,
				profile_picture_url,
				rank,
                sign_up_datetime,
                user_name
        )
        VALUES (
                in_birth_date,
                in_email,
                in_first_name,
                in_genre,
                in_last_name,
                in_location,
				NULL,
				NULL,
				NULL,
				0,
                v_sign_up_datetime,
                in_user_name
        );
       
        INSERT INTO user_password(
                user_name,
                password
        )
        VALUES (
                in_user_name,
                v_encrypted_password_binary
        );
       
        COMMIT;
END; !
 
 
/*
 * Inserts a new problem.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE insert_problem(
        IN in_content MEDIUMTEXT CHARACTER SET utf8,
        IN in_creator_user_name VARCHAR(31),
        IN in_description TEXT CHARACTER SET utf8,
        IN in_id BINARY(34),
        IN in_is_anonymous BOOLEAN
)
BEGIN
        DECLARE v_creation_datetime TIMESTAMP DEFAULT UTC_TIMESTAMP();
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        INSERT INTO Problem(
                content,
                creation_datetime,
                creator_user_name,
                description,
                id,
                is_anonymous,
                is_solved,
                last_edition_datetime,
                vote_balance
        )
        VALUES (
                in_content,
                v_creation_datetime,
                in_creator_user_name,
                in_description,
                v_id_binary,
                in_is_anonymous,
                FALSE,
                v_creation_datetime,
                0
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
        DECLARE v_found_accepted_solution_id BINARY(17) DEFAULT NULL;
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        START TRANSACTION;
       
        -- Searches the value of the accepted_solution_id column
        SELECT solution_id
        FROM problem_solved
        WHERE problem_id = v_id_binary
        LIMIT 1
        INTO v_found_accepted_solution_id;
       
        IF v_found_accepted_solution_id IS NOT NULL THEN               
                -- Deletes the accepted Solution row
                DELETE FROM Solution
                WHERE id = v_found_accepted_solution_id
                LIMIT 1;
        END IF;
       
        -- Deletes the associated problem_solved row
        DELETE FROM     problem_solved
        WHERE problem_id = v_id_binary
        LIMIT 1;
       
       
        DELETE FROM Solution
        USING Solution, problem_solutions
        WHERE
                problem_solutions.problem_id = v_id_binary
                AND
                problem_solutions.solution_id = Solution.id;
       
        -- Deletes the associated problem_solutions rows
        DELETE FROM problem_solutions
        WHERE problem_id = v_id_binary;
       
        -- Deletes the Problem row
        DELETE FROM Problem
        WHERE id = v_id_binary
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
        DECLARE v_has_accepted_solution INT DEFAULT 0;
        DECLARE v_found_accepted_solution_id BINARY(17) DEFAULT NULL;
        DECLARE v_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
        DECLARE v_solution_id_binary BINARY(17) DEFAULT UNHEX(in_solution_id);
       
        START TRANSACTION;
       
        -- Searches the current accepted solution
        SELECT count(*)
        FROM problem_solved
        WHERE problem_id = v_problem_id_binary
        LIMIT 1
        INTO v_has_accepted_solution;
       
        IF v_has_accepted_solution > 0 THEN
        
        		-- Search the old solution id
        		SELECT solution_id
		        FROM problem_solved
		        WHERE problem_id = v_problem_id_binary
		        LIMIT 1
		        INTO v_found_accepted_solution_id;

        		
        		-- Insert the old problem solution into the problem_solution table
        		INSERT INTO problem_solutions(
        			problem_id,
        			solution_id) 
        		VALUES (
	        		v_problem_id_binary,
	        		v_found_accepted_solution_id
        		);
        
                -- Delete the old problem-solution row
                DELETE FROM problem_solved
                WHERE problem_id = v_problem_id_binary
                LIMIT 1;
        END IF;
       
        -- Insert the new problem-solution row
        INSERT INTO problem_solved (
	        problem_id, 
	        solution_id)
        VALUES (
	        v_problem_id_binary, 
	        v_solution_id_binary);

	    -- Delete from problem_solution the new accepted solution

	    DELETE FROM problem_solutions
	    WHERE solution_id = v_solution_id_binary
	    LIMIT 1;
        
        -- Sets problem as solved
        UPDATE Problem
        SET is_solved = 1
        WHERE id = v_problem_id_binary
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
        DECLARE v_has_accepted_solution INT DEFAULT 0;
        DECLARE v_found_accepted_solution_id BINARY(17) DEFAULT NULL;
        DECLARE v_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
       
        START TRANSACTION;
       
        -- Searches the current accepted solution        
        SELECT count(*)
        FROM problem_solved
        WHERE problem_id = v_problem_id_binary
        LIMIT 1
        INTO v_has_accepted_solution;
       
        IF v_has_accepted_solution > 0  THEN
        		
        		-- Search for the solution_id 
        		SELECT solution_id
        		FROM problem_solved
        		WHERE
        			problem_id = v_problem_id_binary
        		LIMIT 1
        		INTO v_found_accepted_solution_id;
        		
        		-- Insert problem_id solution_id  into problem_solution table 
        		INSERT INTO problem_solutions (
        			problem_id,
        			solution_id)
        		VALUES(
        			v_problem_id_binary,
        			v_found_accepted_solution_id);
        
                -- The current accepted solution must be eliminate from problem_solve table
                DELETE FROM problem_solved
                WHERE problem_id = v_problem_id_binary;

				-- Sets problem as unsolved
		        UPDATE Problem
		        SET is_solved = 0
		        WHERE id = v_problem_id_binary
		        LIMIT 1;
		END IF;


       
        COMMIT;
END; !
 
 
/*
 * Vote for a problem
 * Note: in_problem_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE vote_problem(
        IN in_id BINARY(34),
        IN in_vote_user_name VARCHAR(31),
        IN in_is_positive_vote BOOLEAN
)
BEGIN
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
        DECLARE v_vote_balance INT;
        DECLARE checkExist INT;
        DECLARE v_is_positive BOOLEAN DEFAULT true;
       
        START TRANSACTION;
        
        -- Get the vote balance from Problem
        SELECT vote_balance
        FROM Problem
        WHERE id = v_id_binary
        LIMIT 1
        INTO v_vote_balance;
       
        -- If the user already votes
        SELECT count(*) FROM problem_votes
        WHERE problem_id = v_id_binary
        AND username = in_vote_user_name
        INTO checkExist;
        
        
       
        IF  checkExist = 0 THEN
       
                -- Create the vote in problem_votes table
                INSERT INTO problem_votes(
                        problem_id,
                        username,
                        is_positive
                )
                VALUES (
                        v_id_binary,
                        in_vote_user_name,
                        in_is_positive_vote
                );
               
                IF in_is_positive_vote IS TRUE THEN 
                	SET v_vote_balance = v_vote_balance + 1;            
                ELSE
                	SET v_vote_balance = v_vote_balance - 1;    
                END IF;
               
                -- Updates the vote_balance from the Problem row
                UPDATE Problem
                SET vote_balance = v_vote_balance
                WHERE id = v_id_binary
                LIMIT 1;
        ELSE
				SELECT is_positive FROM problem_votes
                WHERE problem_id = v_id_binary
                AND username = in_vote_user_name
                INTO v_is_positive;


                IF in_is_positive_vote IS TRUE AND v_is_positive IS FALSE THEN
                        
                        -- Delete the vote an increment the vote_balance
                        DELETE FROM problem_votes
                        WHERE problem_id = v_id_binary AND username = in_vote_user_name
                        LIMIT 1;
                        
                        SET v_vote_balance = v_vote_balance + 1;
                        
                        UPDATE Problem
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;
           		ELSE
                	IF in_is_positive_vote IS FALSE AND v_is_positive IS true THEN

	            		-- Delete the vote an increment the vote_balance

			        	DELETE FROM problem_votes
			        	WHERE problem_id = v_id_binary AND username = in_vote_user_name
			        	LIMIT 1;

			        	SET v_vote_balance = v_vote_balance - 1;

			        	UPDATE Problem
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;

	           		END IF;
		  	END IF;

        END IF;
        COMMIT;
END; !
 
 
 
/*
 * Inserts a new solution and all the necessary associated rows.
 * Note: in_problem_id and in_id must be strings representing hexadecimal numbers.
 */
CREATE PROCEDURE insert_solution(
        IN in_problem_id BINARY(34),
        IN in_content MEDIUMTEXT CHARACTER SET utf8,
        IN in_creator_user_name VARCHAR(31),
        IN in_description TEXT CHARACTER SET utf8,
        IN in_id BINARY(34),
        IN in_is_anonymous BOOLEAN
)
BEGIN
        DECLARE v_creation_datetime TIMESTAMP DEFAULT UTC_TIMESTAMP();
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
        DECLARE v_problem_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
       
        START TRANSACTION;
       
        INSERT INTO Solution(
                content,
                creation_datetime,
                creator_user_name,
                description,
                id,
                is_anonymous,
                last_edition_datetime,
                problem_id,
                vote_balance
        )
        VALUES (
                in_content,
                v_creation_datetime,
                in_creator_user_name,
                in_description,
                v_id_binary,
                in_is_anonymous,
                v_creation_datetime,
                v_problem_id_binary,
                0
        );
       
        INSERT INTO problem_solutions(
                problem_id,
                solution_id
        )
        VALUES (
                v_problem_id_binary,
                v_id_binary
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
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        START TRANSACTION;
       
        -- Updates the associated Problems_solution row (if there's any)
        UPDATE problem_solved
        SET solution_id = NULL
        WHERE solution_id = v_id_binary
        LIMIT 1;
       
        -- If no rows were affected, a problem_solutions row must be deleted
        IF ROW_COUNT() = 0 THEN
                DELETE FROM problem_solutions
                WHERE solution_id = v_id_binary
                LIMIT 1;
        END IF;
       
        -- Deletes the Solution row
        DELETE FROM Solution
        WHERE id = v_id_binary
        LIMIT 1;
       
        COMMIT;
END; !
 
 
/*
 * Vote a existing solution.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE vote_solution(
        IN in_id BINARY(34),
        IN in_vote_user_name VARCHAR(31),
        IN in_is_positive_vote BOOLEAN
)
BEGIN
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
        DECLARE v_vote_balance INT;
        DECLARE checkExist INT;
        DECLARE v_is_positive BOOLEAN DEFAULT true;
       
        START TRANSACTION;
        
        -- Get the vote balance from Problem
        SELECT vote_balance
        FROM Solution
        WHERE id = v_id_binary
        LIMIT 1
        INTO v_vote_balance;
       
        -- If the user already votes
        SELECT ROW_COUNT(*) FROM solution_votes
        WHERE solution_id = v_id_binary
        AND username = in_vote_user_name
        INTO checkExist;
        
        
       
        IF  checkExist = 0 THEN
       
                -- Create the vote in problem_votes table
                INSERT INTO solution_votes(
                        solution_id,
                        username,
                        is_positive
                )
                VALUES (
                        v_id_binary,
                        in_vote_user_name,
                        in_is_positive_vote
                );
               
                IF in_is_positive_vote IS TRUE THEN 
                	SET v_vote_balance = v_vote_balance + 1;            
                ELSE
                	SET v_vote_balance = v_vote_balance - 1;    
                END IF;
               
                -- Updates the vote_balance from the Problem row
                UPDATE Solution
                SET vote_balance = v_vote_balance
                WHERE id = v_id_binary
                LIMIT 1;
        ELSE
				SELECT is_positive FROM solution_votes
                WHERE solution_id = v_id_binary
                AND username = in_vote_user_name
                INTO v_is_positive;


                IF in_is_positive_vote IS TRUE AND v_is_positive IS FALSE THEN
                        
                        -- Delete the vote an increment the vote_balance
                        DELETE FROM solution_votes
                        WHERE solution_id = v_id_binary AND username = in_vote_user_name
                        LIMIT 1;
                        
                        SET v_vote_balance = v_vote_balance + 1;
                        
                        UPDATE Solution
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;
           		ELSE
                	IF in_is_positive_vote IS FALSE AND v_is_positive IS true THEN

	            		-- Delete the vote an increment the vote_balance

			        	DELETE FROM solution_votes
			        	WHERE solution_id = v_id_binary AND username = in_vote_user_name
			        	LIMIT 1;

			        	SET v_vote_balance = v_vote_balance - 1;

			        	UPDATE Solution
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;

	           		END IF;
		  	END IF;

        END IF;
        COMMIT;
END; !

 
 
/*
 * Inserts a new clarification.
 * Note: in_publication_id and in_id must be strings representing hexadecimal numbers.
 */
CREATE PROCEDURE insert_clarification(
        IN in_publication_id BINARY(34),
        IN in_creator_user_name VARCHAR(31),
        IN in_id BINARY(34),
        IN in_question TEXT CHARACTER SET utf8
)
BEGIN
        DECLARE v_publication_id_binary BINARY(17) DEFAULT UNHEX(in_publication_id);
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        INSERT INTO Clarification(
                answer,
                publication_id,
                creator_user_name,
                id,
                question
        )
        VALUES (
                NULL,
                v_publication_id_binary,
                in_creator_user_name,
                v_id_binary,
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
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        DELETE FROM Clarification
        WHERE id = v_id_binary
        LIMIT 1;
END; !
 
/*
 * Atomically insert a proposal and solution_proposal associated row
 * Note: in_id must be a string representing an hexadecimal number.
 */
 
CREATE PROCEDURE insert_proposal(
        IN in_solution_id BINARY(34),
        IN in_content MEDIUMTEXT CHARACTER SET utf8,
        IN in_creator_user_name VARCHAR(31),
        IN in_id BINARY(34),
        IN in_is_anonymous BOOLEAN
)
BEGIN
        DECLARE v_creation_datetime TIMESTAMP DEFAULT UTC_TIMESTAMP();
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
        DECLARE v_solution_id_binary BINARY(17) DEFAULT UNHEX(in_problem_id);
       
        START TRANSACTION;
       
        INSERT INTO Proposal(
                content,
                creation_datetime,
                creator_user_name,
                id,
                is_anonymous,
                last_edition_datetime,
                vote_balance
        )
        VALUES (
                in_content,
                v_creation_datetime,
                in_creator_user_name,
                v_id_binary,
                in_is_anonymous,
                v_creation_datetime,
                0
        );
       
        INSERT INTO solution_proposals(
                solution_id,
                proposal_id
               
        )
        VALUES (
                v_solution_id_binary,
                v_id_binary
        );
       
        COMMIT;
END; !
 
 
/*
 * Atomically deletes a proposal and all its associated rows.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE delete_proposal(
        IN in_id BINARY(34)
)
BEGIN
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
       
        DELETE FROM solution_proposals
        WHERE proposal_id = v_id_binary;
       
        DELETE FROM Proposal
        WHERE id = v_id_binary
        LIMIT 1;
END; !


/*
 * Vote a existing proposal.
 * Note: in_id must be a string representing an hexadecimal number.
 */
CREATE PROCEDURE vote_proposal(
        IN in_id BINARY(34),
        IN in_vote_user_name VARCHAR(31),
        IN in_is_positive_vote BOOLEAN
)
BEGIN
        DECLARE v_id_binary BINARY(17) DEFAULT UNHEX(in_id);
        DECLARE v_vote_balance INT;
        DECLARE checkExist INT;
        DECLARE v_is_positive BOOLEAN DEFAULT true;
       
        START TRANSACTION;
        
        -- Get the vote balance from Problem
        SELECT vote_balance
        FROM Proposal
        WHERE id = v_id_binary
        LIMIT 1
        INTO v_vote_balance;
       
        -- If the user already votes
        SELECT count(*) FROM proposal_votes
        WHERE proposal_id = v_id_binary
        AND username = in_vote_user_name
        INTO checkExist;
        
        
       
        IF  checkExist = 0 THEN
       
                -- Create the vote in problem_votes table
                INSERT INTO proposal_votes(
                        proposal_id,
                        username,
                        is_positive
                )
                VALUES (
                        v_id_binary,
                        in_vote_user_name,
                        in_is_positive_vote
                );
               
                IF in_is_positive_vote IS TRUE THEN 
                	SET v_vote_balance = v_vote_balance + 1;            
                ELSE
                	SET v_vote_balance = v_vote_balance - 1;    
                END IF;
               
                -- Updates the vote_balance from the Problem row
                UPDATE Proposal
                SET vote_balance = v_vote_balance
                WHERE id = v_id_binary
                LIMIT 1;
        ELSE
				SELECT is_positive FROM proposal_votes
                WHERE proposal_id = v_id_binary
                AND username = in_vote_user_name
                INTO v_is_positive;


                IF in_is_positive_vote IS TRUE AND v_is_positive IS FALSE THEN
                        
                        -- Delete the vote an increment the vote_balance
                        DELETE FROM proposal_votes
                        WHERE proposal_id = v_id_binary AND username = in_vote_user_name
                        LIMIT 1;
                        
                        SET v_vote_balance = v_vote_balance + 1;
                        
                        UPDATE Proposal
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;
           		ELSE
                	IF in_is_positive_vote IS FALSE AND v_is_positive IS true THEN

	            		-- Delete the vote an increment the vote_balance

			        	DELETE FROM proposal_votes
			        	WHERE proposal_id = v_id_binary AND username = in_vote_user_name
			        	LIMIT 1;

			        	SET v_vote_balance = v_vote_balance - 1;

			        	UPDATE Proposal
		                SET vote_balance = v_vote_balance
		                WHERE id = v_id_binary
		                LIMIT 1;

	           		END IF;
		  	END IF;

        END IF;
        COMMIT;
END; !


/*
 * Calculates the users' ranking
 */
CREATE PROCEDURE rank_update(IN in_user_name VARCHAR(31))
BEGIN
        DECLARE v_rank INT DEFAULT 0;
       
        DECLARE v_proposal_weight INT DEFAULT 4;
        DECLARE v_problem_weight INT DEFAULT 8;
        DECLARE v_solution_weight INT DEFAULT 12;
        DECLARE v_vote_weight INT DEFAULT 1;
        DECLARE v_accepted_solution_weight INT DEFAULT 40;
       
        DECLARE v_count INT;
       
        START TRANSACTION;
        -- Proposal
        SELECT
                count(*)
        FROM
                Proposal
        WHERE creator_user_name = in_user_name AND vote_balance > 0
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_proposal_weight;
       
        -- Problem
        SELECT
                count(*)
        FROM
                Problem
        WHERE creator_user_name = in_user_name AND vote_balance > 0
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_problem_weight;
       
                -- Solution
        SELECT
                count(*)
        FROM
                Solution
        WHERE creator_user_name = in_user_name AND vote_balance > 0
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_solution_weight;
       
                -- Problem vote
        SELECT
                count(*)
        FROM
                problem_votes
        WHERE username = in_user_name
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_vote_weight;
       
       
                -- Solution vote
        SELECT
                count(*)
        FROM
                solution_votes
        WHERE username = in_user_name
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_vote_weight;
       
                -- Proposal vote
        SELECT
                count(*)
        FROM
                proposal_votes
        WHERE username = in_user_name
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_vote_weight;
       
                -- Accepted solutions
        SELECT
                count(*)
        FROM
                problem_solved JOIN Solution
        ON Solution.id = problem_solved.solution_id
        WHERE Solution.creator_user_name = in_user_name AND Solution.vote_balance > 0
        INTO v_count;
       
        SET v_rank = v_rank + v_count*v_accepted_solution_weight;
       
        -- Rank update
       
        UPDATE User
        SET rank = v_rank
        WHERE user_name = in_user_name;
       
        COMMIT;
       
END; !

CREATE PROCEDURE update_all_users_rank()
BEGIN
	DECLARE done INT DEFAULT 0;
	DECLARE user_name VARCHAR(31);
	DECLARE cur1 CURSOR FOR SELECT user_name FROM User;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

	OPEN cur1;

	REPEAT 
		FETCH cur1 INTO user_name;
		IF NOT done THEN
			CALL rank_update(user_name);
		END IF;
	UNTIL done END REPEAT;

	CLOSE cur1;
END; !
 
 
DELIMITER ;
 
 
 
-- TRIGGERS -------------------------------------------------------------------
 
DELIMITER !
 
/*
 * Triggered before a Problem row is deleted.
 */
CREATE TRIGGER Problem_before_delete_trigger
BEFORE DELETE ON Problem
FOR EACH ROW
BEGIN
        -- Deletes the associated Clarification rows
        DELETE FROM Clarification
        WHERE publication_id = OLD.id;
END; !
 
 
/*
 * Triggered before a Solution row is deleted.
 */
CREATE TRIGGER Solution_before_delete_trigger
BEFORE DELETE ON Solution
FOR EACH ROW
BEGIN
        -- Deletes the associated Clarification rows
        DELETE FROM Clarification
        WHERE publication_id = OLD.id;
       
        -- Deletes the associated Proposal rows
        DELETE FROM Proposal
        USING Proposal, solution_proposal
        WHERE
                solution_proposal.solution_id = OLD.id
                AND
                solutions_proposal.proposal_id = Proposal.id;
               
        -- Deletes the associated solution_proposals rows
        DELETE FROM solution_proposals
        WHERE solution_id = OLD.id;
END; !
 
 
DELIMITER ;

-- EVENT -------------------------------------------------------------------

/*
* Update ranking event
*/

CREATE EVENT myevent
    ON SCHEDULE EVERY 5 SECOND
    DO
      update_all_users_rank();
 
 
 
-- USERS ----------------------------------------------------------------------
 
CREATE USER 'pci_user'@'localhost'
IDENTIFIED BY PASSWORD '*6D4CC5751FA512A297F78B8A892AAF9D051B0231';
 
REVOKE ALL PRIVILEGES, GRANT OPTION
FROM 'pci_user'@'localhost';
 
GRANT SELECT
ON TABLE pci_database.User
TO 'pci_user'@'localhost';
 
GRANT SELECT
ON TABLE pci_database.Problem
TO 'pci_user'@'localhost';
 
GRANT SELECT
ON TABLE pci_database.Solution
TO 'pci_user'@'localhost';
 
GRANT SELECT
ON TABLE pci_database.problem_solutions
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.problem_solved
TO 'pci_user'@'localhost';

GRANT SELECT
ON TABLE pci_database.Clarification
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

/* TODO: REMOVE! DEBUG!!! */
GRANT ALL PRIVILEGES
ON *.*
TO 'pci_user'@'localhost';