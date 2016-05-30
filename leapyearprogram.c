/* This program is designed to calc if the year entered
 * by the user is a leap year or not.
 * 06/03/2016
 * Tony , b46qqq
 */

#include <stdio.h>
#include <stdlib.h>

#define MINLEAPYEAR 1582

int main(int argc, char const *argv[])
{
	int enteredYear;
	
	printf ("Please enter a year needs to be calc :");
	scanf ("%d", &enteredYear);

	// This statement is to ensure the input is always greater than 1582
	// because this is no calender before this date.
	while(enteredYear < MINLEAPYEAR){
		printf ("Please enter a year greater than year 1582 :");
		scanf ("%d", &enteredYear);
	}

	if ((enteredYear%4 == 0 && enteredYear%100 != 0) || (enteredYear%400 == 0)){
		printf ("Year %d is a leap year.\n", enteredYear);

	}else if (enteredYear%4 != 0) {
		printf ("Year %d is not a leap year\n", enteredYear);
		printf ("As it is not divisible by 4\n");

	}else if (enteredYear%4 == 0 && enteredYear%100 == 0 && enteredYear != 0){
		printf ("Year %d is not a leap year\n", enteredYear);
		printf ("Because it is divisible by 100, but not 400\n");
	}else {
		printf ("ERROR\n");
	}
	return 0;
}