#include <SFML/Graphics.hpp>
using namespace sf;

const int M = 20; //Высота игрового поля
const int N = 10; //Ширина игрового поля

int field[M][N] = { 0 }; //Игровое поле

//Массив фигурок-тетрамино
int figures[7][4]=
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

struct Point
{
	int x, y;
} a[4], b[4];


int main()
{
	RenderWindow window(VideoMode(320, 480), "The Game!");

	//Создание и загрузка текстуры
	Texture texture;
	texture.loadFromFile("C:\\dev\\SFML_Tutorial\\images\\tiles.png");

	//Создание спрайта
	Sprite sprite(texture);
	//Вырезаем из спрайта отдельный квадратик размером 18х18 пикселей
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	//Главный цикл приложения. Выполняется, пока открыто окно.
	while (window.isOpen())
	{
		//Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			//Пользователь нажал на «крестик» и хочет окно закрыть?
			if (event.type == Event::Closed)
				//Тогда закрываем его
				window.close();
		}

		int n = 3; //Задаем тип тетрамино
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}
	
		//Задаем цвет фона (Белый)
		window.clear(Color::White);

		for (int i = 0; i < 4; i++)
		{
			//Устанавливаем позицию каждого кусочка тетрамино
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			//Отрисовка спрайта
			window.draw(sprite);
		}
		//Отрисовка окна
		window.display();
	}

	return 0;
}
