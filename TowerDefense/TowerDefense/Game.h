#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game 
{
public:
	Game();
	~Game();

	void Run();
	bool isRunning();

private:
	sf::RenderWindow App;

	bool running;
	std::string name;

};
#endif