#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class date {
private:
	int day, month, year; //день мес€ц год
public:
	date();
	date(int day, int month, int year);
	~date(){}
	
	void set_date(unsigned day, unsigned month, unsigned year); //сеттер даты
	void get_date(int& day, int& month, int& year); //геттер даты
	void get_date(int* day, int* month, int* year);
	void print_date() const;
	void input_date();
};