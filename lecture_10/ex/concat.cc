#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	string hello("Hello");
	hello = hello + ", World";
	cout << hello << endl;
	return EXIT_SUCCESS;
}
