#include "SimplePoint.h"

//Default consructor//
SimplePoint::SimplePoint() {
	x_ = 0;
	y_ = 0;

}

//Constructors with 2 arguments
SimplePoint::SimplePoint(const int x, const int y) {
	
	x_ = x;
	y_ = y;

}	

void foo() {
	SimplePoint x; //caling default constructor
	SimplePoint a[3]; //calling default constructor twice
	SimplePoint y(1, 2); //invokes the definte constructor
}
