#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

//testing fullDeckCount() //


void testScoreFor() {
	// Hand Test //
	int score;
	int x;
	//tests handCount //
	for (x = 0; x < 6; x++) {
		int player = 0;
		struct gameState * state = malloc(sizeof(struct gameState));

		switch (x)
		{
			case 0:
				populateHand(curse, state, player);
				score = scoreFor(0, state);
				if (score == -10) {
					printf("scoreFor() -> handCount -> curse: Expected Score of -10 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> curse: Expected Score of -10 \t Score: %i\t FAILED\n", score);
				break;
			case 1:
				populateHand(estate, state, player);
				score = scoreFor(0, state);
				if (score == 10) {
					printf("scoreFor() -> handCount -> estate: Expected Score of 10 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> estate: Expected Score of 10 \t Score: %i\t FAILED\n", score);
				break;
			case 2:
				populateHand(duchy, state, player);
				score = scoreFor(0, state);
				if (score == 30) {
					printf("scoreFor() -> handCount -> duchy: Expected Score of 30 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> duchy: Expected Score of 30 \t Score: %i\t FAILED\n", score);
				break;
			case 3:
				populateHand(province, state, player);
				score = scoreFor(0, state);
				if (score == 60) {
					printf("scoreFor() -> handCount -> province: Expected Score of 60 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> province: Expected Score of 60 \t Score: %i\t FAILED\n", score);
				break;
			case 4:
				populateHand(great_hall, state, player);
				score = scoreFor(0, state);
				if (score == 10) {
					printf("scoreFor() -> handCount -> great_hall: Expected Score of 10 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> great_hall: Expected Score of 10 \t Score: %i\t FAILED\n", score);
				break;
			case 5:
				populateHand(gardens, state, player);
				score = scoreFor(0, state);
				if (score == 1) {
					printf("scoreFor() -> handCount -> gardens: Expected Score of 1 \t Score: %i\t PASSED\n", score);
				}
				else
					printf("scoreFor() -> handCount -> gardens: Expected Score of 1 \t Score: %i\t FAILED\n", score);
				break;
		}
		delete(state);
	}

	// test discard //
	for (x = 0; x < 6; x++) {
		int player = 0;
		struct gameState * state = malloc(sizeof(struct gameState));

		switch (x)
		{
		case 0:
			populateDiscard(curse, state, player);
			score = scoreFor(0, state);
			if (score == -10) {
				printf("scoreFor() -> discardCount -> curse: Expected Score of -10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> curse: Expected Score of -10 \t Score: %i\t FAILED\n", score);
			break;
		case 1:
			populateDiscard(estate, state, player);
			score = scoreFor(0, state);
			if (score == 10) {
				printf("scoreFor() -> discardCount -> estate: Expected Score of 10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> estate: Expected Score of 10 \t Score: %i\t FAILED\n", score);
			break;
		case 2:
			populateDiscard(duchy, state, player);
			score = scoreFor(0, state);
			if (score == 30) {
				printf("scoreFor() -> discardCount -> duchy: Expected Score of 30 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> duchy: Expected Score of 30 \t Score: %i\t FAILED\n", score);
			break;
		case 3:
			populateDiscard(province, state, player);
			score = scoreFor(0, state);
			if (score == 60) {
				printf("scoreFor() -> discardCount -> province: Expected Score of 60 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> province: Expected Score of 60 \t Score: %i\t FAILED\n", score);
			break;
		case 4:
			populateDiscard(great_hall, state, player);
			score = scoreFor(0, state);
			if (score == 10) {
				printf("scoreFor() -> discardCount -> great_hall: Expected Score of 10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> great_hall: Expected Score of 10 \t Score: %i\t FAILED\n", score);
			break;
		case 5:
			populateDiscard(gardens, state, player);
			score = scoreFor(0, state);
			if (score == 1) {
				printf("scoreFor() -> discardCount -> gardens: Expected Score of 1 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> discardCount -> gardens: Expected Score of 1 \t Score: %i\t FAILED\n", score);
			break;
		}
		delete( state);
	}

	//test deck//

	for (x = 0; x < 6; x++) {
		int player = 0;
		struct gameState * state = malloc(sizeof(struct gameState));

		switch (x)
		{
		case 0:
			populateDeck(curse, state, player);
			score = scoreFor(0, state);
			if (score == -10) {
				printf("scoreFor() -> deckCount -> curse: Expected Score of -10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> curse: Expected Score of -10 \t Score: %i\t FAILED\n", score);
			break;
		case 1:
			populateDeck(estate, state, player);
			score = scoreFor(0, state);
			if (score == 10) {
				printf("scoreFor() -> deckCount -> estate: Expected Score of 10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> estate: Expected Score of 10 \t Score: %i\t FAILED\n", score);
			break;
		case 2:
			populateDeck(duchy, state, player);
			score = scoreFor(0, state);
			if (score == 30) {
				printf("scoreFor() -> deckCount -> duchy: Expected Score of 30 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> duchy: Expected Score of 30 \t Score: %i\t FAILED\n", score);
			break;
		case 3:
			populateDeck(province, state, player);
			score = scoreFor(0, state);
			if (score == 60) {
				printf("scoreFor() -> deckCount -> province: Expected Score of 60 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> province: Expected Score of 60 \t Score: %i\t FAILED\n", score);
			break;
		case 4:
			populateDeck(great_hall, state, player);
			score = scoreFor(0, state);
			if (score == 10) {
				printf("scoreFor() -> deckCount -> great_hall: Expected Score of 10 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> great_hall: Expected Score of 10 \t Score: %i\t FAILED\n", score);
			break;
		case 5:
			populateDeck(gardens, state, player);
			score = scoreFor(0, state);
			if (score == 1) {
				printf("scoreFor() -> deckCount -> gardens: Expected Score of 1 \t Score: %i\t PASSED\n", score);
			}
			else
				printf("scoreFor() -> deckCount -> gardens: Expected Score of 1 \t Score: %i\t FAILED\n", score);
			break;
		}
		delete(state);
	}
	
}

void populateHand(enum CARD pick, struct gameState *state, int player) {
	state->handCount[player] = 10; // set to 10 card count
	int i;
	for (i = 0; i < state->handCount[player]; i++) {
		state->hand[player][i] = pick;
	}
}

void populateDiscard(enum CARD pick, struct gameState *state, int player) {
	state->discardCount[player] = 10; // set to 10 card count
	int i;
	for (i = 0; i < state->discardCount[player]; i++) {
		state->discard[player][i] = pick;
	}
}

void populateDeck(enum CARD pick, struct gameState *state, int player) {
	state->deckCount[player] = 10; // set to 10 card count
	int i;
	for (i = 0; i < state->deckCount[player]; i++) {
		state->deck[player][i] = pick;
	}
}

int main(int argc, char* argv[]) {
	testScoreFor();
	return 0;
}