#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

const int M = 20; //Высота игрового поля
const int N = 10; //Ширина игрового поля

int field[M][N] = { 0 }; //Игровое поле

//Массив фигурок-тетрамино
int figures[7][4] =
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

//Проверка на выход за границы игрового поля
bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;

	return 1;

};


int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(320, 480), "The Game!");

	//Создание и загрузка текстуры
	Texture texture, texture_background, texture_frame;
	texture.loadFromFile("C:\\dev\\SFML_Tutorial\\images\\tiles.png");
	texture_background.loadFromFile("C:\\dev\\SFML_Tutorial\\images\\background.png");
	texture_frame.loadFromFile("C:\\dev\\SFML_Tutorial\\images\\frame.png");

	//Создание спрайта
	Sprite sprite(texture), sprite_background(texture_background), sprite_frame(texture_frame);
	//Вырезаем из спрайта отдельный квадратик размером 18х18 пикселей
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	//Переменные для горизонтального перемещения и вращения
	int dx = 0; bool rotate = 0; int colorNum = 1; bool beginGame = true; int n = rand() % 7;

	//Переменные для таймера и задержки
	float timer = 0, delay = 0.3;

	//Часы (таймер)
	Clock clock;


	//Главный цикл приложения. Выполняется, пока открыто окно.
	while (window.isOpen())
	{
		//Получаем время, прошедшее с начала отсчета, и конвертируем его в секунды
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			//Пользователь нажал на «крестик» и хочет окно закрыть?
			if (event.type == Event::Closed)
				//Тогда закрываем его
				window.close();
			//Была нажата кнопка на клавиатуре?
			if (event.type == Event::KeyPressed)
				//Эта кнопка – стрелка вверх?…
				if (event.key.code == Keyboard::Up) rotate = true;
			//…или же стрелка влево?…
				else if (event.key.code == Keyboard::Left) dx = -1;
			////…ну тогда может это стрелка вправо?
				else if (event.key.code == Keyboard::Right) dx = 1;
		}

		//Нажали кнопку "вниз"? Ускоряем падение тетрамино
		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

		//// Горизонтальное перемещение ////
		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
		//Вышли за пределы поля после перемещения? Тогда возвращаем старые координаты 
		if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];


		////// Вращение //////
		if (rotate)
		{
			Point p = a[1]; //Задаем центр вращения
			for (int i = 0; i < 4; i++)
			{
				int x = a[i].y - p.y; //y-y0
				int y = a[i].x - p.x; //x-x0
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
			//Вышли за пределы поля после поворота? Тогда возвращаем старые координаты 
			if (!check()) { for (int i = 0; i < 4; i++) a[i] = b[i]; }

		}

		////// Движение тетрамино вниз («Тик» таймера) //////
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
			if (!check())
			{
				for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
				colorNum = 1 + rand() % 7;
				n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}
				
			}
			timer = 0;
		
		}

		//----ПРОВЕРКА ЛИНИИ----//
		int k = M - 1;
		for (int i = M - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < N) k--;
		}
		
		//Первое появление тетрамино на поле?
		if (beginGame)
		{
			beginGame = false;
			n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}
		dx = 0; rotate = 0; delay = 0.3;
		
		//----ОТРИСОВКА----//
		//Задаем цвет фона (Белый)
		window.clear(Color::White);
		window.draw(sprite_background);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (field[i][j] == 0) continue;
				sprite.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
				sprite.setPosition(j * 18, i * 18);
				sprite.move(28, 31); //Смещение
				window.draw(sprite);
			}

		for (int i = 0; i < 4; i++)
		{
			//Разукрашиваем тетрамино
			sprite.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
			//Устанавливаем позицию каждого кусочка тетрамино
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			sprite.move(28, 31); //Смещение
			//Отрисовка спрайта
			window.draw(sprite);
		}
		//Отрисовка фрейма
		window.draw(sprite_frame);
		//Отрисовка окна
		window.display();
	}

	return 0;
}
