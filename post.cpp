#include "post.h"

post::post() {
	name = nullptr;
	description = nullptr;
	views = 0;
	likes = 0;
	comments = nullptr;
	comments_count = 0;
}

post::post(const char* name) : post() 
{
	this->name = _strdup(name);
}

post::post(const char* name, const char* descr) : post(name)
{
	description = _strdup(descr);
}

post::post(const char* name, const char* descr, date date) : post(name, descr)
{
	this->upload_date = date;
}

post::post(const post& other) : post()
{
	*this = other;
}

post::~post()
{
	if (name) free(name);
	if (description) free(description);
	if (comments_count == 1) {
		delete comments[0];
		delete comments;
	}
	else {
		for (unsigned i = 0; i < comments_count; i++)
			delete comments[i];
		delete[] comments;
	}
}

void post::set_name(const char* name)
{
	if (this->name) free(this->name);
	this->name = _strdup(name);
}

void post::set_description(const char* descr)
{
	if (description)free(description);
	description = _strdup(descr);
}

const post& post::operator=(const post& other)
{
	if(name)free(name);
	(other.name == nullptr) ? name = nullptr : name = _strdup(other.name);

	if(description)free(description);
	(other.description == nullptr) ? description = nullptr : description = _strdup(other.description);

	views = other.views;
	likes = other.likes;
	upload_date = other.upload_date;
	
	if (comments_count == 1) {
		delete comments[0];
		delete comments;
	}
	else {
		for (unsigned i = 0; i < comments_count; i++)
			delete comments[i];
		delete[] comments;
	}

	comments_count = other.comments_count;
	if (comments_count == 0) {
		this->comments = nullptr;
	}
	else {
		if (comments_count == 1) {
			comments = new comment*();
			comments[0] = new comment(*other.comments[0]);
		}
		else {
			comments = new comment*[comments_count];
			for (unsigned i = 0; i < comments_count; i++)
			{
				comments[i] = new comment(*other.comments[i]);
			}
		}
	}

	return *this;
}

void post::input_post()
{
	printf("\nВвод текстового поста.");
	printf("Ввести заголовок поста? (Да - 1, нет - 2):");
	int a = 0;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char name[30];
		printf("Ввод: ");
		fgets(name, 30, stdin);
		*strchr(name, '\n') = '\0';
		this->set_name(name);
	}

	a = 0;

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char descr[300];
		printf("Ввод: ");
		fgets(descr, 300, stdin);
		*strchr(descr, '\n') = '\0';
		this->set_description(descr);
	}
}

void post::add_comment(const comment& comm)
{
	comments_count += 1;
	if (comments == nullptr) {
		comments = new comment*();
		comments[0] = new comment(comm);
	}
	else {
		comment** temp = new comment*[comments_count];
		for (unsigned i = 0; i < comments_count - 1; i++)
			temp[i] = comments[i];
		delete[] comments;

		comments = new comment*[comments_count];
		for (unsigned i = 0; i < comments_count-1; i++)
			comments[i] = temp[i];
		comments[comments_count - 1] = new comment(comm);
		
		delete[] temp;
	}
}


void post::watch(unsigned views)
{
	this->views += views;
	this->print_post();
	printf("Описание: %s\nКомментарии:\n", description);
	if (comments_count == 0) printf("Отсутствуют\n");
	for (unsigned i = 0; i < comments_count; i++) {
		printf("%d)", i+1);
		comments[i]->print_comment();
	}
}

void post::like(unsigned a){

	this->likes += a;
}

void post::print_post() const
{
	printf("Заголовок: %s\n", name);
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

video::video(){

	duration = {0,0,0};
}

video::video(const char* name) : post(name){

	duration = { 0,0,0 };
}

video::video(const char* name, const char* descr): post(name, descr) {

	duration = { 0,0,0 };
}

video::video(const char* name, const char* descr, Time duration) : post(name,descr){

	this->duration = duration;
}

video::video(const char* name, const char* descr, Time duration, date upload_date) : post(name, descr, upload_date) {

	this->duration = duration;
}

video::video(const video& other) : video(){

	*this = other;
}


void video::print_post() const
{
	printf("Название: %s\n", name);
	printf("Длительность: %d:%d:%d\n", duration.get_hour(), duration.get_min(), duration.get_sec());
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

void video::input_post()
{
	printf("\nВвод видео.\n");
	upload_date.input_date();

	printf("Ввести название видео? (Да - 1, нет - 2):");
	int a;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char name[30];
		printf("Ввод: ");
		fgets(name, 30, stdin);
		*strchr(name, '\n') = '\0';
		this->set_name(name);
	}

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char descr[300];
		printf("Ввод: ");
		fgets(descr, 300, stdin);
		*strchr(descr, '\n') = '\0';
		this->set_description(descr);
	}
	
	printf("Ввести длительность видео? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1) {
		int min, sec, hour;
		printf("Введите часы: ");
		while (scanf_s("%d", &hour) != 0) {
			printf("Ошибка. Введите часы: ");
		}
		while (getchar() != '\n');
		printf("Введите минуты:");
		while (scanf_s("%d", &min) != 0) {
			printf("Ошибка. Введите минуты: ");
		}
		while (getchar() != '\n');
		
		printf("Введите секунды:");
		while (scanf_s("%d", &sec) != 0) {
			printf("Ошибка. Введите секунды: ");
		}
		while (getchar() != '\n');

		this->set_duration(hour, min, sec);
	}
}

const video& video::operator=(const post& other) 
{
	post::operator=(other);
	duration = { 0,0,0 };
	return *this;
}

const video& video::operator=(const video& other)
{
	post::operator=(other);
	duration = other.duration;
	return *this;
}

void video::set_duration(int hour, int min, int sec) 
{
	duration.set_time(hour, min, sec);
}

photo::photo() : post(){}
photo::photo(const char* name) : post(name) {}
photo::photo(const char* name, const char* descr) : post(name, descr) {}
photo::photo(const char* name, const char* descr, date date) : post(name, descr, date){}
photo::photo(const photo& other) : post()
{
	*this = other;
}


const photo& photo::operator=(const photo& other) 
{
	post::operator=(other);
	return *this;
}

void photo::print_post() const
{
	printf("Название: %s\n", name);
	printf("Просмотры: %u | Лайки: %u | Комментарии: %u\n", views, likes, comments_count);
	upload_date.print_date();
}

void photo::input_post()
{
	printf("\nВвод фото.\n");
	upload_date.input_date();

	printf("Ввести название фото? (Да - 1, нет - 2):");
	int a;
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char name[30];
		printf("Ввод: ");
		fgets(name, 30, stdin);
		*strchr(name, '\n') = '\0';
		this->set_name(name);
	}

	a = 0;

	printf("Ввести описание? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char descr[300];
		printf("Ввод: ");
		fgets(descr, 300, stdin);
		*strchr(descr, '\n') = '\0';
		this->set_description(descr);
	}

}
