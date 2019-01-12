#ifndef SLIDER_H
#define SLIDER_H

class Slider {
	private:
		sf::RectangleShape line;
		int sliderHeight;

	public:
		Slider();	
		void draw(sf::RenderWindow &window);
		virtual void move(int);		//Polymorphism
		inline sf::RectangleShape* getLine() { return &line; }
		int posx() const;
		int posy() const;
		bool collision(ball &b);
		//void func(ball &b);
		~Slider() {}
};

#endif