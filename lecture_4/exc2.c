#include <stdio.h>
#include <stdlib.h>


typedef struct complex_st
{

	double real;
	double imag;
} Complex;

typedef struct complex_set_st
{
	double num_points_in_set;
	Complex* points;
} ComplexSet;

ComplexSet* AllocSet(Complex c_arr[], int size);
void FreeSet(ComplexSet* set);

int main(int argc, char** argv)
{

	Complex c_arr[3];
	Complex point1 = {1.0, 2.0};
	Complex point2 = {3.0, 4.0};
	Complex point3 = {5.0, 6.0};
	c_arr[0] = point1;
	c_arr[1] = point2;
	c_arr[2] = point3;
	ComplexSet* set = AllocSet(c_arr, 3);
	
	for (int i = 0; i < set->num_points_in_set; i++) {
		Complex points = set->points[i];
		printf("point%d: (%f, %f)\n", i + 1, points.real, points.imag);
	}
	FreeSet(set);

}

ComplexSet* AllocSet(Complex c_arr[], int size) 
{
	int i;
	//Malloc a new ComplexSet
	ComplexSet* set = (ComplexSet*) malloc(sizeof(ComplexSet));
	set->num_points_in_set = size;
	//allocate the point field inide
	set->points = (Complex*) malloc(size * sizeof(Complex));
	
	for (i = 0; i < size; i++) {
		set->points[i] = *(c_arr + i);
	}
	return set;
}

void FreeSet(ComplexSet* set)
{
	//free the array of point field inside set
	free(set->points);

	//Free the entire set
	free(set);


}
