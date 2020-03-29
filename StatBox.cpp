#include <cstdio>
#include <cstdlib>
#include "rlutil.h"
#include "Statbox.h" 

using namespace rlutil;

#define HO printf("\xCD")
#define VE printf("\xBA")
#define IZAR printf("\xC9")
#define DEAR printf("\xBB")
#define IZAB printf("\xC8")
#define DEAB printf("\xBC")
#define NEWLINE printf("\n")
#define FIZ printf("\xAE"), printf("\xC4")
#define FDE printf("\xC4"), printf("\xAF")
#define LIN printf("\xC4")

PlayerStatBox::PlayerStatBox(int color, const char* name, int x, int y, int w, int h)
	:m_x{ x }, m_y{ y }, m_w{ w }, m_h{ h }, m_color{ color }
{
}

void PlayerStatBox::draw()
{
	drawBox();
	title();
	for (int i = 0; i < 6; i++)
		fillStats((Stats)i, value, i);
}

void PlayerStatBox::draw2()
{
	drawBox();
	title();
	result();
	for (int i = 0; i < 6; i++)
		fillStats((Stats)i, value, i);
}

void PlayerStatBox::draw(int x, int y)
{
	m_x = x;
	m_y = y;
	draw();
}

void PlayerStatBox::draw2(int x, int y)
{
	m_x = x;
	m_y = y;
	draw2();
}

void PlayerStatBox::title()
{
	locate(m_x + 1, m_y + 1);
	saveDefaultColor();

	setColor(RED);
	printf("D&D Stats:");

	locate(m_x + 2, m_y + 2);
	setColor(BLUE);
	printf("Player1");

	resetColor();
}

void PlayerStatBox::result() 
{
	int c = rand() % 2;

	if (c == 1)
	{
		locate(4, 3);
		saveDefaultColor();
		setColor(GREEN);
		printf("Wins!");

		locate(24, 3);
		setColor(RED);
		printf("Loses");

		locate(15, 3);
		setColor(GREEN);
		FDE;

		resetColor();
	}
	else
	{
		locate(24, 3);
		saveDefaultColor();

		setColor(GREEN);
		printf("Wins!");

		locate(4, 3);
		setColor(RED);
		printf("Loses");

		locate(15, 3);
		setColor(GREEN);
		FIZ;

		resetColor();
	}
}

void PlayerStatBox::fillStats(Stats statIndice, int& value, int order)
{
	locate(m_x + 2, m_y + order + 4);
	saveDefaultColor();
	value = rand() % 14;

	setColor(YELLOW);
	printf("%s: ", statNames[statIndice]);
	setColor(BLUE);
	printf("%d", value);

	resetColor();
}

void PlayerStatBox::drawBox()
{
	int x = m_x, y = m_y;

	saveDefaultColor();
	setColor(m_color);
	locate(x, y);

	IZAR;
	for (int i = 0; i < m_w + 2; i++) HO;
	DEAR;
	locate(x, ++y);
	for (int i = 0; i < m_h + 2; i++)
	{
		VE;
		for (int j = 0; j < m_w + 2; j++)
			printf(" ");
		VE;
		locate(x, ++y);
	}
	IZAB;
	for (int i = 0; i < m_w + 2; i++) HO;
	DEAB;

	resetColor();
}