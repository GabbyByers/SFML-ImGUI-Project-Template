#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML", sf::Style::Close);
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color(0, 0, 0));
		window.display();
	}

	return 0;
}