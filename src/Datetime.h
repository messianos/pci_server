
#ifndef DATETIME_H_
#define DATETIME_H_

// Includes
#include <ctime>
#include <string>

class Datetime {

private:
	time_t timestamp;

public:
	Datetime(time_t timestamp);
	virtual ~Datetime();
	std::string toString(std::string format);
};

#endif /* DATETIME_H_ */
