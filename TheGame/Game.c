#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Game.h"

//=========Some predefined values=================
#define X 1
#define Y 2
#define Z 3

#define MAPVERTEXCOLIF 	{3, 5, 7}
#define MAPVERTEXCOL12 	{2, 4, 6, 8}
#define MAPVERTEXCOL34 	{1, 3, 5, 7, 9}
#define MAPVERTEXCOL56 	{0, 2, 4, 6, 8, 10}

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

#define MAPEDGE_ROW 	{Y,X,Z,X,Y,X,Z,X,Y,X,Z,X,Y}
//================================================

struct _playerData {
	int kpiPoint;
	int arcGrant;
	int go8Campus;
	int normalCampus;
	int ipPatents;
	int publication;
	int disciplineStudent[6];
};

struct _gameData {
	int regionStudentType[19];
	int corresRegionValue[19];
	int theBetterPlayer;
	int topARCPlayer;
	int topPubliPlayer;
	int globalTurnCounter;
	int localPlayerTurn;
//	int mapping...
	int vertexMap[12][11];
	int edgeMap[11][10];
};

typedef struct _game {
	struct _gameData gameData;
	struct _playerData playerData[3];
	char optimisedPath[PATH_LIMIT];
} game;

typedef struct _mapData {
	int mapVertexColumn[11];
	int mapEdgeRow[13];
} mapData;

static void initialiseMap (Game gameStats);
static void showMap (Game gameStats);
//static void optimisedPath (Game gameStats, path pathfinder);


int main(int argc, char const **argv)
{
	game * gameStats = (game *) malloc (sizeof (game));

	Game ptrTest = (Game) malloc (sizeof (Game));

	gameStats->gameData.globalTurnCounter = 1;
	char array[PATH_LIMIT];

	fgets (array, sizeof (array), stdin);

	int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    newGame (disciplines, dice);
	ptrTest = newGame (disciplines, dice);
	printf("=================================\n");
	printf("%d\n", ptrTest->gameData.regionStudentType[1]);

	if (gameStats->gameData.globalTurnCounter != -1){
		//Only start the game iff the globalTurnCounter is not -1 or 0;;;

		//initialiseMap (gameStats);
		//showMap (gameStats);
		//getARC (gameStats, array);
		for (int i = 0; i < 19; i++) {
			printf ("%d with dice value %d\n", ptrTest->gameData.regionStudentType[i],
											ptrTest->gameData.corresRegionValue[i]);
		}

	//	printf("%s\n", gameStats->optimisedPath);
	}

	free (gameStats);
	gameStats = NULL;
	return 0;
}

Game newGame (int discipline[], int dice[]) {
	struct _game *ptrOutput = (struct _game *)malloc (sizeof (struct _game));

	for (int i = 0; i < 19; i++) {
		ptrOutput->gameData.regionStudentType[i] = discipline[i];
	}
	for (int i = 0; i < 19; i++) {

		ptrOutput->gameData.corresRegionValue[i] = dice[i];
	}
	return ptrOutput;
}
void disposeGame (Game gameStats) {
	free (gameStats);
	gameStats = NULL;
}

int getDiscipline (Game gameStats, int regionID) {

	//newGame (gameStats->gameData.regionStudentType, gameStats->gameData.corresRegionValue);
	//disposeGame (gameStats);
	return (gameStats->gameData.regionStudentType[regionID]);
}

int getDiceValue (Game gameStats, int regionID) {
	return (gameStats->gameData.corresRegionValue[regionID]);
}


int getMostARCs (Game gameStats);

int getMostPublications (Game gameStats) {
	return (gameStats->gameData.topPubliPlayer);
}

int getTurnNumber (Game gameStats);

int getWhoseTurn (Game gameStats);

int getCampus (Game gameStats, path pathfinder){

	int counter = 0;
	int currentDir = Z;
	int column = 5, row = 0;
	while (counter < (strlen (pathfinder)-1)) {
		if (pathfinder[counter] == 'R' || pathfinder[counter] == 'L'||
						pathfinder[counter] == 'B'){
			if (pathfinder[counter] == 'R') {
				if (currentDir == Z){
					column --; row ++;
					currentDir = -Y;
				}else if (currentDir == -Z) {
					column ++; row --;
					currentDir = Y;
				}else if (currentDir == Y) {
					column ++; 
					currentDir = X;
				}else if (currentDir == -Y) {
					column --;
					currentDir = -X;
				}else if (currentDir == X) {
					column ++; row ++;
					currentDir = Z;
				}else if (currentDir == -X) {
					column --; row --;
					currentDir = -Z;
				}
			}else if (pathfinder[counter] == 'L') {
				if (currentDir == X) {
					column ++; row --;
					currentDir = Y;
				}else if (currentDir == -X) {
					column --; row ++;
					currentDir = -Y;
				}else if (currentDir == Y) {
					column --; row --;
					currentDir = -Z;
				}else if (currentDir == -Y) {
					column ++; row ++;
					currentDir = Z;
				}else if (currentDir == Z) {
					column ++;
					currentDir = X;
				}else if (currentDir == -Z) {
					column --;
					currentDir = -X;
				}
			}else if (pathfinder[counter] == 'B') {
				if (currentDir == X){
					column --;
				}else if (currentDir == -X) {
					column ++;
				}else if (currentDir == Y) {
					column --; row ++;
				}else if (currentDir == -Y) {
					column ++; row --;
				}else if (currentDir == Z) {
					column --; row --;
				}else if (currentDir == -Z) {
					column ++; row ++;
				}
				currentDir = -currentDir;
			}
			counter ++;
		}
	}
	return (gameStats->gameData.vertexMap[column][row]);
}

int getARC (Game gameStats, path pathfinder) {

	int counter = 0;
	int currentDir = Z;
	int column = 0, row = 0;

	while (counter < (strlen (pathfinder) - 1)){

		if (pathfinder[counter] == 'R' || pathfinder[counter] == 'L' ||
						pathfinder[counter] == 'B'){

			if (counter == 0){
				if (pathfinder[counter] == 'R'){
					column = 4; row = 0;
					currentDir = -Y;
				}else if (pathfinder[counter] == 'L'){
					column = 5, row = 0;
					currentDir = X;
				}else if (pathfinder[counter] == 'B'){
					//printf("This action is illegal\n");
				}
				counter ++;
			}else if (pathfinder[counter] == 'R'){

				if (currentDir == X){
					column ++;
					currentDir = Z;
				}else if (currentDir == -X){
					column --;
					currentDir = -Z;
				}else if (currentDir == Y){
					column ++;
					currentDir = X;
				}
				 else if (currentDir == -Y){
					 column --;
					 currentDir = -X; 
				}else if (currentDir == Z){
					 row ++;
					 currentDir = -Y;
				}else if (currentDir == -Z){
					 row --;
					 currentDir = Y;
				}
				counter ++;
			}else if (pathfinder[counter] == 'L'){
				
				if (currentDir == X){
					column ++;
					currentDir = Y;
				}else if (currentDir == -X){
					column --;
					currentDir = -Y;
				}else if (currentDir == Y){
					row --;
					currentDir = -Z;
				}else if (currentDir == -Y){
					row ++;
					currentDir = Z;
				}else if (currentDir == Z){
					column ++;
					row ++;
					currentDir = X;
				}else if (currentDir == -Z){
					column --;
					currentDir = -X;
				}
				counter ++;
			}else if (pathfinder[counter] == 'B'){

				if (currentDir > 0){
					currentDir = -currentDir;
				}else if (currentDir < 0){
					currentDir = -currentDir;
				}
				counter ++;
			}

		}

	}
		
	return gameStats->gameData.edgeMap[column][row];
}

int getKPIpoints (Game gameStats, int player){
	int compare[3];
	int i = 0;
	int max;
	while (i < 3){
		compare[i] = gameStats->playerData[player+i].kpiPoint;
		i ++;
	}
	i = 0;
	while (i < 2){
		if (compare[i] < compare[i+1]){
			max = compare[i+1];
		}else if (compare [i] > compare[i+1]){
			max = compare[i];
		}else {
			printf("PASS\n");
		}
	}

	gameStats->gameData.theBetterPlayer = max;

	return (gameStats->playerData[player].kpiPoint);
}

int getARCs (Game gameStats, int player){
	return (gameStats->playerData[player].arcGrant);
}

int getGO8s (Game gameStats, int player){
	return (gameStats->playerData[player].go8Campus);
}

int getCampuses (Game gameStats, int player){
	return (gameStats->playerData[player].normalCampus);
}

int getIPs (Game gameStats, int player){
	return (gameStats->playerData[player].ipPatents);
}

int getPublication (Game gameStats, int player){
	return (gameStats->playerData[player].publication);
}

int getStudents (Game gameStats, int player, int discipline);

int getExchangeRate (Game gameStats, int player,
					int disciplineFrom, int disciplineTo);

static void initialiseMap (Game gameStats){

	int vertexColif[] = MAPVERTEXCOLIF;
	int vertexCol12[] = MAPVERTEXCOL12;
	int vertexCol34[] = MAPVERTEXCOL34;
	int vertexcol56[] = MAPVERTEXCOL56;

	int defaultEdgeValue[] = MAPEDGE_ROW;

	//mapping for edges
	int row = 0;
	int column = 0;
	while(row < 10) {
		if ((row == 0 && column == 4) || (row == 0 && column == 5) 
					|| (row == 0 && column == 6)){
			gameStats->gameData.edgeMap[column][row] = defaultEdgeValue[column];
		} else if ((row == 9 && column == 4) || (row == 9 && column == 5) 
					|| (row == 9 && column == 6)){

			gameStats->gameData.edgeMap[column][row] = defaultEdgeValue[column];
		} else if ((row == 2) || (row == 4) || (row == 6)){
			while(column < 11) {
				gameStats->gameData.edgeMap[column][row] = defaultEdgeValue[column];
				column ++;
			}
		} else if ((row == 3) || (row == 5) || (row == 7)){
			while(column < 13) {
				gameStats->gameData.edgeMap[column][row] = defaultEdgeValue[column+2];
				column ++;
			}
		} else if (row == 1){
			while(column < 7) {
				gameStats->gameData.edgeMap[column+2][row] = defaultEdgeValue[column];
				column ++;
			}
		} else if (row == 8){
			while(column < 7) {
				gameStats->gameData.edgeMap[column+2][row] = defaultEdgeValue[column+2];
				column ++;
			}
		}
		column ++;
		if (column >= 10){
			column = 0;
			row ++;
		}
	}
	// mapping for vertex. 
	column = 0;
	row = 0;
	while (column < 12){
		if ((column == 0) || (column == 11)){
			for (int i = 0; i < 3; i++){
				gameStats->gameData.vertexMap[column][vertexColif[i]] = '*';
			}
		}else if ((column == 1) || (column == 2) || (column == 9) || (column == 10)){
			for (int i = 0; i < 4; i++){
				gameStats->gameData.vertexMap[column][vertexCol12[i]] = '*';
			}
		}else if ((column == 3) || (column == 4) || (column == 7) || (column == 8)){
			for (int i = 0; i < 5; i++)
			{
				gameStats->gameData.vertexMap[column][vertexCol34[i]] = '*';
			}
		}else if ((column == 5) || (column == 6)){
			for (int i = 0; i < 6; i++){
				gameStats->gameData.vertexMap[column][vertexcol56[i]] = '*';
			}
		}
		column ++;
	}
	gameStats->gameData.vertexMap[0][3] = CAMPUS_B;
	gameStats->gameData.vertexMap[11][7] = CAMPUS_B;
	gameStats->gameData.vertexMap[5][0] = CAMPUS_A;
	gameStats->gameData.vertexMap[6][10] = CAMPUS_A;
	gameStats->gameData.vertexMap[1][8] = CAMPUS_C;
	gameStats->gameData.vertexMap[10][2] = CAMPUS_C;
}

static void showMap (Game gameStats){
	int column = 0, row = 0;
	while (row < 11){
		while (column < 12){
			if (gameStats->gameData.vertexMap[column][row] == '\0'){
				gameStats->gameData.vertexMap[column][row] = ' ';
			}

			if (gameStats->gameData.vertexMap[column][row] == 1 ||
				gameStats->gameData.vertexMap[column][row] == 2 ||
				gameStats->gameData.vertexMap[column][row] == 3){
				printf(" %d ", gameStats->gameData.vertexMap[column][row]);
			}else {
				printf(" %c ", gameStats->gameData.vertexMap[column][row]);
			}
		//	printf (" %c ", gameStats->gameData.vertexMap[column][row]);
			if (column == 11){
				printf("\n");
			}
			column ++;
		}
		column = 0;
		row ++;
	}

	column = 0; row = 0;
	while (row < 10){
		while (column < 11){
			if (gameStats->gameData.edgeMap[column][row] == '\0'){
				gameStats->gameData.edgeMap[column][row] = ' ';
			}

			if (gameStats->gameData.edgeMap[column][row] == 1){
				printf(" X ");
			}else if (gameStats->gameData.edgeMap[column][row] == 2){
				printf(" Y ");
			}else if (gameStats->gameData.edgeMap[column][row] == 3){
				printf(" Z ");
			}else {
				printf(" %c ", gameStats->gameData.edgeMap[column][row]);
			}

			if (column == 10){
				printf("\n");
			}
			column ++;
		}
		column = 0;
		row ++;
	}
}
/*
static void optimisedPath (Game gameStats, path pathfinder){
	
	int totalChar = strlen (pathfinder);

	int counter = 0;
	int backCounter = 0;
	int RLcounter = 0; 
	int yABcounter = 0;

	int spottingBack[totalChar];

	char *copyPath = pathfinder;
	
	//This is only for testing;;;
	//printf("%s\n", copyPath);

	while (counter <= totalChar){
		if (pathfinder[counter] == 'B'){
			spottingBack[backCounter] = counter;
			backCounter ++;
		}else if (pathfinder[counter] == 'R' || pathfinder[counter] == 'L'){
			RLcounter ++;
		}
		counter ++;
	}

	if (backCounter > RLcounter){
		printf("error \n");
	}else if (backCounter == RLcounter){
		printf("back to original place\n");
	}else if (backCounter < RLcounter){
		while (yABcounter < backCounter){
			if (copyPath[yABcounter] != 'B'){
				yABcounter ++;
			}else if (pathfinder[yABcounter] == 'B'){
				copyPath[yABcounter-1] = '\0';
				copyPath[yABcounter] = '\0';
				yABcounter ++;			
			}
		}
	}
	counter = 0;
	while (counter < totalChar){
		if (copyPath[counter] != '\0')
		{
			gameStats->optimisedPath[counter] = copyPath[counter];
			counter ++;
		}
		counter ++;
	}
}
*/
