#include "blogger.h"

blogger::blogger()
{
	name = nullptr;
	description = nullptr;
	followers = 0;
	videos = nullptr;
	video_count = 0;
	photos = nullptr;
	photo_count = 0;
}
blogger::blogger(const char* name):blogger()
{
	this->name = _strdup(name);
}
blogger::blogger(const char* name, const char* descr):blogger(name)
{
	description = _strdup(descr);
}
blogger::blogger(const blogger& other):blogger()
{
	*this = other;
}
blogger::~blogger()
{
	if (name) free(name);
	if (description) free(description);
	
	if (video_count == 1) {
		delete videos[0];
		delete videos;
	}
	else {
		for (unsigned i = 0; i < video_count; i++)
			delete videos[i];
		delete[] videos;
	}
	
	if (photo_count == 1) {
		delete photos[0];
		delete photos;
	}
	else {
		for (unsigned i = 0; i < photo_count; i++)
			delete photos[i];
		delete[] photos;
	}
}

const blogger& blogger::operator=(const blogger& other)
{
	if (name)free(name);
	(other.name == nullptr) ? name = nullptr : name = _strdup(other.name);

	if (description)free(description);
	(other.description == nullptr) ? description = nullptr : description = _strdup(other.description);

	followers = other.followers;

	if (video_count == 1) {
		delete videos[0];
		delete videos;
	}
	else {
		for (unsigned i = 0; i < video_count; i++)
			delete videos[i];
		delete[] videos;
	}

	video_count = other.video_count;
	if (video_count == 0) {
		videos = nullptr;
	}
	else {
		if (video_count == 1) {
			videos = new video * ();
			videos[0] = new video(*other.videos[0]);
		}
		else{
			videos = new video*[video_count];
			for (unsigned i = 0; i < video_count; i++)
			{
				videos[i] = new video(*other.videos[i]);
			}
		}
	}

	if (photo_count == 1) {
		delete photos[0];
		delete photos;
	}
	else {
		for (unsigned i = 0; i < photo_count; i++)
			delete photos[i];
		delete[] photos;
	}

	photo_count = other.photo_count;
	if (photo_count == 0) {
		photos = nullptr;
	}
	else {
		if (photo_count == 1) {
			photos = new photo * ();
			photos[0] = new photo(*other.photos[0]);
		}
		else {
			photos = new photo*[photo_count];
			for (unsigned i = 0; i < photo_count; i++)
			{
				photos[i] = new photo(*other.photos[i]);
			}
		}
	}

	return *this;
}

void blogger::add_video(const video& vid)
{
	video_count += 1;
	if (video_count == 1) {
		videos = new video*();
		videos[0] = new video(vid);
	}
	else {
		video** temp = new video*[video_count];
		for (unsigned i = 0; i < video_count - 1; i++)
			temp[i] = videos[i];
		delete[] videos;
		
		videos = new video*[video_count];
		for (unsigned i = 0; i < video_count - 1; i++)
			videos[i] = temp[i];
		videos[video_count - 1] = new video(vid);

		delete[] temp;
	}
}

void blogger::add_photo(const photo& pho)
{
	photo_count += 1;
	if (photo_count == 1) {
		photos = new photo*();
		photos[0] = new photo(pho);
	}
	else {
		photo** temp = new photo*[photo_count];
		for (unsigned i = 0; i < photo_count - 1; i++)
			temp[i] = photos[i];
		delete[] photos;

		photos = new photo*[photo_count];
		for (unsigned i = 0; i < photo_count-1; i++)
			photos[i] = temp[i];
		photos[photo_count - 1] = new photo(pho);

		delete[] temp;
	}
}

void blogger::set_name(const char* name)
{
	if (this->name) free(this->name);
	this->name = _strdup(name);
}

void blogger::set_description(const char* descr)
{
	if (description)free(description);
	description = _strdup(descr);
}

void blogger::follow(unsigned followers)
{
	this->followers += followers;

}

void blogger::print_videos()
{
	printf("\nВидео: ");
	if (video_count == 0)
	{
		printf("Отсутствуют.\n");
		return;
	}
	for (unsigned i = 0; i < video_count; i++)
	{
		printf("\n%d)", i+1);
		videos[i]->print_post();
	}
}

void blogger::print_photos()
{
	printf("\nФото: ");
	if (photo_count == 0)
	{
		printf("Отсутствуют.\n");
		return;
	}
	for (unsigned i = 0; i < photo_count; i++)
	{
		printf("\n%d)", i+1);
		photos[i]->print_post();
	}
}

void blogger::print_all_posts()
{
	this->print_photos();
	this->print_videos();
}

void blogger::print_blogger()
{
	printf("\nНазвание блоггера: %s\n", name);
	printf("Описание: %s\n", description);
	printf("Подписчики: %u | Фото: %u | Видео: %u\n", followers, photo_count, video_count);
}

void blogger::input_blogger()
{
	printf("Ввод блоггера:\n");

	printf("Ввести название блоггера? (Да - 1, нет - 2): ");
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

	printf("Ввести описание? (Да - 1, нет - 2): ");
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


