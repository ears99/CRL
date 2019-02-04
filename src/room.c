#include "dungeon.h"

Room* createRoom(int y, int x, int height, int width) {
	Room* newRoom;
	newRoom = malloc(sizeof(Room));

	newRoom->position.y = y;
	newRoom->position.x = x;
	newRoom->height = height;
	newRoom->width = width;

	//add doors
	
	
	newRoom->doors = malloc(sizeof(Position)*4);



	//door is an array of positions (on rooms, count counterclockwise starting from the top door.)

	//top door
	newRoom->doors[0] = malloc(sizeof(Position));
	newRoom->doors[0]->x = rand() % (width - 2) + newRoom->position.x + 1;
	newRoom->doors[0]->y = newRoom->position.y;

	//left door
	newRoom->doors[1] = malloc(sizeof(Position));
	newRoom->doors[1]->y = rand() % (height - 2) + newRoom->position.y + 1;
	newRoom->doors[1]->x = newRoom->position.x;

	//bottom door
	newRoom->doors[2] = malloc(sizeof(Position));
	newRoom->doors[2]->x = rand() % (width - 2) + newRoom->position.x + 1;
	newRoom->doors[2]->y = newRoom->position.y + newRoom->height;

	//right door
	newRoom->doors[3] = malloc(sizeof(Position));
	newRoom->doors[3]->y = rand() % (height - 2) + newRoom->position.y + 1;
	newRoom->doors[3]->x = newRoom->position.x + width - 1;

	return newRoom;

}


int drawRoom(Room* room) {
	int x; 
	int y;
	
	//draw top and bottom
	for(x = room->position.x; x < room->position.x + room->width; x++) {
		mvprintw(room->position.y, x, "-"); //top
		mvprintw(room->position.y + room->height, x, "-"); //bottom
	}

	//draw floors and side walls
	for(y = room->position.y + 1; y < room->position.y + room->height; y++) {
		//draw side walls
		mvprintw(y, room->position.x, "|");
		mvprintw(y, room->position.x + room->width - 1, "|");
		
		//draw floor
		for(x = room->position.x + 1; x < room->position.x + room->width - 1; x++) {
			mvprintw(y, x, ".");
		}
	}

	//draw doors
	mvprintw(room->doors[0]->y, room->doors[0]->x, "+");
	mvprintw(room->doors[1]->y, room->doors[1]->x, "+");
	mvprintw(room->doors[2]->y, room->doors[2]->x, "+");
	mvprintw(room->doors[3]->y, room->doors[3]->x, "+");

	return 0;
}


int connectDoors(const Position* doorOne, const Position* doorTwo) {

/*
ALGORITHIM STEPS:
1. STARTING AT THE DOOR TILE, TAKE A STEP RANDOMLY IN ONE DIRECTION.
2. IS THAT CLOSER TO THE DESTINATION DOOR?
	IF YES, IS THAT SPACE EMPTY?
	IF BOTH ARE YES, MOVE ON TO NEXT STEP.
3. DRAW HALLWAY ('#').
*/
	Position temp;
	
	temp.x = doorOne->x;
	temp.y = doorOne->y;
	
	while(1) {
	//step left
	//if we step left, does that bring us closer to the destination? further away? no change?
		if((abs((temp.x - 1) - doorTwo->x) < abs(temp.x - doorTwo->x)) && (mvinch(temp.y, temp.x - 1) == ' ')) {
			mvprintw(temp.y, temp.x - 1, "#");
			temp.x = temp.x - 1;
		}
		//step right
		else if((abs((temp.x + 1) - doorTwo->x) < abs(temp.x - doorTwo->x)) && (mvinch(temp.y, temp.x + 1) == ' ')) {
			mvprintw(temp.y, temp.x + 1, "#");
			temp.x = temp.x + 1;
		}
		
		//step down
		else if((abs((temp.y + 1) - doorTwo->y) < abs(temp.y - doorTwo->y)) && (mvinch(temp.y + 1, temp.x) == ' ')) {
			mvprintw(temp.y + 1, temp.x, "#");
			temp.y = temp.y + 1;
		}
		
		//step up
		else if((abs((temp.y - 1) - doorTwo->y) < abs(temp.y - doorTwo->y)) && (mvinch(temp.y - 1, temp.x) == ' ')) {
			mvprintw(temp.y - 1, temp.x, "#");
			temp.y = temp.y - 1;
		} else {
		//can't pathfind to current destination
			return 1;
		}
	//getch(); //see it draw each path.
	}	
	 
	return 0;
}	
