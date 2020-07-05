#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "NthPrime.h"

__int64_t PrimeOrNot(__int64_t prime);

__int64_t NthPrime(__int16_t n) {
	
	//corner-case: n is less than 1
	if (n < 1) {
		printf("Error: Please enter number greater than 1\n");
		exit(0);
	}
	
	__int64_t isPrime = 0;
	__int64_t prime = 1;
	while (isPrime < n) {
		prime++;
		if (PrimeOrNot(prime)) {
			isPrime++;	
		}
	}
	return prime;
}

__int64_t PrimeOrNot(__int64_t prime) {
	
	for (int i = 2; i < prime; i++) {
		if (prime % i == 0) {
			return 0;
		}
	}
	return 1;
}


