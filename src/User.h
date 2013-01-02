/*
 * User.h
 *
 *  Created on: Jan 2, 2013
 *      Author: GNZ
 */


#ifndef USER_H_
#define USER_H_

#include <string>
#include <ctime>
#include "Dateclass.h"
using namespace std;

class User {
private:
	string user_name;
	string first_name;
	string last_name;
	string password;
	char genre;
	string email;
	Date_class birth_date;
	time_t signup_date;

public:
	User();
	virtual ~User();

};

#endif /* USER_H_ */
