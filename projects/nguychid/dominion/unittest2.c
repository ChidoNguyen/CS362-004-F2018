#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

// Tetsing isGameOver() //

int isGameOver(struct gameState *state) {
	int i;
	int j;

	//if stack of Province cards is empty, the game ends
	if (state->supplyCount[province] == 0)
	{
		return 1;
	}

	//if three supply pile are at 0, the game ends
	j = 0;
	for (i = 0; i < 25; i++)
	{
		if (state->supplyCount[i] == 0)
		{
			j++;
		}
	}
	if (j >= 3)
	{
		return 1;
	}

	return 0;
}

void testGameOver() {

	struct gameState *temp = malloc(sizeof(struct gameState));
	int case1 = -1;
	int case2 = 0;
	int case3 = 1;
	int x = 0;
	int results, passed, failed;

	temp->supplyCount[Province] = case1;
	results = isGameOver(temp);
	if (results != 1) {
		printf("isGameOver(): -1 province count test: \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): -1 province count test: \tFAILED\n");
		failed++;
	}
	temp->supplyCount[Province] = case2;
	results = isGameOver(temp);
	if (results != 1) {
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
	for ( x = 0; x < 25; x++) {
		temp->supplyCount[x] = 1;
	}

	result = isGameOver(temp);
	if (result == 0) {
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
	result = isGameOver(temp);
	if (result == 0) {
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
	result = isGameOver(temp);
	if (result) {
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
	result = isGameOver(temp);
	if (result) {
		printf("isGameOver(): 25 empty piles : \tPASSED\n");
		passed++;
	}
	else {
		printf("isGameOver(): 25 empty piles: \tFAILED\n");
		failed++;
	}

	printf("isGameOver() : PASSED COUNT %i \t FAILED COUNT %i", passed, failed);

}


int main(int argc, char * argv[]) {
	testGameOver();
	return 0;
}