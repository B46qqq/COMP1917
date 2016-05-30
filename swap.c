/* 
	this program is designed to 'swap' two input integers.

	Program i date; 20/03/2016

	By; Tony Bao
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0


//As the name suggest, this function gets two integers from the user
//Since we passed in two references. The input values will be stored
//in the two agrument addresses
void getInput (int *first, int *second);

//This function swaps two input values
void swap (int *first, int *second);

//Test ... 
int testCases (int first, int second);



int main (int argc, char const *argv[]) {

	int i = 0;
	// A loop for testing. Don't need hard coding. 
	while (i < 100) {
	
	    i ++;
	    int ranNumber1 = rand(), ranNumber2 = rand();

	    assert (testCases(ranNumber1, ranNumber2));
	    printf ("pass\n");
	}
	int first, second;
	getInput (&first, &second);
	swap (&first, &second);
	printf ("%d, %d \n", first, second);
	return 0;
}

void getInput (int *first, int *second) {

	printf ("Enter the first real number:");
	scanf (" %d", first);
	printf ("Enter the second real number;");
	scanf (" %d", second);
}

void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}


int testCases (int first, int second) {

	int value1 = first;
	int value2 = second;
	int statement;

	swap (&first, &second);

	statement = (value1 == second) && (value2 == first);

	printf ("%d\n", statement);
	return (statement);
}