#include "menu.h"
#include <sstream>


Menu::Menu() {

	font.loadFromFile("Lato-LightItalic.ttf");
	text.setFont(font);
	text.setString("Welcome to the Game!");
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Red);
	text.setPosition(100, 100);
	
	std::stringstream ss;
	//ss << ++R;
	score.setFont(font);
	score.setPosition(100,100);
	score.setCharacterSize(40);
	text.setColor(sf::Color::Red);
	score.setString( "How are you? ");

}


void Menu::draw(sf::RenderWindow &window) {
	//window.clear();
	window.draw(text);
	window.draw(score);
	
}
