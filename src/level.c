#include "dungeon.h"

Room** mapSetup() {

Room** rooms; //array of rooms
rooms = malloc(sizeof(Room)*6);

	//create a room with the left corner at 13, 13, 6 tiles in height, and 8 tiles in length
	//store it in the first index of rooms.
	rooms[0] = createRoom(13, 13, 6, 8);
	drawRoom(rooms[0]);

	rooms[1] = createRoom(20, 2, 6, 8);
	drawRoom(rooms[1]);

	rooms[2] = createRoom(30, 9, 5, 12);
	drawRoom(rooms[2]);
	
	//Connect the doors of rooms together to create hallways
	connectDoors(rooms[0]->doors[1], rooms[1]->doors[0]);
	return rooms;
}

char** saveLevelPosition() {
//char array, levelPositions
	char** positions;
	positions = malloc(sizeof(char*)*25);
	int x, y;

	for(y = 0; y < 25; y++) {
		positions[y] = malloc(sizeof(char)*100);
		for(x = 0; x < 100; x++) {
			positions[y][x] = mvinch(y, x);
		}
	}
	//return the array of positions
	//memset(positions, positions[y][x], sizeof(char*)*25);
	return positions;
}
