#include "dominion.h"
#include <stdio>
#include <math.h>
#include <stdlib>
#include <limits.h>

//Unit Testing for the compare() function //
//Param: two int variables a and b
//Returns: 1 if A is greater than (B less than)
//        -1 if A is less than (B greater than)
//         0 if equal

void testCompare() {
	int a, b, c, d, e, result;
	int passed;
	int failed;

	a = INT_MIN;
	b = INT_MAX;

	result = compare(a, b);
	if (result == -1) {
		printf("COMPARE(): INT_MIN < INT_MAX : PASSED");
		passed++;
	}
	else {
		printf("COMPARE(): INT_MIN < INT_MAX: FAILED");
		failed++;
	}

	result = compare(b, a);

	if (result == 1) {
		printf("COMPARE(): INT_MIN > INT_MAX : PASSED");
		passed++;
	}
	else {
		printf("COMPARE(): INT_MIN > INT_MAX: FAILED");
		failed++;
	}
	
	a = b;
	result = compare(a, b);
	if (result == 0) {
		printf("COMPARE(): INT_MIN == INT_MAX : PASSED");
		passed++;
	}
	else {
		printf("COMPARE(): INT_MIN == INT_MAX: FAILED");
		failed++;
	}
	

}

int main(int argc, char *argv[]) {

}
