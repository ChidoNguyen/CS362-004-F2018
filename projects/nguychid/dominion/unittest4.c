#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

void rigPlayers(int player, enum CARD pick, struct gameState* state);
//test getWinners()//

void testGetWinners() {
	int results;
	int play[MAX_PLAYERS];
	struct gameState *state = malloc(sizeof(struct gameState));

	//2 player testing//
	// 1 < 2
	// 1 > 2
	// 1 == 2 
	rigPlayers(0, curse, state);
	rigPlayers(1, estate, state);
	results = getWinners(&play, state);
	if (play[1] == 1 && play[0] == 0) {
		printf("getWinners(): 2 players, player-2 should win: \t\t WINNER: Player 2: PASS\n");
	}
	else
		printf("getWinners(): 2 players, player-2 should win: \t\t WINNER: Player 1: FAIL\n");

	rigPlayers(0, estate, state);
	rigPlayers(1, curse, state);
	results = getWinners(&play, state);
	if (play[0] == 1 && play[1] == 0 ) {
		printf("getWinners(): 2 players, player-1 should win: \t\t WINNER: Player 1: PASS\n");
	}
	else
		printf("getWinners(): 2 players, player-1 should win: \t\t WINNER: Player 2: FAIL\n");

	rigPlayers(0, estate, state);
	rigPlayers(1, estate, state);
	results = getWinners(&play, state);
	if (play[0] == 1 && play[1] == 1) {
		printf("getWinners(): 2 players, TIE game: \t\t WINNER: Player 1 and 2: PASS\n");
	}
	else if (play[0] == 1 && play[1] == 0)
		printf("getWinners(): 2 players, TIE game: \t\t WINNER: Player 1: FAIL\n");
	else if (play[1] == 1 && play[0] == 0)
		printf("getWinners(): 2 players, TIE game: \t\t WINNER: Player 2: FAIL\n");

}

void rigPlayers(int playerNumber, enum CARD pick, struct gameState* state) {
	int x = 0;
	for (x; x < 10;) {
		state->hand[playerNumber][x] = pick;
	}
}

int main(int argc, char* argv[]) {
	testGetWinners();
	return 0;
}