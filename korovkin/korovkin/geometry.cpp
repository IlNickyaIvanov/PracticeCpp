using namespace std;
#include <iostream>
#include  "error.h"
#include "geometry.h"

Point::Point(double _x, double _y)
	{
		x = _x;
		y = _y;
		cout << "Point was created" << endl;
	}

Segment::Segment(Point* st, Point* ed)
	{
		if ((st != nullptr) && (ed != nullptr)) {
			start = st;
			end = ed;
			cout << "Segment was created" << endl;
			//valid = true;
		}
		else {
			cout << "Error" << endl;
			throw(Error());
			//valid = false;
			//exit(1);
		}
	}
Segment::Segment(double x1, double y1, double x2, double y2)
	{
		*start = Point(x1, y1);
		*end = Point(x2, y2);
		cout << "Segment was created" << endl;
	}