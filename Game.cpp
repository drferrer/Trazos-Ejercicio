#include "Game.h"
#include "rlutil.h"


Game_t::Game_t(PlayerStatBox* player1, PlayerStatBox* player2)
	: m_player1{ player1 }, m_player2{ player2 }
{
	rlutil::saveDefaultColor();
}

Game_t::~Game_t()
{
	rlutil::resetColor();
}

void Game_t::draw()
{
	m_player1->draw(1, 3);
	m_player2->draw(20, 3);
}

void Game_t::draw2()
{
	m_player1->draw2(1, 3);
	m_player2->draw2(20, 3);
}