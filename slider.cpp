#include "slider.h"
#include "ball.h"

Slider::Slider () : sliderHeight(150) {
	line=sf::RectangleShape(sf::Vector2f(sliderHeight, 1));
	line.setPosition(200,550);
}

void Slider::draw(sf::RenderWindow &window) {
	window.draw(line);
}

void Slider::move(int a) {	
	line.move(a, 0);
}

int Slider::posx() const {
	return line.getPosition().x;

}

int Slider::posy() const {
	return line.getPosition().y;
}


bool Slider::collision(ball &b) {
	sf::CircleShape *circle2 = b.getCircle();
	//sf::RectangleShape *line = Slider::getLine();
	//cout << circle2 << endl;
	sf::FloatRect circle = circle2->getGlobalBounds();
	sf::FloatRect slider = line.getGlobalBounds();
	return (circle.intersects(slider));
}
