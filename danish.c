// This short program is designed to display the 
// great Danish flag in the terminal by a series of
// * and spaces. 


#include <stdio.h>


void showDanish(void);

int main(int argc, char const *argv[])
{
	showDanish();
	return 0;
}
/*
void showDanish(void){
	int i = 1, k = 3;

	while(i < 61 && i != 4){
		printf("%d", i);

		i++;
		k = i;
		while(k < 5) {
		    printf("O");
		    k++;
		}
	}
}*/


// There is a million ways to do this. 
// I wanted to make the loop more smarter, but due 
// to the restriction on the number of while statement
// we allowed to used. It really hard for me to think 
// of a proper way to acheive this.
	
void showDanish (void) {
	int i = 0;
	while (i < 5) {
	    printf ("** *********\n");
	    i ++;

	    while (i == 2) {
	        printf ("\n");
	        i ++;
	    }
	}
}

// Excepted output :: :: ::
/*

** *********
** *********

** *********
** *********

*/