#pragma once
#include "date.h"
#include <string.h>


class answer{

private:
	char* author = nullptr;
	char* text = nullptr;

public:
	date upload_date;
	answer();
	answer(date date);
	answer(date date, const char* text);
	answer(date date, const char* text, const char* author);
	answer(const answer& other);
	~answer();

	const answer& operator = (const answer& other);
	void set_author(const char* aouthor);
	void set_text(const char* text);
	void print_answer() const;
	void input_answer();

};