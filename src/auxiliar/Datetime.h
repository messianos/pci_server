
#ifndef DATETIME_H_
#define DATETIME_H_

// Includes
#include <ctime>
#include <string>

class Datetime {

private:

public:
	time_t timestamp; //TODO: Made public for simplicity

	Datetime(time_t timestamp);
	virtual ~Datetime();
	bool operator<(const Datetime &other);
	std::string toString(std::string format);
};

#endif /* DATETIME_H_ */
