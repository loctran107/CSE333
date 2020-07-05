#include <stdio.h>
#include <inttypes.h>

int main(int argc, char** argv) {

	uint8_t a_byte = 0xD1;
	printf("The byte is: %02" PRIx8 " --enjoy!\n", a_byte);
	return 0;	

}
