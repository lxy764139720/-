#pragma once
#include"pch.h"
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

class date {
	int year;
	int month;
	int day;
	int days;
	bool run;//是否为闰年
	int dpm;//dayspermonth当月天数
public:
	date() {};
	date(int _year, int _month, int _day) :year(_year), month(_month), day(_day) {
		this->isrun();
		this->setdpm();
		if (this->dpm < _day || _day < 1 || (this->month < 1) || (this->month > 12)) {
			cout << "数据错误！请重新创建日期。" << endl;
			return;
		}
		else {
			this->day = _day;
		}
		this->manydays();
		cout << "创建成功！" << endl;
	};
	date(int _totaldays) :days(_totaldays), year(1), month(1), day(1) {
		this->whatdate();
	}
	inline void setYear(int _year) {
		year = _year;
	}
	inline int getYear() const {
		return year;
	}
	inline void setMonth(int _month) {
		month = _month;
	}
	inline int getMonth() const {
		return month;
	}
	inline void setDay(int _day) {
		day = _day;
	}
	inline int getDay() const {
		return day;
	}
	inline void setDays(int _days) {
		days = _days;
	}
	inline int getDays() const {
		return days;
	}
	inline int getDpm() const {
		return dpm;
	}
	date& operator+(int _days);
	date& operator-(int _days);
	int operator-(const date & date1);
	void manydays();
	void whatdate();
	void isrun();
	bool isrun(int);
	void setdpm();
	string toString();
	void erase();
};