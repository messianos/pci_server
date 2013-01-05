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
#include "DateClass.h"
using namespace std;

class User {

public:
	string user_name;
	string first_name;
	string last_name;
	string location;
	string password;
	string genre;
	string email;
	DateClass birth_date;
	time_t signup_date;
	User();
	virtual ~User();

};

#endif /* USER_H_ */
