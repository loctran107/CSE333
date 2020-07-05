#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct point_3d
{
	int16_t x, y, z;
} Point3d, *Point3dPtr;

Point3dPtr AllocatePoint3d(int16_t x, int16_t y, int16_t z) 
{
	//malloc space of point3d
	Point3dPtr point3d = (Point3dPtr) malloc(sizeof(Point3d));
	if (point3d == NULL) {
		perror("Error: Allocation Error");
		exit(EXIT_FAILURE);
	}
	//assigning point3d field to respective variable
	point3d->x = x;
	point3d->y = y;
	point3d->z = z;
	return point3d;
}

int main(int argc, char** argv) {
	
	//Test AllocatePoint3d
	Point3dPtr point3d = AllocatePoint3d(1, 2, 3);
	
	//Verify
	printf("x field is %d\n", point3d->x);
	printf("y field is %d\n", point3d->y);
	printf("z field is %d\n", point3d->z);
	
	free(point3d);
}
