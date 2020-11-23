
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(256, 256), "15-Puzzle! for Ravesli.com");
	
	// Задаем максимальную частоту кадров (иначе эффект анимации может быть незаметен)
	window.setFramerateLimit(60);

	// Создание и загрузка текстуры
	Texture texture;
	texture.loadFromFile("images/15.png");

	// Размеры одного блока - 64 пикселя
	int blockWidht = 64;

	// Логическое представление игрового поля
	int grid[6][6] = { 0 };

	// Массив спрайтов
	Sprite sprite[17];

	// Создаем спрайты соответствующих чисел (1, 2, 3, ..., 15) и заполняем ячейки игрового поля
	int n = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i*blockWidht, j*blockWidht, blockWidht, blockWidht));
			grid[i + 1][j + 1] = n;
		}
		
	
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
			    window.close();

			// Пользователь щелкнул мышкой?
			if (event.type == Event::MouseButtonPressed)
			{
				// Если это была левая кнопка мыши, то пробуем выполнить перестановку "пятнашек"
				if (event.key.code == Mouse::Left)
				{
					// Получаем координаты того места, где был произведен щелчок
					Vector2i position = Mouse::getPosition(window);
					
					// Переводим эти координаты в координаты наших блоков
					int x = position.x / blockWidht + 1;
					int y = position.y / blockWidht + 1;

					// Переменные для задания смещения...
					int dx = 0; //...горизонтального...
					int dy = 0; //...и вертикального.

					// Если справа пустое место
					if (grid[x + 1][y] == 16) { dx = 1; dy = 0; };
					
					// Если снизу пустое место
					if (grid[x][y + 1] == 16) { dx = 0; dy = 1; };
					
					// Если сверху пустое место
					if (grid[x][y - 1] == 16) { dx = 0; dy = -1; };
					
					// Если слева пустое место
					if (grid[x - 1][y] == 16) { dx = -1; dy = 0; };

					// Меняем местами пустую клетку с выбранным блоком
					int temp = grid[x][y];
					grid[x][y] = 16;
					grid[x + dx][y + dy] = temp;

					// Добавляем анимацию перемещения блоков

					// Ставим пустой блок на место выбранного пользователем блока
					sprite[16].move(-dx * blockWidht, -dy * blockWidht);
					// Скорость анимации
					float speed = 6;
					for (int i = 0; i < blockWidht; i += speed)
					{
						// Двигаем выбранный блок
						sprite[temp].move(speed*dx, speed*dy);
						// Отрисовываем пустой блок
						window.draw(sprite[16]);
						// Отрисовываем выбранный блок
						window.draw(sprite[temp]);
						// Отображаем всю композицию в окне
						window.display();
					}
				}
					
			}
				
		}

		
		// Установка цвета фона - белый
		window.clear(Color::White);

		// Установка каждого спрайта на свое место + Отрисовка спрайта
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				// Считываем значение ячейки игрового поля…
				int n = grid[i + 1][j + 1];
				// …и устанавливаем на нее соответствующий спрайт
				sprite[n].setPosition(i*blockWidht, j*blockWidht);
				// Отрисовка спрайта
				window.draw(sprite[n]);
			}
		

		// Отрисовка окна
		window.display();

	}
	
	return 0;
}



