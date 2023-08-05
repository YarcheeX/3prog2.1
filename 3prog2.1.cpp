#include <iostream>
#include "blogger.h"
#include <locale.h>
#include <Windows.h>
#include <string>


int main()
{

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color f0");
 

    blogger* bloggers1 = new blogger[2]; //динамический массив объектов
    
    bloggers1[0].input_blogger(); //ввести блогера
    
    bloggers1[1].set_name("QWERTY"); //установить имя блогера
    bloggers1[1].set_description("Хороший контент");
    
    photo picture; //создать представителя класса photo
    
    picture.set_name("Как делать сальто");
    picture.set_description("Это может быть опасно");
    picture.upload_date.set_date(20, 10, 2014);

    bloggers1[0].add_photo(picture); //использовать метод добавления фото
    
    comment hate_comm({11,1,2010}, "сломал себе шею", "User"); //создать представителя класса comment

    bloggers1[0].photos[0]->add_comment(hate_comm); //добавить созданный комментарий

    video movie("Топ 5 лайф-хаков", "Все лайф-хаки придуманы самостоятельно", {0,5,7}, {11,1,2010}); //создать  представителя класса video
                                                                                    
    bloggers1[1].add_video(movie); //использовать метод добавления видео
    
    blogger* bloggers2[] = { new blogger(bloggers1[0]), new blogger(bloggers1[1])}; //массив с двумя динамическими объектами,
                                                                                    //инициализированными элементами динамического массива 
                                                                                    //с помощью конструкторов копирования 
    
    printf("\n\nДинамический массив:\n\n");
    bloggers1[0].print_blogger();   //вывести информацию о блогере
    bloggers1[0].print_all_posts(); //вывести все посты
    
    printf("\n");
    bloggers1[0].photos[0]->watch(1); //посмотреть фото (вместе с описанием и комментариями)
    
    bloggers1[1].print_blogger();   //вывести информацию о блогере
    bloggers1[1].print_all_posts(); //вывести все посты
    
    printf("\n\nМассив динамических объектов:\n\n");
    bloggers2[0]->print_blogger();   
    bloggers2[0]->print_all_posts();
    
    printf("\n");
    bloggers2[0]->photos[0]->watch(1);
    
    bloggers2[1]->print_blogger();
    bloggers2[1]->print_all_posts();
    
    delete[] bloggers1;  //очистить динамический массив
    delete bloggers2[0]; //очистить элементы массива
    delete bloggers2[1]; //динамических объектов

}

