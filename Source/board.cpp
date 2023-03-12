#include "board.hpp"
#include "game.hpp"

Board::Board(int _height, int _width) : height(_height), width(_width)
{
	board.resize(height);
	for (int i = 0; i < height; i++)
	{
		board[i].assign(width, EMPTY);
	}
}

char Board::getFieldValue(coord field) {return board[field.y][field.x];}

void Board::setFieldValue(coord field, char value) {board[field.y][field.x] = value;}

int Board::getHeight() {return height;}

int Board::getWidth() {return width;}

std::string Board::parseToString()
{
	std::string out;
	for (const auto& row : board)
	{
		out.insert(out.size(), std::string(row.begin(), row.end()));
		out.push_back('\n');
	}
	return out;
}
