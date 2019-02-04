#include "dungeon.h"

int main() {
	Player* user;
	int ch;
	char** level;
	Position* newPosition;
	screenSetup();
	mapSetup();
	level = saveLevelPosition();
	user = playerSetup();

	//TEST
	mvprintw(0,0,"The character at 13, 13 is: %c", level[13][13]);

	//gameloop
	while((ch = getch()) != 'q') {
		newPosition = handleInput(ch, user);
		checkPosition(newPosition, user, level);		
	}

	endwin();
	return 0;
}


int screenSetup() {
	initscr();
	//printw("Dungeon Alpha 0.1");
	noecho();
	refresh();
	srand(time(NULL));
	
	return 0;
}



