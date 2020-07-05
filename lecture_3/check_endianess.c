#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char** argv) {
	int i = 0;

	//Can use a hex number to quickly determine
	//endianness by eye-balling
	int num = 0x01234567;
	int* ptr = &num;
        char* byte = (char*) ptr;
	for (i = 0; i < sizeof(int); i++) {		
		printf("0x%.2x ", *(byte + i));
	}
	
	printf("\n");
	return 0;


}*/

//Another efficient way to determine endianess
int main(int argc, char** argv) {

	int i = 1;
	char* ptr = (char*) &i;
	
	if (*ptr) {
		printf("Little Endian\n");
	} else {
		printf("Big endian\n");
	}
	return 0;

}
