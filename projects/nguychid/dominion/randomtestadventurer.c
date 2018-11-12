#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>

#define TESTRUN  1000
srand(time(null));


// Test Adventurer Card
// Expect 2 card to be drawn , and discard pile to potentially change

int main(int argc, char* argv[]) {
	// pass fail count
	int treasurePass = 0;
	int treasureFail = 0;
	int discardPass = 0;
	int discardFail = 0;
	// new game 
	struct gameState game = newGame();
	struct gameState originalGame = newGame();
	int numberPlayers = 2;
	// No use for Adventurer
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int k[10] = { adventurer, embargo, village, outpost, mine, cutpurse, sea_hag, great_hall, smithy, council_room };
	
	for (int x = 0; x < TESTRUN; x++) {
		int randomSeed = rand();
		// initialize new game and copy original game state
		initializeGame(numberPlayers, k, randomSeed,game);
		memcpy(&originalGame, game, sizeof(struct gameState));
		
		// Play the card 

		cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus);

		// iterate through the hand make sure we've gained 2 treasure cards
		int handTreasure = 0;
		int	postHandTreasure = 0;
		int y = 0, z = 0;
		// count hand of game playing card
		while (state->hand[0][z] != 0) {
			int tmp = state->hand[0][z];
			if (tmp >= 4 && tmp <= 6)
				postHandTreasure++;
			z++;
		}
		// count hand of copy of game pre-card play
		while (originalState->hand[0][y] != 0) {
			int tmp = state->hand[0][y];
			if (tmp >= 4 && tmp <= 6)
				handTreasure++;
			y++;
		}
		if (postHandTreasure - 1 == handTreasure) {
			treasurePass++;
		}
		else
			treasureFail++;
		
		if (game->discardCount[0] != originalGame->discardCount[0]) {
			discardPass++;
		}
		else
			discardFail++;
	}
	printf("Adventurer Card Random Test: Treasure Drawing Passed %i / %i Runs. Discard Aspect Passed %i / %i\n", treasurePass, TESTRUN, discardPass, TESTRUN);

	return 0;
}


