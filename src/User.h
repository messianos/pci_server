/*
 * User.h
 *
 *  Created on: Jan 2, 2013
 *      Author: GNZ
 */
#include <string>
#include <ctime>

using namespace std;

#ifndef USER_H_
#define USER_H_

class User {
public:
	User();
	virtual ~User();


private:
	string user_name;
	string first_name;
	string last_name;
	string password;
	char genre;
	string email;
	Date_class birth_date;
	time_t signup_date;



};

#endif /* USER_H_ */
