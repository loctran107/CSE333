#include <stdio.h>
#include <stdlib.h>


//Change the string by passing by reference
//
void change(char** str) {

	*str = "Hello Pikachu";
	return;
}

int main(int argc, char** argv) {

	char* str = "Hello Donavan";
	change(&str);
	printf("%s\n", str);
	return EXIT_SUCCESS;

}
