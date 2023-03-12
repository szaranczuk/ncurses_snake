#pragma once
#include <vector>

enum directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
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