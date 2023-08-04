#pragma once
#include "post.h"


class blogger {

private:
	char* name = nullptr;               //�������� ������
	char* description = nullptr;        //�������� ������
	unsigned int followers;    //����������
	unsigned int video_count;  //���-�� �����
	unsigned int photo_count;  //����� ������

public:
	
	video** videos = nullptr;            //����� ������
	photo** photos = nullptr;            //���� ������
	blogger();
	blogger(const char* name);
	blogger(const char* name, const char* descr);
	blogger(const blogger& other); //����������� �����������
	~blogger();
	
	const blogger& operator = (const blogger& other); //���������� ��������� = ��� ����� ������
	void add_video(const video& vid);  //�������� ����
	void add_photo(const photo& pho);  //�������� �����
	void set_name(const char* name);         //������ �������� ������
	void set_description(const char* descr); //������ �������� ������
	void follow(unsigned followers);   //�����������
	void print_videos();               //������� ��� �����
	void print_photos();               //������� ��� ����
	void print_all_posts();            //������� ��� �����
	void print_blogger();
	void input_blogger();

	
};
