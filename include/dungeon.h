#ifndef DUNGEON_H
#define DUNGEON_H
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

//====================
// STRUCTS & TYPEDEFS
//====================

//just to make it easier to use position
typedef struct Position {
	int x; 
	int y;
} Position;

typedef struct Room {
//xPos and yPos of the room is top left corner
	Position position;
	int height; 
	int width;
	Position** doors;
	//pointer to arrays = **
	//Monster** monsters
	//Items** items
} Room;



typedef struct Player {
	Position position;
	int health;
	//Room* room; //which room player spawns in

} Player;


int screenSetup();

//===============
//LEVEL FUNCTIONS
//===============
Room** mapSetup();
char** saveLevelPosition();

//================
//PLAYER FUNCTIONS
//================

Position* handleInput(int input, Player* user);
int movePlayer(Position* newPosition, Player* user, char** level);
int checkPosition(Position* newPosition, Player* user, char** level);
Player* playerSetup();

//=============
//ROOM FUCTIONS
//=============

Room* createRoom(int y, int x, int height, int width);
int drawRoom(Room* room);
int connectDoors(const Position* doorOne, const Position* doorTwo);


#endif
