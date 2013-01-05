
USE pci_database;

ALTER TABLE Problem MODIFY id BIGINT AUTO_INCREMENT;
ALTER TABLE Problem AUTO_INCREMENT = 1000;
ALTER TABLE Solution MODIFY id BIGINT AUTO_INCREMENT;
ALTER TABLE Solution AUTO_INCREMENT = 0;
ALTER TABLE Clarification MODIFY id BIGINT AUTO_INCREMENT;
ALTER TABLE Clarification AUTO_INCREMENT = 2000;

DELETE IGNORE FROM problem_solutions;
DELETE IGNORE FROM Clarification;
DELETE IGNORE FROM Problem;
DELETE IGNORE FROM Solution;
DELETE IGNORE FROM User;

INSERT IGNORE INTO User(user_name, password)
VALUES ('problem_related_user', 'password');
INSERT IGNORE INTO User(user_name, password)
VALUES ('solution_related_user', 'password');

INSERT IGNORE INTO Problem(content, creator_user_name, description, is_anonymous, is_solved)
VALUES ('problem content', 'problem_related_user', 'problem description', FALSE, FALSE);
INSERT IGNORE INTO Solution(content, creator_user_name, description, is_anonymous)
VALUES ('solution content', 'solution_related_user', 'solution description', FALSE);
INSERT IGNORE INTO problem_solutions(problem_id, solution_id)
VALUES (1000, 1);

INSERT IGNORE INTO Clarification(answer, associated_publication_id, creator_user_name, question)
VALUES ('answer of problem_related_user', 1000, 'solution_related_user', 'question from solution_related_user');
INSERT IGNORE INTO Clarification(answer, associated_publication_id, creator_user_name, question)
VALUES ('answer of solution_related_user', 1, 'problem_related_user', 'question from problem_related_user');
