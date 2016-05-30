/* This program is designed to receive a valid input from the 
 * user, then it will display the wonderous series of the 
 * input. 
 */


#include <stdio.h>
#include <stdlib.h>

// This function will calculate and 
// display the wonderous series.
// one argument : the user input
int printWondrous (unsigned int start);


int main (int argc, char const *argv[]) {
    unsigned int start;
    int counter;
    scanf (" %d", &start); //Get the input from the user

    counter = printWondrous (start);
    printf ("The length is %d\n", counter);
    return 0;
}



int printWondrous (unsigned int start) {
	
    int counter = 1; // this counter is assigning the
                    // number of iteration

    if (start > 1){
    // This output is to display the first number in the
    // series, which is the input.        
        printf("%d ", start);
        while (start > 1){
            counter ++;
            if (start % 2 != 0) {
                    start = start * 3 + 1;
            }else {
                    start = start / 2;
            }
            printf ("%d ", start);
        }
    }else if (start == 1){
    // If the input is 1,
    // then there is only 1 iteration and 1 output;
    // which is the input 1 itself       
        printf ("\n");
    }

    return (counter);
}
