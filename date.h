#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class date {
private:
	int day, month, year; //���� ����� ���
public:
	date();
	date(int day, int month, int year);
	~date(){}
	
	void set_date(unsigned day, unsigned month, unsigned year); //������ ����
	void get_date(int& day, int& month, int& year); //������ ����
	void get_date(int* day, int* month, int* year);
	void print_date() const;
	void input_date();
};