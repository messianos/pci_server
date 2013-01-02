/*
 * Dateclass.h
 *
 *  Created on: Jan 2, 2013
 *      Author: GNZ
 */

#ifndef DATECLASS_H_
#define DATECLASS_H_

class Date_class {
private:
	int year;
	int month;
	int day;
public:
	Date_class();
	Date_class(int day, int month, int year);
	virtual ~Date_class();
	int getDay();
	int getMonth();
	int getYear();
	int getAge(int day, int month, int year);
	bool isBirthday(int day, int month);
	void setDate(int day, int month, int year);

};

#endif /* DATECLASS_H_ */
