#include "date.h"

date::date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

date::date(int day, int month, int year)
{
	this->set_date(day, month, year);
}

void date::set_date(unsigned day, unsigned month, unsigned year)
{
	(day < 32) ? this->day = day : this->day = 0;
	(month < 13) ? this->month = month : this->month = 0;
	(year > 2005 && year < 2024) ? this->year = year : this->year = 0;
}

void date::get_date(int& day, int& month, int& year)
{
	day = this->day;
	month = this->month;
	year = this->year;
}

void date::get_date(int* day, int* month, int* year)
{
	*day = this->day;
	*month = this->month;
	*year = this->year;
}

void date::print_date() const
{
    printf("����: %u.%u.%u\n", day, month, year);
}

void date::input_date()
{
    unsigned day, month, year;

    printf("\n���� ����:\n");

    printf("����: ");
    while (scanf_s("%u", &day) != 1)
    {
		while (getchar() != '\n');
		printf("������, ������� ����: ");
    }
    while (getchar() != '\n');

    printf("����� (�����): ");
    while (scanf_s("%u", &month) != 1)
    {
		while (getchar() != '\n');
        printf("������, ������� ����� (������): ");
    }
    while (getchar() != '\n');

    printf("���: ");
    while (scanf_s("%u", &year) != 1)
    {
		while (getchar() != '\n');
        printf("������, ������� ���: ");
    }
    while (getchar() != '\n');

    this->set_date(day, month, year);
}