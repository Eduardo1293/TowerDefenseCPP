#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <SFML/Graphics.hpp>

class EndScreen
{
public:
	EndScreen();
	~EndScreen();

	void Run();
	bool isRunning();

private:
	sf::RenderWindow Window;

	bool running;
	std::string name;

};
#endif