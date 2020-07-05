// Original solution

/*#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;

void printArrayReverse(int* input, int size);
int main(int argc, char** argv) {

	int num, i;
	int input[SIZE] = { 0 };
	string prompt("Type the float number below: ");
	
	for (i = 0; i < SIZE; i++) {
		cout << prompt << endl;
		cin >> num;
		input[i] = num;
	
	}

	printArrayReverse(input, SIZE);
	
	return EXIT_SUCCESS;
}

void printArrayReverse(int* input, int size) {
	for (int i = SIZE - 1; i >= 0; i--) {
		cout << input[i] << " ";
		
	}
	cout << endl;

}*/

//Recommended solution

#include <iostream> //for std:cout, std:Cin, std:cerr;
#include <cstdlib> // for EXIT_SUCCESS
#include <cassert> //for assert()
#include <string> //for string object

//Write a C++ Program that uses stream to:
//
//- prompt the user to type in 5 floats
//- print them out in opposite order iwth 4 digits of precision
//
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;


#define NUMFLOATS 5
int main(int argc, char** argv) {

	float input[NUMFLOATS];
	int i;

	cout << "Type in a whitespace-separated list of " << NUMFLOATS << " ";
	cout << "floats: " << endl;

	for (i = 0; i < NUMFLOATS; ++i) {

		//Try to read the next float from cin; we'll call cin's
		//good() method to make sure the input and float conversion
		//was successful
		if (!((cin >> input[i]).good())) {

			cerr << "Failed to read float " << i << ":" << endl;
			
			//Did we fail because we hit the end of file?
			if (cin.eof()) {
				cerr << " [hit EOF] " << endl;
				return EXIT_FAILURE;
			}
		}

		//Help out the user by printing the offending input
		string broken;
		cin.clear();
		cin >> broken;
		cout << "You broke" << endl;
		cerr << " [" << broken << "]" << endl;
		return EXIT_FAILURE;
	}

	//print out the arrya, but reversed
	for (i = NUMFLOATS - 1; i > 0; i--) {
		cout << input[i] << " ";
	}
	cout << input[0] << endl;
	return EXIT_SUCCESS;

}
