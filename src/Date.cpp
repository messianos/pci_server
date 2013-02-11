
// Includes
#include "Date.h"

// Namespaces
using namespace std;

// Initializations
const char Date::FORMAT_INDICATOR = '%';
const char Date::DAY_INDICATOR = 'd';
const char Date::MONTH_INDICATOR = 'm';
const char Date::YEAR_LAST_TWO_DIGITS_INDICATOR = 'y';
const char Date::YEAR_INDICATOR = 'Y';

short int Date::parseShortInt(string formatted_date, size_t initial_position, size_t *final_position) {

	char character;
	stringstream stream;
	bool valid_character = true;
	size_t current_position = initial_position;

	while (valid_character && current_position < formatted_date.size()) {
		character = formatted_date[current_position];

		if (character >= '0' && character <= '9') {
			stream << character;
			current_position++;
		} else
			// Invalid character
			valid_character = false;
	}

	*final_position = current_position;

	short int number;
	stream >> number;
	return number;
}

Date::Date(short int day, short int month, short int year) {
	// Initializes the attributes with a default value
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(string format, string formatted_date) {

	// Initializes the attributes with a default value
	day = 0;
	month = 0;
	year = 0;

	bool format_indicator_found = false;
	size_t offset = 0;
	size_t final_position;

	for (size_t i = 0; i < format.size(); i++) {

		if (format_indicator_found) {

			// The format indicator has been found in the previous iteration

			switch (format[i]) {

				case DAY_INDICATOR : {
					day = parseShortInt(formatted_date, i - 1 + offset, &final_position);
					offset = final_position - i - 1;
					break;
				}

				case MONTH_INDICATOR : {
					month = parseShortInt(formatted_date, i - 1 + offset, &final_position);
					offset = final_position - i - 1;
					break;
				}

				case YEAR_LAST_TWO_DIGITS_INDICATOR :
				case YEAR_INDICATOR : {
					year = parseShortInt(formatted_date, i - 1 + offset, &final_position);
					offset = final_position - i - 1;
					break;
				}
			}

			format_indicator_found = format[i] == FORMAT_INDICATOR;

		} else
			if (format[i] == FORMAT_INDICATOR)
				// The format indicator has been found
				format_indicator_found = true;
	}
}

Date::~Date() {}

short int Date::getDay() {
	return day;
}

short int Date::getMonth() {
	return month;
}

short int Date::getYear() {
	return year;
}

string Date::toString(string format) {

	string formatted_date = format; // The initial content is the format
	bool format_indicator_found = false;
	size_t offset = 0;

	for (size_t i = 0; i < format.size(); i++) {

		if (format_indicator_found) {

			// The format indicator has been found in the previous iteration

			stringstream stream;
			string value_string;
			short int value = -1;

			switch (format[i]) {

				case DAY_INDICATOR : {
					stream << setfill('0') << setw(2);
					value = day;
					break;
				}

				case MONTH_INDICATOR : {
					stream << setfill('0') << setw(2);
					value = month;
					break;
				}

				case YEAR_LAST_TWO_DIGITS_INDICATOR : {
					stream << setfill('0') << setw(2);
					value = year % 100;
					break;
				}

				case YEAR_INDICATOR : {
					value = year;
					break;
				}
			}

			format_indicator_found = format[i] == FORMAT_INDICATOR;

			if (value > 0) {
				stream << value;
				value_string = stream.str();
				formatted_date.replace(i - 1 + offset, 2, value_string);
				offset += value_string.size() - 2;
			}

		} else
			if (format[i] == FORMAT_INDICATOR)
				// The format indicator has been found
				format_indicator_found = true;
	}

	return formatted_date;
}
