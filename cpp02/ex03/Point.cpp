#include "Point.hpp"

Point::Point() {
}

Point::Point(const float x, const float y): m_x(x), m_y(y) {
}

Point::Point(const Point& other): m_x(other.m_x), m_y(other.m_y) {
}

Point::~Point() {
}

Point&	Point::operator=(const Point&) {
	return *this;
}

float	Point::getX() const {
	return m_x.toFloat();
}

float	Point::getY() const {
	return m_y.toFloat();
}

static float cross(const Point p1, const Point p2, const Point p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool    bsp(const Point a, const Point b, const Point c, const Point point) {
	const float	EPS = 1e-6f;
	float	sign1 = cross(point, a, b);
	float	sign2 = cross(point, b, c);
	float	sign3 = cross(point, c, a);
	bool	isNotZero = (fabs(sign1) > EPS && fabs(sign2) > EPS && fabs(sign3) > EPS);
	bool	isNeg = (sign1 < 0 || sign2 < 0 || sign3 < 0);
	bool	isPos = (sign1 > 0 || sign2 > 0 || sign3 > 0);
	return !(isNeg && isPos) && isNotZero;
}
