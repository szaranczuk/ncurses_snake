#include "game.hpp"

Game::Game(int _height, int _width) : board(_height, _width)
{
	gen.seed(std::random_device{}());
	isactive = true;
}

void Game::takePlayerTurn(directions direction)
{
	snake.move(direction);
	coord headpos = snake.getHeadPos();
	if (board.getFieldValue(headpos) == APPLE)
	{
		snake.eatApple();
		placeApple();
	}
	else if (isBadSymbol(board.getFieldValue(headpos)))
	{
		isactive = false;
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
