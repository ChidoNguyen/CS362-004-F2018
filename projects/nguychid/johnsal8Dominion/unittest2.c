#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

// Tetsing isGameOver() //



void testGameOver() {

	struct gameState *temp = malloc(sizeof(struct gameState));
	int case1 = -1;
	int case2 = 0;
	int x = 0;
	int results = 0, passed = 0, failed = 0;

	for (x = 0; x < 25; x++) {
		temp->supplyCount[x] = 1;
	}
	printf("isGameOver(): Pre-populated with no empty piles\n");
	temp->supplyCount[province] = case1;
	results = isGameOver(temp);
	if (results != 1) {
		printf("isGameOver(): -1 province count test: \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): -1 province count test: \tFAILED\n");
		failed++;
	}
	temp->supplyCount[province] = case2;
	results = isGameOver(temp);
	if (results) {
		printf("isGameOver(): 0 province count test: \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 0 province count test: \tFAILED\n");
		failed++;
	}

	temp->supplyCount[province] = case1;
	results = isGameOver(temp);
	if (results != 1) {
		printf("isGameOver(): 1 province count test: \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 1 province count test: \tFAILED\n");
		failed++;
	}

	//fill all our supply counts to 1 //
	int j = 0;

	results = isGameOver(temp);
	if (results == 0) {
		printf("isGameOver(): 0 empty piles : \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 0 empty piles: \tFAILED\n");
		failed++;
	}
	//introduce incremental  empty piles till it fails //
	temp->supplyCount[j] = 0;
	j++;
	results = isGameOver(temp);
	if (results == 0) {
		printf("isGameOver(): 1 empty piles : \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 1 empty piles: \tFAILED\n");
		failed++;
	}

	temp->supplyCount[j] = 0;
	j++;
	temp->supplyCount[j] = 0;
	j++;
	results = isGameOver(temp);
	if (results) {
		printf("isGameOver(): 3 empty piles : \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 3 empty piles: \tFAILED\n");
		failed++;
	}

	for (x = 0; x < 25; x++) {
		temp->supplyCount[x] = 0;
	}
	results = isGameOver(temp);
	if (results) {
		printf("isGameOver(): 25 empty piles : \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 25 empty piles: \tFAILED\n");
		failed++;
	}

	printf("isGameOver() : PASSED COUNT %i \t FAILED COUNT %i\n", passed, failed);

}


int main(int argc, char * argv[]) {
	testGameOver();
	return 0;
}