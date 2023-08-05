#pragma once
#include "answer.h"


class comment {

private:
	unsigned int answers_count;   //���������� ������� �� �����������
public:
	char* author = nullptr;       //����� �����������
	char* text = nullptr;         //��� ������ �����������
	date upload_date;             //���� �������� �����������
	answer** answers = nullptr;   //������ �� ����������

	comment();
	comment(date date);
	comment(date date, const char* text);
	comment(date date, const char* text, const char* author);
	comment(const comment& other); //����������� �����������
	~comment();

	const comment& operator = (const comment& other); //���������� ��������� =
	void add_answer(const answer& ans); //����� ���������� ������ � �����������
	void set_author(const char* author); //������ ������ �����������
	void set_text(const char* text); //������ ������ �����������
	void print_comment() const; //����������� �����������
	void watch_comment() const; //���������� ����������� (� ��������)
	void input_comment(); //������ �����������

};