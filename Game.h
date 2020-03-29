#pragma once
#include "StatBox.h"

struct Game_t {

	Game_t(PlayerStatBox* player1, PlayerStatBox* player2);
	~Game_t();

	void draw();
	void draw2();

private:
	enum Status {
		Presentation,
		Resolution
	};

	Status m_status;
	PlayerStatBox* m_player1;
	PlayerStatBox* m_player2;
};
