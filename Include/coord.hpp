#pragma once
#include <vector>

enum directions
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

struct coord
{
	int y;
	int x;
};

const std::vector<coord> move_vector = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // UP DOWN LEFT RIGHT

bool operator==(const coord& a, const coord& b);
bool operator!=(const coord& a, const coord& b);
void operator+=(coord& a, const coord& b);
void operator-=(coord& a, const coord& b);
coord operator+(const coord& a, const coord& b);
coord operator-(const coord& a, const coord& b);