#include "game.hpp"
#include <exception>
#include <stdexcept>

Game::Game(int _height, int _width) : board(_height, _width), snake()
{
	gen.seed(std::random_device{}());
	isactive = true;
	coord initial_snake_head = {getRandomInt(0, _height - 1), getRandomInt(0, _width - 1)};
	snake.setHeadPos(initial_snake_head);
	placeApple();
	board.setFieldValue(initial_snake_head, HEAD);
}

void Game::takePlayerTurn(directions direction)
{
	board.setFieldValue(snake.getHeadPos(), BODY);
	snake.move(direction);
	coord headpos = snake.getHeadPos();
	try
	{
		if (board.getFieldValue(headpos) == APPLE)
		{
			snake.eatApple();
			placeApple();
		}
		else if (isBadSymbol(board.getFieldValue(headpos)))
		{
			isactive = false;
		}
	}
	catch(std::out_of_range)
	{
		isactive = false;
		return;
	}
	board.setFieldValue(headpos, HEAD);
	if (snake.hasEaten())
	{
		snake.switchHasEaten();
	}
	else
	{
		coord tail = snake.getTailPos();
		board.setFieldValue(tail, EMPTY);
		snake.popTail();
	}
}

bool Game::isBadSymbol(char symbol)
{
	return symbol != APPLE && symbol != EMPTY;
}

bool Game::isGameActive()
{
	return isactive;
};

int Game::getRandomInt(int lowest, int highest)
{
	std::uniform_int_distribution<int> dist(lowest, highest);
	return dist(gen);
}

void Game::placeApple()
{
	coord apple_coord;
	do
	{
		apple_coord = {getRandomInt(1, board.getHeight() - 1), getRandomInt(1, board.getWidth() - 1)};
	} while (board.getFieldValue(apple_coord) != EMPTY);
	board.setFieldValue(apple_coord, APPLE);
}

std::string Game::getBoard() {return board.parseToString();}
