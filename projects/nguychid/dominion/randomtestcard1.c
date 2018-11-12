#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include "dominion.h"

#define TESTRUN  1000

struct gameState* newGame();
int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

// Test Smithy Card
// Expect 3 carrds to be drawn

int main(int argc, char* argv[]) {
	srand(time(0));
	// pass fail count
	cardCountPass = 0;
	// new game 
	struct gameState *game = newGame();
	struct gameState *originalGame = newGame();
	int numberPlayers = 2;
	// No use for Adventurer
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int handPos = 0;
	int k[10] = { adventurer, embargo, village, outpost, mine, cutpurse, sea_hag, great_hall, smithy, council_room };

	for (int x = 0; x < TESTRUN; x++) {
		int randomSeed = rand();
		// initialize new game and copy original game state
		initializeGame(numberPlayers, k, randomSeed, game);
		memcpy(originalGame, game, sizeof(struct gameState));

		// Play the card 

		cardEffect(smithy, choice1, choice2, choice3, game, handPos, &bonus);
		//

		if (game->handCount[0] - 2 == originalGame->handCount[0]) {
			cardCountPass++;
		}
	}

	printf("Smithy Random Test: %i/ %i Runs Passed.\n", cardCountPass, TESTRUN);
}

