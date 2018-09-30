#include "Menu.h"
#include "PlayingField.h"

int main() {

	
	Menu game;

	while (game.isRunning())
	{
		game.Run();
	}
}