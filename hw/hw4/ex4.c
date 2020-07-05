#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "NthPrime.h"

int main(int argc, char** argv) {
		
	//Test the NthPrime method
	printf("The nth prime number of %d is %ld\n", atoi(argv[1]), NthPrime(atoi(argv[1])));

	return EXIT_SUCCESS;

}
