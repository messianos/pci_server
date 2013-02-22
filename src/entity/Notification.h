
#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <string>

class Notification {
public:
	Notification();
	virtual ~Notification();
	std::string user_name;
	short int seen;
	std::string url;
	std::string message;
};

#endif /* NOTIFICATION_H_ */
