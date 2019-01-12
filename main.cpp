/*
	* File: Main.cpp
	* Contributors: Muhammad Rafay (K17-3746)
					Mubashir Ahmed
					Zubair Aslam

	* Ping pong game
		using SFML graphics

This software is provided 'as-is', without any express or
implied warranty. In no event will the programmers be held
liable for any damages arising from the use of this software.
 
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
 
1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.
 
2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.
 
3. This notice may not be removed or altered from any
   source distribution.
 
 *
 * Created on 22nd April, 2018, 11:02
 */
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
#include "ball.cpp"
#include "slider.cpp"
#include "sides.cpp"
#include "slider2.cpp"
#include "menu2.cpp"

#define SCREEN_X 600
#define SCREEN_Y 600

float xspeed = 0.09;
float yspeed = 0.09;
int score = 0;
int score2 = 0;
double mapDouble(double valToMap, double valMin, double valMax, double mappedMin, double mappedMax)
{
	return ((valToMap - valMin) / (valMax - valMin)) * (mappedMax - mappedMin) + mappedMin;
}

void Score(Slider bar, slider2 bar2, ball b) {
	//Menu menu;
	if(bar.collision(b)) {
		++score;
		//cout << "Player1: " << score++ << endl;
	}

	if(bar2.collision(b) /*|| b.collision(b, s)*/) {
		++score2;
		//cout << "Player2: " << score2++ << endl;
	}
}

void Movement(Slider bar, slider2 bar2, ball b, sides lside, sf::RenderWindow &window, sf::Sound sound) {
	
	float xAcc = 0.04f, yAcc=0.04f;
	float angle;
	if(bar2.collision(b) || lside.collision2(b) ) {
		xspeed += xAcc;
		//sound.play();
		//cout << xspeed;
	}
	else if(bar.collision(b) || lside.collision(b) ) {
		xspeed -= xAcc;
		//sound.play();
	}
	

	if(bar.collision(b) || bar2.collision(b)) {
		//sound.play();
		xspeed = -(xspeed)	; //*exp(0.0001));
		yspeed = -(yspeed);
		Score(bar,bar2,b);
	}

	lside.draww(window);
	b.draw(window);
	bar.draw(window);
	bar2.draw(window);
}




int main() {


	int n=0;
	menu *obj;
	console test;
	//Menu menu;
	obj=&test;
	int a = obj->execution();
	if(a==1) {
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Game2");
	ball b;
	Slider s;
	slider2 bar2;
	sides lside;

	sf::SoundBuffer buffer;
	buffer.loadFromFile("Sound.wav");

	sf::Sound sound;
	sound.setBuffer(buffer);

	
	sf::Event event;
	window.setKeyRepeatEnabled(true);
	while(window.isOpen()) {
		
		while(window.pollEvent(event)) {
			if(event.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				window.close();

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				s.move(-6.0);

			else if(sf::Keyboard::isKeyPressed (sf::Keyboard::Right))
				s.move(6.0);

			else if(sf::Keyboard::isKeyPressed (sf::Keyboard::A))
				bar2.move(-6.0);

			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				bar2.move(6.0);
			
		}
		window.clear();
		//menu.draw(window);
		//window.clear();
		b.mover(xspeed, yspeed);
		Movement(s, bar2, b, lside, window, sound);
		window.display();

	}
	ofstream outfile;
	outfile.open("score.txt",ios::out|ios::app);
	//YOUR SCORE OF THE FIRST GAME :
	outfile<< "Player1: " << score << endl;
	outfile.close();
	}
	else if(a==2) {
		obj->option2();
	}
	else if(a==3) {
		obj->option3();
	}
	if(score>score2) 
		cout << "\n\nPlayer1 Won the Game. \n";
	else cout << "\n\nPlayer2 won the game.\n";
	
}