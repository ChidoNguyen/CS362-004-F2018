#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include <math.h>
#include "rngs.h"


int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
void testVillage() {
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
	int currentPlayer = whoseTurn(state)
	//copy state//
	memcpy(originalState, state, sizeof(struct gameState));
	printf("TESTING VILLAGE CARD (+2 ACTION, +1 CARD) :\n");
	int preDraw = state->handCount[0];
	int preDisc = state->discardCount[0];
	int preAct = state->numActions;
	int result = cardEffect(village, choice1, choice2, choice3, state, handPos, &bonsu);
	int postDraw = state->handCount[0];
	int postDisc = state->discardCount[0];
	int postAct = state->numActions;
	//testing hand count before and after should be +1//
	printf("DRAWING A CARD: HAND BEFORE: %s \t HAND AFTER: %s\t\t;",preDraw, postDraw);
	if (preDraw + 1 == postDraw)
		printf("PASS\n");
	else
		printf("FAIL\n");
	//actions
	printf("ACTION +2 BEFORE: %s \t HAND AFTER: %s\t\t;", preAct, postAct);
	if (preAct + 2 == postAct)
		printf("PASS\n");
	else
		printf("FAIL\n");
	// discard
	printf("DISCARD +1 BEFORE: %s \t HAND AFTER: %s\t\t;", preDisc, postDisc);
	if (preDisc + 1 == postDisc)
		printf("PASS\n");
	else
		printf("FAIL\n");
	/////
	//state check player 2///
	printf("PLAYER 2 STATE CHECK FOR UNCHANGED HAND/DECK/DISCARD:\n");
	int Fail = 0;
	if (state->hand[1] != originalState->hand[1]) {
		printf("Failed Hand Check\n");
		Fail++;
	}
	if (state->deck[1] != originalState->deck[1]) {
		printf("Failed Deck Check\n");
		Fail++;
	}
	if (state->discard[1] != originalState->discard[1]) {
		printf("Failed Discard Check\n");
		Fail++;
	}
	if (!Fail)
		printf("PASS\n");

}

int main(int argc, char*argv[]) {
	testVillage();
	return 0;
}