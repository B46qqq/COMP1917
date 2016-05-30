/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by YOUR-NAME-HERE
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 //						for the COMP1917 Assignment 1; 
 //This program is designed to calculate the day in week 
 //from the 4 inputs. 	-- doomsday of the year
 //						-- Month and day
 //						-- Leapyear OR common year
 //First build day : 16/03/2016
 //By Tony Bao - 
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6
 
#define TRUE 1			// to Exclude magic numbers
#define FALSE 0			// by defining 1 and 0 by true and false

#define DAYS_PER_WEEK 7	//Days within a week. This will become extremely handly 
 						//for mod7 etc. And also meeting the style guide, 
 						//as this exclude magic number 7 
 

int dayOfWeek (int doomsday, int leapYear, int month, int day);
// dayOfWeek function is designed to call sub-funtion 'MainDivider' depend 
// on the value of the input month, as different parameter will be passed 
// into the MainDivider function. 

//parameters : doomsday, leapYear, month and day are essential inputs.

//  I believe the name MainDivider is more suitable 
// 			for the function dayOfWeek. 

int MainDivider (int doomsday, int day, int CommYearDoomsday, int LeapYearDoomsday, int leapYear);
// The function MainDivider is designed to call function ProcessDayofWeek
// depend on whether is the input a yearleap. Different parameter will be
// passed into the function ProcessDayofWeek / 

int ProcessDayofWeek(int inputday, int inputDoomsday, int doomsday);
// Function ProcessDayofWeek does the actual calculation which day is the input.
//  

int main (int argc, char *argv[]) {

	assert(dayOfWeek(SUNDAY,  FALSE,  1,  1) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  2) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  3) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  4) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  5) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  6) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  7) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  8) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  9) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  10) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  11) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  12) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  13) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  14) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  15) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  16) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  17) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  18) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  19) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  20) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  21) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  22) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  23) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  24) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  25) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  26) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  27) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  28) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  29) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  30) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  1,  31) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  1) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  2) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  3) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  4) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  5) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  6) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  7) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  8) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  9) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  10) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  11) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  12) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  13) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  14) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  15) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  16) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  17) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  18) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  19) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  20) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  21) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  22) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  23) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  24) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  25) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  26) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  27) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  2,  28) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  1) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  2) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  3) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  4) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  5) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  6) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  7) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  8) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  9) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  10) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  11) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  12) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  13) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  14) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  15) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  16) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  17) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  18) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  19) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  20) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  21) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  22) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  23) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  24) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  25) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  26) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  27) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  28) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  29) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  30) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  3,  31) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  1) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  2) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  3) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  4) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  5) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  6) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  7) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  8) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  9) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  10) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  11) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  12) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  13) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  14) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  15) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  16) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  17) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  18) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  19) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  20) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  21) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  22) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  23) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  24) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  25) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  26) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  27) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  28) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  29) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  4,  30) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  1) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  2) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  3) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  4) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  5) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  6) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  7) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  8) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  9) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  10) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  11) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  12) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  13) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  14) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  15) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  16) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  17) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  18) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  19) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  20) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  21) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  22) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  23) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  24) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  25) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  26) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  27) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  28) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  29) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  30) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  5,  31) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  1) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  2) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  3) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  4) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  5) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  6) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  7) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  8) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  9) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  10) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  11) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  12) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  13) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  14) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  15) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  16) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  17) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  18) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  19) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  20) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  21) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  22) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  23) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  24) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  25) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  26) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  27) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  28) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  29) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  6,  30) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  1) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  2) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  3) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  4) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  5) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  6) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  7) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  8) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  9) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  10) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  11) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  12) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  13) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  14) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  15) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  16) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  17) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  18) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  19) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  20) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  21) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  22) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  23) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  24) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  25) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  26) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  27) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  28) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  29) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  30) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  7,  31) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  1) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  2) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  3) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  4) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  5) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  6) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  7) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  8) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  9) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  10) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  11) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  12) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  13) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  14) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  15) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  16) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  17) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  18) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  19) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  20) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  21) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  22) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  23) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  24) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  25) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  26) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  27) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  28) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  29) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  30) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  8,  31) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  1) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  2) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  3) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  4) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  5) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  6) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  7) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  8) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  9) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  10) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  11) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  12) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  13) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  14) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  15) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  16) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  17) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  18) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  19) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  20) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  21) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  22) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  23) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  24) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  25) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  26) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  27) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  28) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  29) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  9,  30) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  1) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  2) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  3) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  4) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  5) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  6) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  7) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  8) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  9) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  10) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  11) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  12) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  13) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  14) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  15) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  16) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  17) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  18) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  19) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  20) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  21) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  22) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  23) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  24) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  25) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  26) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  27) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  28) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  29) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  30) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  10,  31) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  1) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  2) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  3) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  4) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  5) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  6) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  7) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  8) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  9) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  10) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  11) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  12) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  13) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  14) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  15) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  16) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  17) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  18) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  19) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  20) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  21) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  22) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  23) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  24) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  25) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  26) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  27) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  28) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  29) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  11,  30) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  1) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  2) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  3) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  4) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  5) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  6) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  7) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  8) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  9) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  10) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  11) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  12) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  13) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  14) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  15) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  16) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  17) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  18) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  19) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  20) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  21) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  22) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  23) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  24) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  25) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  26) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  27) == MONDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  28) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  29) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  30) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  FALSE,  12,  31) == FRIDAY);

	//Leap Year: TRUE

	assert(dayOfWeek(SUNDAY,  TRUE,  1,  1) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  2) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  3) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  4) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  5) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  6) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  7) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  8) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  9) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  10) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  11) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  12) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  13) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  14) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  15) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  16) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  17) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  18) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  19) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  20) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  21) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  22) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  23) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  24) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  25) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  26) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  27) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  28) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  29) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  30) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  1,  31) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  1) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  2) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  3) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  4) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  5) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  6) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  7) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  8) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  9) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  10) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  11) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  12) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  13) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  14) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  15) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  16) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  17) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  18) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  19) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  20) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  21) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  22) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  23) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  24) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  25) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  26) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  27) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  28) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  2,  29) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  1) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  2) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  3) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  4) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  5) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  6) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  7) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  8) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  9) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  10) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  11) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  12) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  13) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  14) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  15) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  16) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  17) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  18) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  19) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  20) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  21) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  22) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  23) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  24) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  25) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  26) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  27) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  28) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  29) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  30) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  3,  31) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  1) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  2) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  3) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  4) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  5) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  6) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  7) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  8) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  9) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  10) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  11) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  12) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  13) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  14) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  15) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  16) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  17) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  18) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  19) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  20) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  21) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  22) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  23) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  24) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  25) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  26) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  27) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  28) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  29) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  4,  30) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  1) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  2) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  3) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  4) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  5) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  6) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  7) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  8) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  9) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  10) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  11) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  12) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  13) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  14) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  15) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  16) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  17) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  18) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  19) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  20) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  21) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  22) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  23) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  24) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  25) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  26) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  27) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  28) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  29) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  30) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  5,  31) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  1) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  2) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  3) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  4) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  5) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  6) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  7) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  8) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  9) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  10) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  11) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  12) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  13) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  14) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  15) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  16) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  17) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  18) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  19) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  20) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  21) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  22) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  23) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  24) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  25) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  26) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  27) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  28) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  29) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  6,  30) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  1) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  2) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  3) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  4) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  5) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  6) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  7) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  8) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  9) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  10) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  11) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  12) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  13) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  14) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  15) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  16) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  17) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  18) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  19) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  20) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  21) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  22) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  23) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  24) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  25) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  26) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  27) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  28) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  29) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  30) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  7,  31) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  1) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  2) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  3) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  4) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  5) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  6) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  7) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  8) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  9) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  10) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  11) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  12) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  13) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  14) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  15) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  16) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  17) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  18) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  19) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  20) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  21) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  22) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  23) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  24) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  25) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  26) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  27) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  28) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  29) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  30) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  8,  31) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  1) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  2) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  3) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  4) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  5) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  6) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  7) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  8) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  9) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  10) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  11) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  12) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  13) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  14) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  15) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  16) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  17) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  18) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  19) == SUNDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  20) == MONDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  21) == TUESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  22) == WEDNESDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  23) == THURSDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  24) == FRIDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  25) == SATURDAY);
	assert(dayOfWeek(SUNDAY,  TRUE,  9,  26) == SUNDAY);


	printf ("all tests passed - You are awesome!\n");
	return EXIT_SUCCESS;
}

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;
 
   // INSERT YOUR CODE HERE
 // int DATE=month*100+day, DayDIFF=0, DayMORE=0;
   if (month == 1)
   {		//Since the doomsday in Jan is 3 or 4 for leapyear
		dayOfWeek = MainDivider(doomsday, day,  3,  4, leapYear);	
   }else if (month == 2)
   {		//Since the doomsday in Fre is 28 or 29 for leapyear
		dayOfWeek = MainDivider(doomsday, day, 28, 29, leapYear);
   }else if (month ==3)
   {		//The doomsdays after Fre will NOT vary depend on 
   			// the leapyear.
		dayOfWeek = MainDivider(doomsday, day,  0,  0, leapYear);
   }else if (month == 4)
   {
		dayOfWeek = MainDivider(doomsday, day,  4,  4, leapYear);
   }else if (month == 5)
   {
		dayOfWeek = MainDivider(doomsday, day,  9,  9, leapYear);
   }else if (month == 6)
   {
		dayOfWeek = MainDivider(doomsday, day,  6,  6, leapYear);
   }else if (month == 7)
   {
		dayOfWeek = MainDivider(doomsday, day, 11, 11, leapYear);
   }else if (month == 8)
   {
		dayOfWeek = MainDivider(doomsday, day,  8,  8, leapYear);
   }else if (month == 9)
   {
		dayOfWeek = MainDivider(doomsday, day,  5,  5, leapYear);
   }else if (month == 10)
   {
		dayOfWeek = MainDivider(doomsday, day, 10, 10, leapYear);
   }else if (month == 11)
   {
		dayOfWeek = MainDivider(doomsday, day,  7,  7, leapYear);
   }else
   {
		dayOfWeek = MainDivider(doomsday, day, 12, 12, leapYear);
	}
 
   return dayOfWeek;
}

int MainDivider (int doomsday, int inputday, int CommYearDoomsday, int LeapYearDoomsday, int leapYear){
	int dayOfWeek;

	if (leapYear == TRUE)	//If the input is a leapyear.
	{						//Then in the parameter, doomsday for
							//leapyears will be passed in
		dayOfWeek = ProcessDayofWeek(inputday, LeapYearDoomsday, doomsday);
	}else
	{						//Similar for non-leapyear inputs.
		dayOfWeek = ProcessDayofWeek(inputday, CommYearDoomsday, doomsday);
	}
	return (dayOfWeek);
}

int ProcessDayofWeek(int inputday, int inputDoomsday, int doomsday){
	int dayOfWeek;

	//The calculation here is straight forward. 

	if (inputday > inputDoomsday)
	{
		dayOfWeek = (doomsday + (inputday - inputDoomsday))%DAYS_PER_WEEK;

	}else if (inputday < inputDoomsday)
	{
		dayOfWeek = (((inputday - inputDoomsday)% DAYS_PER_WEEK) +DAYS_PER_WEEK) +doomsday;
		if (dayOfWeek >= DAYS_PER_WEEK)
		{
			dayOfWeek = dayOfWeek - DAYS_PER_WEEK;
		}
	}else
	{
		dayOfWeek = doomsday;
	}

	return (dayOfWeek);
}



