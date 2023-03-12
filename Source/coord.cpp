#include "coord.hpp"


bool operator==(const coord& a, const coord& b)
{
	return a.x == b.x && a.y == b.y;
}
bool operator!=(const coord& a, const coord& b)
{
	return !(a == b);
}
void operator+=(coord& a, const coord& b)
{
	a.x += b.x;
	a.y += b.y;
};
void operator-=(coord& a, const coord& b)
{
	a.x -= b.x;
	a.y -= b.y;
}
coord operator+(const coord& a, const coord& b)
{
	coord out;
	out.y = a.y + b.y;
	out.x = a.x + b.x;
	return out;
}
coord operator-(const coord& a, const coord& b)
{
	coord out;
	out.y = a.y - b.y;
	out.x = a.x - b.x;
	return out;
}