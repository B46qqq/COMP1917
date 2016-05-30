/* This short program is designed to reverse a string of various length
 * This is acheived by allocate an extra space in memory
 * and copy the last character to the first place in the new
 * allocated place. 
 */

// Also since the testBot only test for function
// No need to create a main function. 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse (char *message);

int main(int argc, char const *argv[])
{

	return 0;
}

char *reverse (char *message){

	int counter = 0;
	int strLength = strlen (message);
	int yaCounter = strLength-1;
	char *value;
	value = (char *)malloc (strLength+1);

	while (counter < strLength) {
		value[counter] = message[yaCounter];
		counter ++;
		yaCounter --;
	}
	value[strLength] = '\0';
	return value;
}