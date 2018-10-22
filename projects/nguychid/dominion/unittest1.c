
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

//Unit Testing for the compare() function //
//Param: two int variables a and b
//Returns: 1 if A is greater than (B less than)
//        -1 if A is less than (B greater than)
//         0 if equal

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	if (*(int*)a < *(int*)b)
		return -1;
	return 0;
}

void testCompare() {
	int result;
	int passed;
	int failed;

	const int a = INT_MIN;
	const int b = INT_MAX;

	result = compare(&a, &b);
	if (result == -1) {
		printf("COMPARE(): INT_MIN < INT_MAX : PASSED");
		passed++;
	}
	else {
		printf("COMPARE(): INT_MIN < INT_MAX: FAILED");
		failed++;
	}

	result = compare(&b, &a);

	if (result == 1) {
		printf("COMPARE(): INT_MIN > INT_MAX : PASSED");
		passed++;
	}
	else {
		printf("COMPARE(): INT_MIN > INT_MAX: FAILED");
		failed++;
	}
	
	result = compare(&a, &a);
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
	testCompare();
	return 0;
}
