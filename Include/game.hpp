#pragma once
#include "board.hpp"
#include "snake.hpp"
#include <random>


const char HEAD = '@';
const char BODY = 'O';
const char EMPTY = '.';
const char APPLE = 'x';

class Game
{
	public:
		Game(int _height, int _width);
		void takePlayerTurn(directions direction);
		void placeApple();
		bool isGameActive();
		bool isBadSymbol(char symbol);
		int getRandomInt(int lowest, int highest);
		std::string getBoard();
	private:
		Board board;
		Snake snake;
		bool isactive;
		std::mt19937 gen;
};