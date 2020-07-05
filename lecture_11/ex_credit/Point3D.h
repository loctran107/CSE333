#ifndef _POINT3D_H_
#define _POINT3D_H_

#include <iostream>
using namespace std;
class Point3D {
	public:
		Point3D(const int x, const int y, const int z); //public constructor
		int get_x() const { return x_; } // inline member function
		int get_y() const { return y_; } //inline member function
		int get_z() const { return z_; } //inline member function
		int innerProduct(const Point3D& p);
		double distancePoint3D(const Point3D& p);
		
	private:
	        const int x_; //data member
       		const int y_; //data member
		const int z_; //data member 			

};

#endif //_POINT3D_H_
