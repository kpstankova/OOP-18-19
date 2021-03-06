#include "pch.h"
#include <iostream>
#include<iomanip>
using namespace std;
struct Point
{
	int x;
	int y;
	
};
struct Rectangle
{
	Point A;
	Point B, C, D;
	int width;
	int height;

	void OtherPoints();

};

void Rectangle::OtherPoints()
{
	D.y = A.y - height;
	D.x = A.x;
	C.y = D.y;
	C.x = D.x + width;
	B.y = A.y;
	B.x = A.x + width;
}

int getIntersectionArea(Rectangle& r1, Rectangle& r2)
{
	if (!(r2.A.x < r1.B.x && r2.A.y > r1.C.y && r2.D.x > r1.D.x && r2.D.y < r1.A.y))
	{
		cout << "The rectangles do not intersect" << endl;
		return 0;
	}

	Point newA, newC;
	if (r1.A.x > r2.A.x)
	{
		newA.x = r1.A.x;
	}
	else newA.x = r2.A.x;
	if (r1.A.y < r2.A.y)
	{
		newA.y = r1.A.y;
	}
	else newA.y = r2.A.y;
	if (r1.C.x < r2.C.x)
	{
		newC.x = r1.C.x;
	}
	else newC.x = r2.C.x;
	if (r1.C.y > r2.C.y)
	{
		newC.y = r1.C.y;
	}
	else newC.y = r2.C.y;
	
	int intersectionArea= (newC.x - newA.x)*(newA.y - newC.y);

	return intersectionArea;
	
}
int main()
{
	Rectangle firstRectangle, secondRectangle;
	cout << "+-----------------------------+" << endl;
	cout << "|"<< setw(20) << "FIRST RECTANGLE"<< setw(10) <<"|"<< endl;
	cout << "+-----------------------------+" << endl;
	cout << "X= ";
	cin >> firstRectangle.A.x;
	cout << "Y= ";
	cin >> firstRectangle.A.y;
	do {
		cout << "Enter height of the rectangle: ";
		cin >> firstRectangle.height;
	} while (firstRectangle.height == 0);
	do {
			cout << "Enter width of the rectangle: ";
			cin >> firstRectangle.width;
	} while (firstRectangle.width == 0);
	cout << "+-----------------------------+" << endl;
	cout << "|"<<setw(20) << "SECOND RECTANGLE"<<setw(10) <<"|"<< endl;
	cout << "+-----------------------------+" << endl;
	cout << "X= ";
	cin >> secondRectangle.A.x;
	cout << "Y= ";
	cin >> secondRectangle.A.y;
	do {
		cout << "Enter height of the rectangle: ";
		cin >> secondRectangle.height;
	} while (secondRectangle.height == 0);
	do {
		cout << "Enter width of the rectangle: ";
		cin >> secondRectangle.width;
	} while (secondRectangle.width == 0);
	cout << "---------------------------------------" << endl;

	firstRectangle.OtherPoints();
	secondRectangle.OtherPoints();
	
	cout << "Intersection area of the rectangles: " << getIntersectionArea(firstRectangle, secondRectangle) << endl;
	return 0;
}

