#include "Point.h"
#include <iostream>
//Globals:///////////////////////////////////////////////////////////
Point& operator+=(Point& rl, int i) 
{
	rl.m_x += i;
	rl.m_y += i;

	return rl;
}

Point/*&*/ operator-(Point& rl, int i)
{
	//rl.m_x -= i;
	//rl.m_y -= i;	return rl;

	return Point(rl.m_x-i, rl.m_y-i);
}

Point/*&*/ operator-(Point& rl, const Point& rr)
{
	//rl.m_x -= rr.m_x;
	//rl.m_y -= rr.m_y;	return rl;

	return Point(rl.m_x - rr.m_x, rl.m_y - rr.m_y);
}

Point/*&*/ operator+(int i, Point& r)
{
	//r.m_x += i; 
	//r.m_y += i; return r;

	return Point(r.m_x + i, r.m_y + i);
}
///////////////////////////////////////////////////////////////////////////////////

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::Point(const Point& r)
{
	m_x = r.m_x;
	m_y = r.m_y;
}

Point& Point::operator=(const Point& r)
{
	if (this == &r) { return *this; }

	m_x = r.m_x;
	m_y = r.m_y;

	return *this;
}

Point& Point::operator+=(const Point& r)
{
	m_x += r.m_x;
	m_y += r.m_y;

	return *this;
}

Point/*&*/ Point::operator+(const Point& r)
{	
	//m_x += r.m_x;
	//m_y += r.m_y; return *this;
	return Point(m_x + r.m_x, m_y + r.m_y);
}
/*
Point& Point::operator-(const Point& r)
{
	m_x -= r.m_x;
	m_y -= r.m_y;

	return *this;
}//*/

Point/*&*/ Point::operator+(int i)
{
	//m_x += i;
	//m_y += i;
	//return *this;
	
	return Point(m_x + i, m_y + i);
}

Point Point::operator+() 
{//��� ���� ������
	//m_x += 1;
	//m_y += 1;
	return *this;
}
Point operator-(const Point& r)
//Point& Point::operator-()
{
	//m_x -= 1;
	//m_y -= 1;
	return Point(-r.m_x,-r.m_y);
}

void Point::print()
{
	std::cout << "\npoint: m_x = " << m_x << " m_y = " << m_y;
}