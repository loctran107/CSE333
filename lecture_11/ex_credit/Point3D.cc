#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Point3D.h"


using namespace std;
Point3D(int x, int y, int z) {

	//Assigning data members
	this.x_ = x;
	this.y_ = y;
	this.z_ = z;
}

int innerProduct(const Point3D& p) {

	
	//Dot product calculation
	return p.get_x() * x_ + p.get_y() * y_ + p.get_z() * z_;
}

double distancePoint3D(const Point3D& p) {

	//Distance calculation
	int distance_x = (p.get_x() - x_) * (p.get_x() - x_);
	int distance_y = (p.get_y() - y_) * (p.get_y() - y_);
	int distance_z = (p.get_z() - z_) * (p.get_z() - z_);
	return sqrt(distance_x + distance_y + distance_z);
}


