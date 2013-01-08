
#ifndef USER_H_
#define USER_H_

// Includes
#include <string>

class User {

public:
	//struct ctime birth_date; TODO
	std::string email;
	std::string first_name;
	std::string genre;
	std::string last_name;
	std::string location;
	//struct ctime sign_up_date; TODO
	std::string user_name;
	User();
	virtual ~User();
};

#endif /* USER_H_ */
