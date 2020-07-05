#include <stdio.h> //For NULL
#include <stdlib.h> //For malloc and free
#include <assert.h> //for assert

#include "complex.h"

Complex* add(Complex* num1, Complex* num2, Complex* result) {
	result->real = num1->real + num2->real;
	result->imag = num1->imag + num2->imag;
	return result;	
}

Complex* subtract(Complex* num1, Complex* num2, Complex* result) {

	result->real = num1->real - num2->real;
	result->imag = num1->imag - num2->imag;	
	return result;
}

Complex* multiply(Complex* num1, Complex* num2, Complex* result) {

	result->real = num1->real * num2->real - num1->imag * num2->imag;
	result->imag = num1->real * num2->imag + num1->imag * num2->real;
	return result;	
}

Complex* divide(Complex* num1, Complex* num2, Complex* result) {

	result->real = (num1->real / num2->real) + (num1->imag / num2->imag);
	result->imag = (num1->imag / num2->real) - (num1->real / num2->imag);
	return result;	
}
