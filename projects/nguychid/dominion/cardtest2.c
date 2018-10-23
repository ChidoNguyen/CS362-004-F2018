#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include <math.h>
#include "rngs.h"

//Testing Adventurer Card//
//reveal cards from own deck until you reveal 2 treasure cards
//put those 2 treasure card into hand
// discard the others
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
void testAdvent() {
	int x = 0, y = 0;
	int numPlayers = 2;
	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;
	int k[10] = { adventurer, embargo, village, outpost, mine, cutpurse,
			sea_hag, great_hall, smithy, council_room };
	int randomSeed = rand();

	struct gameState *state = malloc(sizeof(struct gameState));
	struct gameState *originalState = malloc(sizeof(struct gameState));

	//intialize a game//
	if (initializeGame(numPlayers, k, randomSeed, state)) {
		printf("Initializing game failed.\n");
	}
	//copy state//
	memcpy(originalState, state, sizeof(struct gameState));
	printf("TESTING ADVENTURER CARD:\n");
	int results = cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus);
	printf("Discarding Adventurer and Drawing Until 2 Treasure Cards: Net Gain Expected of +1 Cards\n");
	int handTreasure = 0 ;
	int	postHandTreasure = 0;
	
	while (state->hand[0][x] != 0) {
		int tmp = state->hand[0][x];
		if (tmp >= 4 && tmp <= 6)
			postHandTreasure++;
		x++;
	}
	while (originalState->hand[0][y] != 0) {
		int tmp = state->hand[0][y];
		if (tmp >= 4 && tmp <= 6)
			handTreasure++;
		y++;
	}
	printf("Orignal State: %i\tPost Play State: %i\n", handTreasure, postHandTreasure);
	if ( postHandTreasure - 1 == handTreasure)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

int main(int argc, char*argv[]) {
	testAdvent();
	return 0;
}