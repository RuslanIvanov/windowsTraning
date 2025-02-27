#pragma once
class Point
{
	int m_x;
	int m_y;

	public:
		Point(int x = 0, int y = 0);
		Point(const Point& r);
		//Point( Point&& r);
		Point& operator=(const Point&);
		
		Point operator+(const Point&); // ����� ������� ������ �����, �.�. �������� ������ ���� �� ����
		Point operator+(int);
		//Point& operator-(const Point&);
	
		Point& operator+=(const Point&);

		Point operator+();

		bool operator==(const  Point&) const;
		
		friend Point& operator+=(Point&, int);
		friend Point operator-(Point& rl, int i);
		friend Point operator-(Point& rl, const Point& rr);
		friend Point operator+(int, Point& r);
		friend Point operator-(const Point& r);

		void print();
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

Point& operator+=(Point&, int);
Point operator-(Point& rl, int i);
Point operator-(Point& rl, const Point& rr);
Point operator+(int, Point& r);
Point operator-(const Point& r);

std::ostream& operator<<(std::ostream& os, const Point& p);

