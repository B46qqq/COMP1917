// Written by: Tony Bao (z), Corina Chen (z5118831), Daniel Luu (z5109922), Jason Wong (z5117248)
// A program which creates a Game (or several Games) and uses them to extensively test the Game ADT interface functions.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Game.h"


#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
        STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
        STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
        STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
        STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


//declare functions so main function knows they exists
void testGetDiscipline  (Game ptrGame, int *studentType);
void testDiceValue      (Game ptrGame, int *diceValue);
void testMostARC        (Game ptrGame);
void testMostPublication(Game ptrGame);
void testTurnNumber     (Game ptrGame);
void testWhoseTurn      (Game ptrGame);
void testGetCampus      (Game ptrGame);
void testGetARC         (Game ptrGame);


int main (int argc, char * argv[]) {
   
   int disciplineType[] = DEFAULT_DISCIPLINES;
   int CoDiceValue[] = DEFAULT_DICE;

   Game g = newGame (disciplineType, disciplineType);

   testGetDiscipline (g, disciplineType);
   testDiceValue (g, CoDiceValue);
   testGetCampus (g);
   testGetARC (g);
   printf ("All tests passed, you are Awesome!\n");

   return EXIT_SUCCESS;
}

void testGetDiscipline (Game ptrGame, int *studentType) { // testing with known values
// Using loops are really efficient then writing hundreds of asserts functions
   for (int i = 0; i < 19; i++) {
      assert (getDiscipline (ptrGame, i) == studentType[i]);
   }
}

void testDiceValue (Game ptrGame, int *diceValue) {
   for (int i = 0; i < 19; i++) {
      assert (getDiceValue (ptrGame, i) == diceValue[i]);
   }
}

void testGetCampus (Game ptrGame) {
   //can't automate this one :( 
   assert (getCampus (ptrGame, "")           == CAMPUS_A);
   assert (getCampus (ptrGame, "RLLLLL")     == CAMPUS_A);
   assert (getCampus (ptrGame, "LRRRRR")     == CAMPUS_A);
   assert (getCampus (ptrGame, "RRLRL")      == CAMPUS_B);
   assert (getCampus (ptrGame, "LRLRL")      == CAMPUS_C);
   assert (getCampus (ptrGame, "RLRLRLRLRLL")== CAMPUS_A);
   assert (getCampus (ptrGame, "RL")         == VACANT_VERTEX);
// assert (getCampus (ptrGame, pathfinder) == VALUE!!!!);
   //everyone, tries to add more later,
   //hopefully, come up with an algorithm. 
}

void testGetARC (Game ptrGame) {
   assert (getARC (ptrGame, "")        == ARC_A);
   assert (getARC (ptrGame, "R")       == VACANT_ARC);
   assert (getARC (ptrGame, "L")       == VACANT_ARC);
   assert (getARC (ptrGame, "LLLRRL")  == ARC_C);
}
