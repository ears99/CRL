#include "dungeon.h"

Player* playerSetup() {
	Player* newPlayer;
	newPlayer = malloc(sizeof(Player));

	newPlayer->position.x = 14;
	newPlayer->position.y = 14;
	newPlayer->health = 10;

	mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
	move(newPlayer->position.y, newPlayer->position.x);	
	return newPlayer;
}

Position* handleInput(int input, Player* user) {
	Position* newPosition;
	newPosition = malloc(sizeof(Position));
	
	switch(input) {
		case 'w': //up
		case 'W':
			newPosition->y = user->position.y - 1;
			newPosition->x = user->position.x;
			break;
		case 'd': //right
		case 'D':
			newPosition->y = user->position.y;
			newPosition->x = user->position.x + 1;
			break;
		case 's': //down
		case 'S':
			newPosition->y = user->position.y + 1;
			newPosition->x = user->position.x;
			break;
		case 'a': //left
		case 'A':
			newPosition->y = user->position.y;
			newPosition->x = user->position.x - 1;
			break;

		default:
			break;
	}
	return newPosition;
}

int checkPosition(Position* newPosition, Player* user, char** level) {
	int space;
	//mvinch checks what is at the next position (in terms of characters)
	switch(mvinch(newPosition->y, newPosition->x)) {
		case '.':
		case '#':
		case '+':
			movePlayer(newPosition, user, level);
			break;
		default:
			move(user->position.y, user->position.x);
			break;
	}
}


int movePlayer(Position* newPosition, Player* user, char** level) {
	
	//char buffer[8];

	//store last character walked over
	//level[user->position.y][user->position.x]

//error on the following line!
	mvaddch(user->position.y, user->position.x, level[user->position.y][user->position.x]);

	//print the most recent character stored in the buffer
	//mvprintw(user->position.y, user->position.x, buffer);

	//update player position to reflect the new coordinates
	user->position.y = newPosition->y;
	user->position.x = newPosition->x;
	
	mvprintw(user->position.y, user->position.x, "@");

	//reset the cursor to be over the player
	move(user->position.y, user->position.x);
	return 0;
}
