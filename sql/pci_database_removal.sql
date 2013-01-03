
-- USERS REMOVAL --------------------------------------------------------------


-- If the user doesn't exist, it is automatically created
-- Note: NO_AUTO_CREATE_USER mode must be disabled
GRANT SELECT, INSERT, UPDATE, DELETE
ON pci_database.*
TO 'pci_user'@'localhost'
IDENTIFIED BY PASSWORD '*6D4CC5751FA512A297F78B8A892AAF9D051B0231';

DROP USER pci_user@localhost;



-- DATABASE REMOVAL -----------------------------------------------------------

DROP DATABASE IF EXISTS pci_database;
