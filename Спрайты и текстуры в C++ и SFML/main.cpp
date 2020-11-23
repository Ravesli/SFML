#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(600, 300), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����.
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ���� �������?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		
		// ��������� ����� ���� - �����
		window.clear(Color::White);

		// ������� ���������� ��������
		Texture texture;

		// ���������� ���� �������� �� ����� texture_bricks.jpg (�������� �������)
		texture.loadFromFile("C:\\dev\\SFML_Tutorial\\Debug\\texture_bricks.jpg");

		// ������� 5 �������� ��� �������
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);

		// �������
		sprite1.setPosition(10.f, 30.f); // ���������� ��������
		sprite2.move(170.f, 10.f); // �������� ������������ ������� �������

		// ��������
		sprite3.setPosition(450.f, 30.f); // ������� ������� ������ � �������
		sprite3.setRotation(45.f); // ���������� �������� � 45�
		// sprite.rotate(15.f); // ����� ������ �������� ������������ �������� �������� ���� (+15�)

		// �������
		sprite4.setPosition(10, 150); // ������� ������� ������ ����
		sprite4.setScale(0.3f, 0.9f); // ���������� �������� ��������

		sprite5.setPosition(100, 170); // ������� ������� ������ � �������
		sprite5.scale(1.5f, 0.2); // �������� ���������� ��������������� ������������ ������� ��������									
		
		// ��������� ���� ��������
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);

		// ��������� ����
		window.display();

	}

	return 0;
}
