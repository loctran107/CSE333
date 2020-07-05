#include <stdio.h>
#include <stdlib.h>

void changeString(char** str) {

	*str = "Hello Donavan";
}

int main(int argc, char** argv) {


	char* str = "hello world";
	changeString(&str);
	printf("%s\n", str);

}
