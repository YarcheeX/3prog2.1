#include "answer.h"

answer::answer()
{
	text = nullptr;
	author = nullptr;
}

answer::answer(date date)
{
	upload_date = date;
}

answer::answer(date date, const char* text) : answer(date)
{
	this->text = _strdup(text);
}

answer::answer(date date, const char* text, const char* author) : answer(date, text)
{
	this->author = _strdup(author);
}

answer::answer(const answer& other) : answer()
{
	*this = other;
}

answer::~answer()
{
	if (author) free(author);
	if (text) free(text);
}

const answer& answer::operator=(const answer& other)
{
	if(author) free(author);
	(other.author == nullptr) ? this->author = nullptr : this->author = _strdup(other.author);

	if(text) free(text);
	(other.text == nullptr) ? this->text = nullptr : this->text = _strdup(other.text);

	this->upload_date = other.upload_date;

	return *this;
}

void answer::set_author(const char* author)
{
	if (this->author)free(this->author);
	this->author = _strdup(author);
}

void answer::set_text(const char* text)
{
	if (this->text)free(this->text);
	this->text = _strdup(text);
}

void answer::print_answer() const
{
	printf("Автор: %s | ", author);
	upload_date.print_date();
	printf("Текст: %s\n", text);
}


void answer::input_answer()
{
	printf("Ввод коментария.\n");
	upload_date.input_date();
	
	int a = 0;
	printf("Ввести автора? (Да - 1, нет - 2):");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char aut[30];
		printf("Ввод: ");
		fgets(aut, 30, stdin);
		*strchr(aut, '\n') = '\0';
		this->set_author(aut);
	}
	else
	{
		this->set_author("Аноним");
	}

	a = 0;

	printf("Ввести текст? (Да - 1, нет - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("Ошибка. Выберите один из предложенных вариантов: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char txt[300];
		printf("Ввод: ");
		fgets(txt, 300, stdin);
		*strchr(txt, '\n') = '\0';
		this->set_author(txt);
	}
	else
	{
		this->set_author("Пустой текст");
	}
	
}

