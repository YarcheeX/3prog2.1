#pragma once
#include "post.h"


class blogger {

private:
	char* name = nullptr;               //название канала
	char* description = nullptr;        //описание канала
	unsigned int followers;    //подписчики
	unsigned int video_count;  //кол-во видео
	unsigned int photo_count;  //видео канала

public:
	
	video** videos = nullptr;            //видео канала
	photo** photos = nullptr;            //фото канала
	blogger();
	blogger(const char* name);
	blogger(const char* name, const char* descr);
	blogger(const blogger& other); //конструктор копирования
	~blogger();
	
	const blogger& operator = (const blogger& other); //перегрузка оператора = для этого класса
	void add_video(const video& vid);  //добавить фото
	void add_photo(const photo& pho);  //добавить видео
	void set_name(const char* name);         //сеттер названия канала
	void set_description(const char* descr); //сеттер описания канала
	void follow(unsigned followers);   //подписаться
	void print_videos();               //вывести все видео
	void print_photos();               //вывести все фото
	void print_all_posts();            //вывести все посты
	void print_blogger();
	void input_blogger();

	
};
