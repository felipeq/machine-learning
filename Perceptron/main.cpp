#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>
#include "Perceptron.h"
#include "Constants.h"

using namespace sf;


void generateCircles(std::vector<CircleShape> &circles)
{
	circles.clear();
	for (int i = 0; i < CIRCLE_AMOUNT; i++)
	{
		CircleShape cs(CIRCLE_RADIUS);
		if (rand() % 2 == 0)
			cs.setFillColor(Color::Red);
		else
			cs.setFillColor(Color::Green);
		cs.setPosition(rand() % (WINDOWS_WIDTH - CIRCLE_RADIUS), rand() % (WINDOWS_HEIGHT - CIRCLE_RADIUS));
		circles.push_back(cs);
	}
}

int main()
{
	srand(time(0));

	std::vector<CircleShape> circles;

	generateCircles(circles);
	Perceptron::initializePerceptron();
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Perceptron", Style::Default, settings);

	while (window.isOpen())
	{
		window.clear(Color::White);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space)
				generateCircles(circles);
			if (event.type == Event::Closed)
				window.close();
		}

		for (std::vector<CircleShape>::iterator it = circles.begin(); it != circles.end(); ++it)
		{
			window.draw(*it);
		}

		window.display();
	}

	return 0;
}