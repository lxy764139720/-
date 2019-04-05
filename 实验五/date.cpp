#include "pch.h"
#include "date.h"
#include<string>
#include<string.h>
#include <iostream>
using namespace std;

date& date::operator+(int _days) {
	this->days += _days;
	int days1 = this->days;
	this->whatdate();
	this->days = days1;
	return *this;
}

date& date::operator-(int _days) {
	this->days -= _days;
	int days1 = this->days;
	this->whatdate();
	this->days = days1;
	return *this;
}

int date::operator-(const date & date1) {
	int days1 = this->days;
	int days2 = date1.days;
	if (days1 - days2 >= 0)
		return days1 - days2;
	else
		return days2 - days1;
}

void date::manydays() {
	int year1 = this->year - 1;
	int month1 = this->month - 1;
	int day1 = this->day;
	long totaldays = 0;
	for (; year1 != 0;) {
		if (this->isrun(year1))
			totaldays += 366;
		else
			totaldays += 365;
		--year1;
	}
	switch (month1) {
	case 11:
		totaldays += 30;
	case 10:
		totaldays += 31;
	case 9:
		totaldays += 30;
	case 8:
		totaldays += 31;
	case 7:
		totaldays += 31;
	case 6:
		totaldays += 30;
	case 5:
		totaldays += 31;
	case 4:
		totaldays += 30;
	case 3:
		totaldays += 31;
	case 2:
		if (this->run)
			totaldays += 29;
		else totaldays += 28;
	case 1:
		totaldays += 31;
	}
	totaldays += day1;
	this->days = totaldays;
}

void date::whatdate() {
	int _totaldays = this->days;
	this->erase();
	int year1 = 1;
	int month1 = 1;
	int day1 = 1;
	this->run = false;
	this->dpm = 31;
	while (_totaldays > 0) {
		if (_totaldays <= this->dpm) {
			this->day = this->day + _totaldays - 1;
			_totaldays = 0;
		}
		else {
			_totaldays -= this->dpm;
			++(this->month);
			if (this->month == 13) {
				this->month = 1;
				++(this->year);
			}
			this->day = 1;
		}
		this->setdpm();
		this->isrun();
	}
}

void date::isrun() {
	if ((this->year % 400) == 0 || (((this->year % 100) != 0) && ((this->year % 4) == 0))) {
		this->run = true;
	}
	else {
		this->run = false;
	}
}

bool date::isrun(int _year1) {
	if ((_year1 % 400) == 0 || (((_year1 % 100) != 0) && ((_year1 % 4) == 0))) {
		return true;
	}
	else {
		return false;
	}
}

void date::setdpm() {
	if ((this->month < 1) || (this->month > 12)) {
		this->dpm = 0;
		return;
	}
	if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
		this->dpm = 31;
	}
	else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
		this->dpm = 30;
	}
	else {
		if (this->run)
			this->dpm = 29;
		else this->dpm = 28;
	}
}

string date::toString() {
	return to_string(this->year) + "." + to_string(this->month) + "." + to_string(this->day);
}

void date::erase() {
	this->year = 1;
	this->month = 1;
	this->day = 1;
	this->days = 0;
	this->dpm = 31;
	this->run = false;
}