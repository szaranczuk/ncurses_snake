#include <iostream>
#include <ncurses.h>
#include <map>
#include <exception>
#include <list>
#include <sstream>
#include <vector>
#include "game.hpp"

std::map<char, directions> keymap = {{'w', UP}, {'s', DOWN}, {'a', LEFT}, {'d', RIGHT}};

directions getInput()
{
	while (true)
	{
		char input = getch();
		try
		{
			return keymap.at(input);
		}
		catch(std::out_of_range)
		{
			printw("Wrong key!\n");
		}
	}
}


int main()
{
	noecho();
	initscr();
	Game game(10, 10);
	clear();
	printw(game.getBoard().c_str());
	while (game.isGameActive())
	{
		directions direction = getInput();
		game.takePlayerTurn(direction);
		clear();
		printw(game.getBoard().c_str());
	}
	endwin();
}
