#pragma once

using namespace std;
#include  "error.h"

class Point
{
public:
	double x;
	double y;

	Point(double _x, double _y);
};

class Segment
{
private:
	Point* start;
	Point* end;
	//bool valid;

public:
	Segment(Point* st, Point* ed);

	Segment(double x1 = 0, double y1 = 1, double x2 = 0, double y2 = 1);
	
};