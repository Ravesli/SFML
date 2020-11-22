#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	//Задаем х8-уровень антиалиасинга
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	//Объект, который собственно является главным окном приложения
	RenderWindow window(VideoMode(500, 300), "SFML Works!", Style::Default, settings);

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
		//Установка цвета фона
		window.clear(Color(250, 220, 100, 0));

		//Создаем круг радиусом 50
		CircleShape circle(50.f);
		//Закрашиваем наш круг 
		circle.setFillColor(Color(230, 0, 230));
		//Задаем толщину контура круга
		circle.setOutlineThickness(15.f);
		//Задаем цвет контура
		circle.setOutlineColor(Color(80, 220, 50));
		//Двигаем круг на толщину контура
		circle.move(15, 15);
		//Отрисовка круга
		window.draw(circle);

		//Создаем треугольник
		CircleShape triangle(65.f, 3);
		//Задаем начальную позицию справа от круга
		triangle.setPosition(125, 0);
		//Задаем цвет треугольника (Синий)
		triangle.setFillColor(Color::Blue);
		//Отрисовка треугольника
		window.draw(triangle);

		//Создаем квадрат
		CircleShape square(60.f, 4);
		//Задаем начальную позицию справа от треугольника
		square.setPosition(250, 0);
		//Задаем цвет квадрата (Красный)
		square.setFillColor(Color::Red);
		//Отрисовка квадрата
		window.draw(square);

		//Создаем октагон
		CircleShape octagon(60.f, 8);
		//Задаем начальную позицию справа от квадрата
		octagon.setPosition(380, 0);
		//Задаем цвет октагона (голубой бирюзовый)
		octagon.setFillColor(Color::Cyan);
		//Отрисовка октагона
		window.draw(octagon);

		//Заготовка фигуры многоугольника 
		ConvexShape convex;
		//Устанавливаем ему 5 вершин
		convex.setPointCount(5);
		//Задаем координаты вершин
		convex.setPoint(0, Vector2f(0.f, 0.f));
		convex.setPoint(1, Vector2f(150.f, 10.f));
		convex.setPoint(2, Vector2f(120.f, 90.f));
		convex.setPoint(3, Vector2f(30.f, 100.f));
		convex.setPoint(4, Vector2f(5.f, 50.f));
		//Задаем ему цвет - черный
		convex.setFillColor(Color::Black);
		//Теперь сдвинем его вниз и чуть-чуть вправо
		convex.move(1, 150);
		//Отрисовка многоугольника
		window.draw(convex);

		//Создаем прямоугольник размером 70 х 100
		RectangleShape rectangle(Vector2f(70.f, 100.f));
		//Двигаем его в нижний ряд справа от многоугольника
		rectangle.move(165, 150);
		//Задаем ему цвет
		rectangle.setFillColor(Color(175, 180, 240));
		//Отрисовка прямоугольника
		window.draw(rectangle);

		//Линия с заданной толщиной
		RectangleShape line_with_thickness(Vector2f(130.f, 5.f));
		//Поворачиваем ее на 45 градусов
		line_with_thickness.rotate(45.f);
		//Задаем цвет
		line_with_thickness.setFillColor(Color(15, 180, 140));
		//Двигаем ее в нижний ряд справа от прямоугольника
		line_with_thickness.move(250, 150);
		//Отрисовка линии
		window.draw(line_with_thickness);

		//Линия с нулевой толщиной. Зададим ее как массив вершин типа Vortex
		Vertex line_without_thickness[] =
		{
			//Координата первой вершины
			Vertex(Vector2f(390.f, 240.f)),
			//Координата второй вершины
			Vertex(Vector2f(470.f, 150.f))
		};
		//Задаем цвет - черный
		line_without_thickness->color = Color::Black;
		//Отрисовка линии
		window.draw(line_without_thickness, 2, Lines);


		//Отрисовка окна
		window.display();

	}

	return 0;
}
