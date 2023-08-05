#include "comment.h"

comment::comment()
{
	text = nullptr;
	author = nullptr;
	answers_count = 0;
	answers = nullptr;
}

comment::comment(date date):comment()
{
	this->upload_date = date;
}


comment::comment(date date, const char* text) : comment(date)
{
	this->text = _strdup(text);
}

comment::comment(date date, const char* text, const char* author) : comment(date, text)
{
	this->author = _strdup(author);
}

comment::comment(const comment& other) : comment()
{
	*this = other;
}

comment::~comment()
{
	if (author != nullptr) free(author);
	if (text != nullptr) free(text);
	if (answers_count == 1) {
		delete answers[0];
		delete answers;
	}
	else {
		for (unsigned i = 0; i < answers_count; i++)
			delete answers[i];
		delete[] answers;
	}
}

const comment& comment::operator=(const comment& other)
{
	//������, ������������ ������ ������
	if(author)free(author);
	(other.author == nullptr) ? this->author = nullptr : this->author = _strdup(other.author);

	//������, ������������ ������ ������
	if(text)free(text);
	(other.text == nullptr) ? this->text = nullptr : this->text = _strdup(other.text);

	//������������ ����� ����
	this->upload_date = other.upload_date;

	//���� � ������� ������� ���� �����, ������ ������ � ������� answer(), �� ��������� delete
	if (answers_count == 1) {
		delete answers[0];
		delete answers;
	}
	//����� ��������� delete[]
	else {
		for (unsigned i = 0; i < answers_count; i++)
			delete answers[i];
		delete[] answers;
	}

	this->answers_count = other.answers_count;

	if (answers_count == 0) {
		this->answers = nullptr;
	}
	else {
		if (answers_count == 1)
		{
			answers = new answer*();
			answers[0] = new answer(*other.answers[0]);
		}
		else {
			answers = new answer*[answers_count];
			for (unsigned i = 0; i < answers_count; i++)
			{
				answers[i] = new answer(*other.answers[i]);
			}
		}
	}

	return *this;
}

void comment::add_answer(const answer& ans)
{
	answers_count += 1;
	if (answers == nullptr) {
		answers = new answer*();
		answers[0] = new answer(ans);
	}
	else {
		
		answer** temp = new answer*[answers_count];
		for (unsigned i = 0; i < answers_count - 1; i++)
		{
			temp[i] = answers[i];
		}
		delete[] answers;
		
		answers = new answer*[answers_count];
		for (unsigned i = 0; i < answers_count - 1; i++)
			answers[i] = temp[i];
		answers[answers_count - 1] = new answer(ans);

		delete[] temp;
	}
}

void comment::set_author(const char* author)
{
	if (this->author)free(this->author);
	this->author = _strdup(author);
}

void comment::set_text(const char* text)
{
	if (this->text)free(this->text);
	this->text = _strdup(text);
}

void comment::print_comment() const
{
	printf("�����: %s | ", author);
	upload_date.print_date();
	printf("�����: %s\n�������: %u\n", text, answers_count);
}

void comment::watch_comment() const {

	printf("�����: %s | ", author);
	upload_date.print_date();
	printf("�����: %s\n������:\n", text);
	for (unsigned i = 0; i < answers_count; i++) {

		answers[i]->print_answer();
	}
}


void comment::input_comment()
{
	printf("���� ���� ����������:\n");
	upload_date.input_date();
	printf("������ ������? (�� - 1, ��� - 2):");
	int a = 0;

	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char aut[30];
		printf("����: ");
		fgets(aut, 30, stdin);
		*strchr(aut, '\n') = '\0';
		this->set_author(aut);
	}
	else
	{
		this->set_author("������");
	}

	a = 0;

	printf("������ �����? (�� - 1, ��� - 2)");
	while (scanf_s("%d", &a) != 1 || ((a != 1) && (a != 2))) {
		while (getchar() != '\n');
		printf("������. �������� ���� �� ������������ ���������: ");
	}
	while (getchar() != '\n');
	if (a == 1)
	{
		char txt[300];
		printf("����: ");
		fgets(txt, 300, stdin);
		*strchr(txt, '\n') = '\0';
		this->set_author(txt);
	}
	else
	{
		this->set_text("������ �����");
	}

}


