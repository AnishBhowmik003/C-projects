#include <SFML\Graphics.hpp>
#include <iostream>
#include "button.h"
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	
	sf::CircleShape circle(50.0f);

	button button1(
		sf::Vector2f(
			50.f,
			50.f
			),
		sf::Vector2f(
			50.f,
			50.f
			)
		);


	
	
	button1.updatePointers();

	circle.setPosition(106.0f, 106.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setOrigin(50.0f, 50.0f);
	
	//sf::Texture playerTexture;
	//playerTexture.loadFromFile("tux.png");
	//player.setTexture(&playerTexture);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			
				
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				circle.setPosition((float)(mousePos.x), (float)(mousePos.y));
			}

			if (button1.pollEvent(evnt))
				cout << "Allah";

		}
		window.clear();
		window.draw(button1);
		window.display();
	}

	return 0;
}