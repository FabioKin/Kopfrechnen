#pragma once

#include<iostream>
#include<random>
#include<chrono>
#include<vector>

class date {
private:
	unsigned int _day;
	unsigned int _month;
	unsigned int _year;
	bool _leapyear_test;

	void create_date();
public:
	date();
	int learn();
};