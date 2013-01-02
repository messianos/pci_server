-- CREATE DATABASE
CREATE DATABASE cppcms;
 
-- CREATE USER
CREATE USER 'cpp_user'@'localhost' IDENTIFIED BY 'cpp_user';
 
-- GRANT PERMISSIONS
GRANT ALL ON cppcms.* TO 'cpp_user'@'localhost';
 
--  FLUSH PRIVILEGES, Tell the server TO reload the GRANT TABLES
FLUSH PRIVILEGES;

CREATE TABLE IF NOT EXISTS `fruit` (
  `fruit_id` int(10) unsigned NOT NULL auto_increment,
  `name` varchar(50) NOT NULL,
  `variety` varchar(50) NOT NULL,
  PRIMARY KEY  (`fruit_id`)
);

INSERT INTO `fruit` (`fruit_id`, `name`, `variety`) VALUES
(1, 'Apple', 'Red Delicious'),
(2, 'Pear', 'Comice'),
(3, 'Orange', 'Navel'),
(4, 'Pear', 'Bartlett'),
(5, 'Orange', 'Blood'),
(6, 'Apple', 'Cox''s Orange Pippin'),
(7, 'Apple', 'Granny Smith'),
(8, 'Pear', 'Anjou'),
(9, 'Orange', 'Valencia'),
(10, 'Banana', 'Plantain'),
(11, 'Banana', 'Burro'),
(12, 'Banana', 'Cavendish');