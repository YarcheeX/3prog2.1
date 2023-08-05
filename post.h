#pragma once
#include "comment.h"
#include "Time.h"


class post {  //������� ����� ��� photo � video
protected:
	unsigned int views;          //���������
	unsigned int likes;          //�����
	unsigned int comments_count; //���-�� ������������

public:
	char* name;                      //�������� �����
	char* description;               //�������� �����
	date upload_date;                //���� �������� �����
	comment** comments = nullptr;	 //�����������

	post();
	post(const char* name);
	post(const char* name, const char* descr);
	post(const char* name, const char* descr, date date);
	post(const post& other);
	~post();

	virtual void print_post() const;
	virtual void input_post();

	const post& operator=(const post& other);
	void set_name(const char* name); //������ ��������
	void set_description(const char* descr); //������ ��������
	void add_comment(const comment& comm); //�������� �����������
	void watch(unsigned views); //����������� ����
	void like(unsigned a); //��������

};



class video : public post {

public:
	Time duration;
	video();//����������� ����������� �������� ������ (� �����������)
	video(const char* name);
	video(const char* name, const char* descr);
	video(const char* name, const char* descr, Time duration);
	video(const char* name, const char* descr, Time duration, date upload_date);
	video(const video& other); //����������� �����������
	
	
	const video& operator = (const post& other); //���������� ��������� = ��� �������� ������
	const video& operator = (const video& other); //���������� ��������� = ��� ����� ������
	void set_duration(int hour, int min, int sec); //������ ������������
	void print_post() const; //������������� ����� �������� ������
	void input_post(); //������������� ����� �������� ������

};

class photo : public post {

public:
	photo();
	//����������� ������������ �������� ������ (� �����������)
	photo(const char* name);
	photo(const char* name, const char* descr);
	photo(const char* name, const char* descr, date date);
	photo(const photo& other); //����������� �����������

	const photo& operator = (const photo& other); //���������� ��������� = ��� ����� ������
	void print_post() const; //������������� ����� �������� ������
	void input_post(); //������������� ����� �������� ������

};

