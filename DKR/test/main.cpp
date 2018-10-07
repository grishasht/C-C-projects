#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf; 

void menu(RenderWindow & window) { // ��������� ����
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture;//��������� ��������
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	aboutTexture.loadFromFile("images/about.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture);//��������� ������� ��� �������
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(400, 80);//������������ �������� ������� �������
	menu2.setPosition(400, 180);
	menu3.setPosition(400, 280);
	about.setPosition(270, 150);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		//��������� ���� ���� ������ ������
		if (IntRect(400, 80, 200, 80).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(400, 180, 200, 80).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(400, 280, 200, 80).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))//���� ������ ��� ������, �� :
		{
			if (menuNum == 1) isMenu = false;//�������� � ����
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }//��������� ���� � �����������
			if (menuNum == 3) { window.close(); isMenu = false; }//��������� ����

		}

		window.draw(menu1);//�������� ��� �� �����
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}

void vin(RenderWindow & window) {//��������� ���, ����� ��������� ���� ��� ���� ���
	Texture endTexture, menuTexture3;
	endTexture.loadFromFile("images/end.png");
	menuTexture3.loadFromFile("images/333.png");
	Sprite end(endTexture), menu3(menuTexture3);
	end.setPosition(400, 150);
	menu3.setPosition(400, 240);

	bool isvin = 1;
	int vinNum = 0;

	while (vin)
	{
		end.setColor(Color::White);
		window.clear(Color(129, 181, 221));

		if (IntRect(400, 240, 200, 80).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); vinNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (vinNum == 3) { window.close(); isvin = false; }

		}

		window.draw(end);
		window.draw(menu3);
		window.display();
	}
}

int main()
{
	RenderWindow window(VideoMode(990, 500), "The game");//��������� ���� �� ������� �������
	menu(window);

	Image desk, sky, ball1, ball2;
	ball1.loadFromFile("Images/ball1.jpg");
	ball1.createMaskFromColor(Color(253, 253, 253));
	ball1.createMaskFromColor(Color(255, 255, 255));
	ball2.loadFromFile("Images/ball2.jpg");
	desk.loadFromFile("Images/desk.jpg");
	sky.loadFromFile("Images/sky.jpg");

	Texture desktexture, skytexture, ball1texture, ball2texture;
	ball1texture.loadFromImage(ball1);
	ball2texture.loadFromImage(ball2);
	desktexture.loadFromImage(desk);
	skytexture.loadFromImage(sky);

	Sprite desksprite, skysprite, ballsprite[6];

	for (int i = 0; i < 3; i++) //��������� ������� �"����
	{
		ballsprite[i].setTexture(ball1texture);
		ballsprite[i].scale(Vector2f(0.11f, 0.11f));
		ballsprite[i].setPosition(30+135*i, 340);
	}

	for (int i = 3; i < 6; i++)
	{
		ballsprite[i].setTexture(ball2texture);
		ballsprite[i].scale(Vector2f(0.27f, 0.27f));
		ballsprite[i].setPosition(165 + 135 * i, 340);
	}
	//��������� ���
	desksprite.setTexture(desktexture);
	skysprite.setTexture(skytexture);
	desksprite.setTextureRect(IntRect(0, 420, 990, 680));
	skysprite.setTextureRect(IntRect(0, 0, 990, 260));
	desksprite.setPosition(0, 240);
	//�������� ������ � ���
	Music music;
	music.openFromFile("Sounds/phone.ogg");
	music.play();

	//��������� ����� ��������� ��� ����� �������
	float a[6] = {30, 165, 300, 570, 705, 840};
	
	Clock clock;

	while (window.isOpen())
	{
		Event event;
		//�����"������� ������� �������
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		while (window.pollEvent(event))//���� ����
		{
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {//���� ������ ��� ������, ��
					if (ballsprite[0].getGlobalBounds().contains(pos.x, pos.y))//���� ������ ����� �� �������� ������
					{
						float CoordX = 30;//����� ��������� ���������� ������� ����
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[0] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{//� ���� ������ ��� ������ �����, ��������� ����� �"��.
						//�� ������� �������� �������� 䳿 � ��������, ��� �� ��� �������� ��������� 
							//�� ��������� �� ��������� ���������� ����������. 
							//��"����� ��������� �� �����.
							//���� ����� �� �������� �� � ������ ��� ����� ���� ����� �����������
							ballsprite[0].setPosition(CoordX, 340);
							a[0] = CoordX;//���� �� �"��� ����������� �� ���� �������� �� �������� ���� ��������� ���
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);//���� ��������� ���
							}
						}
					}
					if (ballsprite[1].getGlobalBounds().contains(pos.x, pos.y))
					{//��� ��� ���������.
						float CoordX = 30;
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[1] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{
							ballsprite[1].setPosition(CoordX, 340);
							a[1] = CoordX;
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);
							}
						}
					}
					if (ballsprite[2].getGlobalBounds().contains(pos.x, pos.y))
					{
						float CoordX = 30;
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[2] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{
							ballsprite[2].setPosition(CoordX, 340);
							a[2] = CoordX;
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);
							}
						}
					}
					if (ballsprite[3].getGlobalBounds().contains(pos.x, pos.y))
					{
						float CoordX = 30;
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[3] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{
							ballsprite[3].setPosition(CoordX, 340);
							a[3] = CoordX;
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);
							}
						}
					}
					if (ballsprite[4].getGlobalBounds().contains(pos.x, pos.y))
					{
						float CoordX = 30;
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[4] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{
							ballsprite[4].setPosition(CoordX, 340);
							a[4] = CoordX;
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);
							}
						}
					}
					if (ballsprite[5].getGlobalBounds().contains(pos.x, pos.y))
					{
						float CoordX = 30;
						for (int i = 0; i < 6; i++)
							if (ballsprite[0].getPosition().x == CoordX ||
								ballsprite[1].getPosition().x == CoordX ||
								ballsprite[2].getPosition().x == CoordX ||
								ballsprite[3].getPosition().x == CoordX ||
								ballsprite[4].getPosition().x == CoordX ||
								ballsprite[5].getPosition().x == CoordX) CoordX += 135;
						float p = a[5] - CoordX;
						if (p < 0) p *= -1;
						if (p <= 270)
						{
							ballsprite[5].setPosition(CoordX, 340);
							a[5] = CoordX;
							if ((ballsprite[0].getPosition().x == 570 || ballsprite[0].getPosition().x == 705 || ballsprite[0].getPosition().x == 840)
								&& (ballsprite[1].getPosition().x == 570 || ballsprite[1].getPosition().x == 705 || ballsprite[1].getPosition().x == 840)
								&& (ballsprite[2].getPosition().x == 570 || ballsprite[2].getPosition().x == 705 || ballsprite[2].getPosition().x == 840)
								&& (ballsprite[3].getPosition().x == 30 || ballsprite[3].getPosition().x == 165 || ballsprite[3].getPosition().x == 300)
								&& (ballsprite[4].getPosition().x == 30 || ballsprite[4].getPosition().x == 165 || ballsprite[4].getPosition().x == 300)
								&& (ballsprite[5].getPosition().x == 30 || ballsprite[5].getPosition().x == 165 || ballsprite[5].getPosition().x == 300))
							{
								vin(window);
							}
						}
					}
				}
			}

			if (event.type == Event::Closed)//���� ������ �� ������� �� ���� ���������
				window.close();
		}
		//�������� ���
		window.clear();
		window.draw(desksprite);
		window.draw(skysprite);
		for (int i=0; i<6; i++)
			window.draw(ballsprite[i]);
		window.display();
	}
	return 0;
}