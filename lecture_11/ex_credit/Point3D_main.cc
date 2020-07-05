#include <iostream>
#include <cstdlib>
#include "Point3D.h"

using namespace std;

int main(int argc, char** argv) {
			

	Point3D p1(1, 2, 3); //Allocate a new point on the stack
	Point3D p2(4, 5 ,6); //Allocate a new point on the stack
	
	double distance;
	int product;
	cout << "The distance between 2 points is: " << p1.distancePoint3D(p2)<< endl;
        cout << "The inner product between 2 points is: " << p2.innerProduct(p2) << endl;
	return EXIT_SUCCESS;

}
