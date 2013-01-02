/*
 * Dateclass.cpp
 *
 *  Created on: Jan 2, 2013
 *      Author: GNZ
 */

#include "Dateclass.h"

Date_class::Date_class(int day,int month, int year) {
	this->year = year;
	this->month = month;
	this->day = day;
}

	int Date_class::getDay(){
		return day;
	}
	int Date_class::getMonth(){
		return month;
	}
	int Date_class::getYear(){
		return year;
	}
	int Date_class::getAge(int day,int month,int year){
		if (this->day-day > 0 && this->month-month >0)
			return year-this->year;
		else return year-this->year-1;
	}
	bool Date_class::isBirthday(int day,int month){
		if (day == this->day && month == this->month)
			return true;
		return false;
	}

	void Date_class::setDate(int day,int month,int year){
		this->year = year;
		this->month = month;
		this->day = day;
	}

Date_class::~Date_class() {

}

