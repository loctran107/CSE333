//Complex number includes both the 
//real and imaginary numbers
typedef struct complex_st {
	
	double real;
	double imag;
} Complex;

Complex* add(Complex* num1, Complex* num2, Complex* result);
Complex* subtract(Complex* num1, Complex* num2, Complex* result);
Complex* divide(Complex* num1, Complex* num2, Complex* result);
Complex* multiply(Complex* num1, Complex* num2, Complex* result);


