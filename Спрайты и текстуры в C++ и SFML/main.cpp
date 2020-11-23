#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(600, 300), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно.
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет окно закрыть?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		
		// Установка цвета фона - белый
		window.clear(Color::White);

		// Создаем переменную текстуры
		Texture texture;

		// Подгружаем нашу текстуру из файла texture_bricks.jpg (текстура кирпича)
		texture.loadFromFile("C:\\dev\\SFML_Tutorial\\Debug\\texture_bricks.jpg");

		// Создаем 5 спрайтов для примера
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);

		// Позиция
		sprite1.setPosition(10.f, 30.f); // абсолютное значение
		sprite2.move(170.f, 10.f); // смещение относительно текущей позиции

		// Вращение
		sprite3.setPosition(450.f, 30.f); // сначала сдвинем спрайт в сторону
		sprite3.setRotation(45.f); // абсолютное значение в 45°
		// sprite.rotate(15.f); // можно задать смещение относительно текущего значения угла (+15°)

		// Масштаб
		sprite4.setPosition(10, 150); // сначала сдвинем спрайт вниз
		sprite4.setScale(0.3f, 0.9f); // абсолютное значение масштаба

		sprite5.setPosition(100, 170); // сначала сдвинем спрайт в сторону
		sprite5.scale(1.5f, 0.2); // смещение параметров масштабирования относительно текущих значений									
		
		// Отрисовка всех спрайтов
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);

		// Отрисовка окна
		window.display();

	}

	return 0;
}
