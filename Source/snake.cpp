#include "snake.hpp"
#include "coord.hpp"
#include <exception>
#include <stdexcept>

Snake::Snake() {}

void Snake::move(directions direction)
{
	coord head_pos = getHeadPos();
	coord new_head_pos = head_pos + move_vector[direction];
	setHeadPos(new_head_pos);
	setCurentDirection(direction);
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

directions Snake::getCurentDirection() {return current_direction;}

void Snake::setCurentDirection(directions value) {current_direction = value;}

int Snake::getSize() {return snake.size();}

bool Snake::isBackMove(directions direction) 
{
	try
	{
		return -1 * move_vector[direction] == move_vector[getCurentDirection()];
	}
	catch (std::out_of_range)
	{
		return false; //probably first move, so getCurrentDirection() returns NULL_DIRECTION
	}
}