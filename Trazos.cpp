#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Game.h"
#include "StatBox.h"
#include "rlutil.h"

using namespace rlutil;

int main(int argc, char** argv)
{
	printf("New Game: N - Quit: Q");

	PlayerStatBox* alvaro = new PlayerStatBox(1, "Alvaro", 0, 0, 8, 8);
	PlayerStatBox* ferrer = new PlayerStatBox(2, "Ferrer", 0, 0, 8, 8);

	saveDefaultColor();
	while (char c = getkey())
	{
		if (c == 'n')
		{
			cls();
			printf("Fight: F - Quit: Q");

			Game_t game(alvaro, ferrer);
			game.draw();
		}
		else if (c == 'q')
		{
			break;
		}
		else if (c == 'f')
		{
			cls();
			printf("New Game: N - Quit: Q");

			Game_t game(alvaro, ferrer);
			game.draw2();
		}
		else
		{
			printf("Incorrect key");
		}
	}
	delete alvaro, ferrer;
}