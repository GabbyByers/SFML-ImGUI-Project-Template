#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(700, 700), "Hello SFML", sf::Style::Close);
	sf::Event event;
	ImGui::SFML::Init(window);
	ImGui::GetIO().IniFilename = NULL;

	sf::Clock deltaClock;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("my pretty window!");
		ImGui::Text("some text!");
		ImGui::End();

		window.clear(sf::Color(0, 0, 0));
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}