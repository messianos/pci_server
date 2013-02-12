
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
	static const char DAY_INDICATOR;
	static const char MONTH_INDICATOR;
	static const char YEAR_LAST_TWO_DIGITS_INDICATOR;
	static const char YEAR_INDICATOR;
	short int day;
	short int month;
	short int year;
	short int parseShortInt(std::string formatted_date, size_t initial_position, size_t *final_position);

public:
	Date(short int day, short int month, short int year);
	Date(std::string format, std::string formatted_date);
	virtual ~Date();
	short int getDay();
	short int getMonth();
	short int getYear();
	std::string toString(std::string format);
};

#endif /* DATE_H_ */
