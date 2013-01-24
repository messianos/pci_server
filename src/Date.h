
#ifndef DATE_H_
#define DATE_H_

// Includes
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

class Date {

private:
	static const char FORMAT_INDICATOR;
	static const char DAY_SHORT_INDICATOR;
	static const char DAY_LONG_INDICATOR;
	static const char MONTH_SHORT_INDICATOR;
	static const char MONTH_LONG_INDICATOR;
	static const char YEAR_SHORT_INDICATOR;
	static const char YEAR_LONG_INDICATOR;
	int parseInt(std::string formatted_date, size_t initial_position, size_t *final_position);

public:
	// TODO: moved for simplicity, why should be private?
	int day;
	int month;
	int year;
	/////
	Date();
	Date(std::string format, std::string formatted_date);
	virtual ~Date();
	std::string toString(std::string format);
};

#endif /* DATE_H_ */
