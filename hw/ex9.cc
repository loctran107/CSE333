#include <iostream>
#include <cstdlib>

#include "IntPair.h"

using namespace std;

void Test(IntPair pair);

int main(int argc, char** argv) {
	
	IntPair pair(2, 3);
	Test(pair);

}

void Test(IntPair pair) {
	int x, y;
	pair.Get(&x, &y);
	cout << "The x is " << x << " and y is " << y << endl;
	pair.Set(x + 1, y + 1);
	pair.Get(&x, &y);
	cout << "The x is " << x << " and y is " << y<< endl;

}
