#include <stdio.h>
#include <stdlib.h>


typedef struct point_str 
{
	float x,y;
} Point, *PointPtr;

typedef struct rectangle
{
	Point bottomLeft;
	Point topRight;
} Rectangle, *RectanglePtr;

float areaRectangle(Rectangle rect) 
{
	return (rect.topRight.y - rect.bottomLeft.y) * (rect.topRight.x - rect.bottomLeft.x);
}

_Bool insideRect(Rectangle rect, Point point)
{
	float x_axis = rect.topRight.x - rect.bottomLeft.x;
	float y_axis = rect.topRight.y - rect.bottomLeft.y;
	return (point.x < x_axis && point.y < y_axis);
	
}

int main(int argc, char** argv) 
{
	
	Point point = {2.0, 2.0};
	Point topRight = {4.0, 5.0};
	Point bottomLeft = {1.0, 0.0};

	Rectangle rect;
	rect.topRight = topRight;
	rect.bottomLeft = bottomLeft;
	
	printf("Area of the rectangle is: %f\n", areaRectangle(rect));
	
	if (insideRect(rect, point)) {
		printf("Point is inside rectanlge\n");

	} else {
		printf("Point is not inside rectangle\n");
	}
}
