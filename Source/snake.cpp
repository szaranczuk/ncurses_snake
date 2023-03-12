#include "snake.hpp"
#include "coord.hpp"

Snake::Snake() {}

void Snake::move(directions direction)
{
	coord head_pos = getHeadPos();
	coord new_head_pos = head_pos + move_vector[direction];
	setHeadPos(new_head_pos);
}

coord Snake::getHeadPos() {return snake.front();}

void Snake::setHeadPos(coord value) {snake.push_front(value);}

coord Snake::getTailPos() {return snake.back();}

void Snake::eatApple()
{
	if (!hasEaten())
	{
		switchHasEaten();
	}
}

void Snake::switchHasEaten() {has_eaten = !has_eaten;}

void Snake::popTail() {snake.pop_back();}

bool Snake::hasEaten() {return has_eaten;}