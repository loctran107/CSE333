#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

int main(int argc, char** argv) {
	
	Complex* num1 = (Complex*) malloc(sizeof(Complex));
	Complex* num2 = (Complex*) malloc(sizeof(Complex));
	Complex* result = (Complex*) malloc(sizeof(Complex));
	
	num1->real = 3.0;
	num1->imag = 5.0;
	num2->real = -2.5;
	num2->imag = 1.5;
	result = add(num1, num2, result);
	printf("(%.2f + %.2fi) + (%.2f + %.2fi) = %.2f + %.2fi\n", num1->real, num1->imag, num2->real, num2->imag, result->real, result->imag);
	
	free(num1);
	free(num2);
	free(result);
	
	return EXIT_SUCCESS;
}
