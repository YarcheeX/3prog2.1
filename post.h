#pragma once
#include "comment.h"
#include "Time.h"


class post {  //базовый класс для photo и video
protected:
	unsigned int views;          //просмотры
	unsigned int likes;          //лайки
	unsigned int comments_count; //кол-во комментариев

public:
	char* name;                      //название поста
	char* description;               //описание поста
	date upload_date;                //дата выгрузки поста
	comment** comments = nullptr;	 //комментарии

	post();
	post(const char* name);
	post(const char* name, const char* descr);
	post(const char* name, const char* descr, date date);
	post(const post& other);
	~post();

	virtual void print_post() const;
	virtual void input_post();

	const post& operator=(const post& other);
	void set_name(const char* name); //сеттер названия
	void set_description(const char* descr); //сеттер описания
	void add_comment(const comment& comm); //добавить комментарий
	void watch(unsigned views); //просмотреть пост
	void like(unsigned a); //лайкнуть

};



class video : public post {

public:
	Time duration;
	video();//перегружает конструктор базового класса (в определении)
	video(const char* name);
	video(const char* name, const char* descr);
	video(const char* name, const char* descr, Time duration);
	video(const char* name, const char* descr, Time duration, date upload_date);
	video(const video& other); //конструктор копирования
	
	
	const video& operator = (const post& other); //перегрузка оператора = для базового класса
	const video& operator = (const video& other); //перегрузка оператора = для этого класса
	void set_duration(int hour, int min, int sec); //сеттер длительности
	void print_post() const; //перегруженный метод базового класса
	void input_post(); //перегруженный метод базового класса

};

class photo : public post {

public:
	photo();
	//перегружают конструкторы базового класса (в определении)
	photo(const char* name);
	photo(const char* name, const char* descr);
	photo(const char* name, const char* descr, date date);
	photo(const photo& other); //конструктор копирования

	const photo& operator = (const photo& other); //перегрузка оператора = для этого класса
	void print_post() const; //перегруженный метод базового класса
	void input_post(); //перегруженный метод базового класса

};

