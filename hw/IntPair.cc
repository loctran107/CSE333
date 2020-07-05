#include <iostream>
#include <cstdlib>

#include "IntPair.h"

void IntPair::Get(int* const x, int* const y) {
	*x = x_;
	*y = y_;
}

void IntPair::Set(const int x, const int y) {
	
 	x_ = x;
	y_ = y;
}


