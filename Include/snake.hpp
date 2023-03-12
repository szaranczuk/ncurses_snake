#pragma once
#include "coord.hpp"
#include <queue>

class Snake
{
	public:
		Snake();
		void move(directions direction);
		coord getHeadPos();
		void setHeadPos(coord value);
		coord getTailPos();
		void eatApple();
		bool hasEaten();
		void switchHasEaten();
		void popTail();
	private:
		std::deque<coord> snake;
		bool has_eaten = false;
};