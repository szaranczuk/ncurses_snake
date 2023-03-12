#pragma once
#include "coord.hpp"
#include <string>
#include <vector>

class Board
{
	public:
		Board(int _height, int _width);
		char getFieldValue(coord field);
		void setFieldValue(coord field, char value);
		std::string parseToString();
		int getWidth();
		int getHeight();
	private:
		const int height;
		const int width;
		std::vector<std::vector<char>> board;
};