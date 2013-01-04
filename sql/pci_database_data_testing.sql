
USE pci_database;

DELETE IGNORE FROM problem_solutions;
DELETE IGNORE FROM Clarification;
DELETE IGNORE FROM Problem;
DELETE IGNORE FROM Solution;
DELETE IGNORE FROM User;

INSERT IGNORE INTO User(user_name, password)
VALUES ('problem_related_user', 'password');
INSERT IGNORE INTO User(user_name, password)
VALUES ('solution_related_user', 'password');

INSERT IGNORE INTO Problem(content, creator_user_name, description, id, is_anonymous, is_solved)
VALUES ('problem content', 'problem_related_user', 'problem description', 123, FALSE, FALSE);
INSERT IGNORE INTO Solution(content, creator_user_name, description, id, is_anonymous)
VALUES ('solution content', 'solution_related_user', 'solution description', 345, FALSE);
INSERT IGNORE INTO problem_solutions(problem_id, solution_id)
VALUES (123, 345);

INSERT IGNORE INTO Clarification(answer, associated_publication_id, creator_user_name, id, question)
VALUES ('answer of problem_related_user', 123, 'solution_related_user', 67, 'question from solution_related_user');
INSERT IGNORE INTO Clarification(answer, associated_publication_id, creator_user_name, id, question)
VALUES ('answer of solution_related_user', 345, 'problem_related_user', 90, 'question from problem_related_user');
