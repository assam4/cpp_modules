#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float, const float);
		Point(const Point&);
		~Point();
	public:
		Point& operator=(const Point&);
	public:
		float	getX() const;
		float	getY() const;
	private:
		const Fixed	m_x;
		const Fixed	m_y;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
