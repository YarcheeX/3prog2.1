#pragma once
#include "date.h"
#include "answer.h"
#include <string.h>
//#include <stdlib.h>


class comment {

private:
	unsigned int answers_count;   //количество ответов на комментарий
public:
	char* author = nullptr;       //текст комментария
	char* text = nullptr;         //имя автора комментария
	date upload_date;             //дата загрузки комментария
	answer** answers = nullptr;   //ответы на коментарий

	comment();
	comment(date date);
	comment(date date, const char* text);
	comment(date date, const char* text, const char* author);
	comment(const comment& other); //конструктор копирования
	~comment();

	const comment& operator = (const comment& other); //перегрузка оператора =
	void add_answer(const answer& ans); //метод добавления ответа к комментарию
	void set_author(const char* author); //сеттер автора комментария
	void set_text(const char* text); //сеттер текста комментария
	void print_comment() const; //распечатать комментарий
	void watch_comment() const; //посмотреть комментарий (с ответами)
	void input_comment(); //ввести комментарий

};