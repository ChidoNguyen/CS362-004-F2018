#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <math.h>
#include "rngs.h"

//Testing Smithy Card//
//Draw 3 cards//
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
void testSmith() {
	int numPlayers = 2;
	int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;
	int k[10] = { adventurer, embargo, village, outpost, mine, cutpurse,
			sea_hag, great_hall, smithy, council_room };
	int randomSeed = rand();
	struct gameState *state = malloc(sizeof(struct gameState));

	//intialize a game//
	if (initializeGame(numPlayers, k, randomSeed, state)) {
		printf("Initializing game failed.\n");
	}
	printf("TESTING SMITHY +3 CARDS:\n");
	int pre_draw = state->handCount[0];
	printf("CURRENT HAND COUNT:\t %i", pre_draw);
	int result = cardEffect(smithy, choice1, choice2, choice3, state, handPos, &bonus);
	printf("AFTER DRAWING HAND COUNT: \t%i\t", state->handCount);
	if (state->handCount[0] - 2 == pre_draw)
		printf("PASS\n");
	else
		printf("FAILED\n");

}


int main(int argc, char*argv[]) {
	testSmith();
	return 0;
}