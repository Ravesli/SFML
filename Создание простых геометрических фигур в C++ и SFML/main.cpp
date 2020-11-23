#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	// Задаем 8-й уровень антиалиасинга
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(500, 300), "SFML Works!", Style::Default, settings);

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
		
		// Установка цвета фона
		window.clear(Color(250, 220, 100, 0));


		// Создаем круг радиусом 50
		CircleShape circle(50.f);
		circle.setFillColor(Color(230, 0, 230)); // закрашиваем наш круг 
		circle.setOutlineThickness(15.f); // задаем толщину контура круга
		circle.setOutlineColor(Color(80, 220, 50)); // задаем цвет контура
		circle.move(15, 15); // двигаем круг на толщину контура
		window.draw(circle); // отрисовка круга


		// Создаем треугольник
		CircleShape triangle(65.f, 3);
		triangle.setPosition(125, 0); // задаем начальную позицию справа от круга
		triangle.setFillColor(Color::Blue); // задаем цвет треугольника - синий
		window.draw(triangle); // отрисовка треугольника


		// Создаем квадрат
		CircleShape square(60.f, 4);
		square.setPosition(250, 0); // задаем начальную позицию справа от треугольника
		square.setFillColor(Color::Red); // задаем цвет квадрата - красный
		window.draw(square); // отрисовка квадрата

		// Создаем октагон
		CircleShape octagon(60.f, 8);
		octagon.setPosition(380, 0); // задаем начальную позицию справа от квадрата
		octagon.setFillColor(Color::Cyan); // задаем цвет октагона - голубой-бирюзовый
		window.draw(octagon); // отрисовка октагона


		// Заготовка фигуры многоугольника 
		ConvexShape convex;
		convex.setPointCount(5); // устанавливаем ему 5 вершин
		
		// Задаем координаты вершин
		convex.setPoint(0, Vector2f(0.f, 0.f));
		convex.setPoint(1, Vector2f(150.f, 10.f));
		convex.setPoint(2, Vector2f(120.f, 90.f));
		convex.setPoint(3, Vector2f(30.f, 100.f));
		convex.setPoint(4, Vector2f(5.f, 50.f));
				
		convex.setFillColor(Color::Black); // задаем ему цвет - черный
		convex.move(1, 150); // теперь сдвинем его вниз и чуть-чуть вправо
		window.draw(convex); // отрисовка многоугольника


		// Создаем прямоугольник размером 70х100
		RectangleShape rectangle(Vector2f(70.f, 100.f));
		rectangle.move(165, 150); // двигаем его в нижний ряд справа от многоугольника
		rectangle.setFillColor(Color(175, 180, 240)); // задаем ему цвет
		window.draw(rectangle); // отрисовка прямоугольника

		// Линия с заданной толщиной
		RectangleShape line_with_thickness(Vector2f(130.f, 5.f));
		line_with_thickness.rotate(45.f); // поворачиваем её на 45 градусов
		line_with_thickness.setFillColor(Color(15, 180, 140)); // задаем цвет
		line_with_thickness.move(250, 150); // двигаем её в нижний ряд справа от прямоугольника
		window.draw(line_with_thickness); // отрисовка линии

		// Линия с нулевой толщиной. Зададим её как массив вершин типа Vertex
		Vertex line_without_thickness[] =
		{
			// Координата первой вершины
			Vertex(Vector2f(390.f, 240.f)),
			// Координата второй вершины
			Vertex(Vector2f(470.f, 150.f))
		};
		
		// Задаем цвет - черный
		line_without_thickness->color = Color::Black;
		
		// Отрисовка линии
		window.draw(line_without_thickness, 2, Lines);


		// Отрисовка окна
		window.display();

	}

	return 0;
}
