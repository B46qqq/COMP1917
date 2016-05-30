/*This program is designed to sort 3 numbers, from lowest to highest. 
Start build date. 15/03/2016. 
Tony Bao(z5114676), Harris(z5110583) 

#Test 			input 				output
				5 6 7 				5
									6
									7
				50 10 12			50
									10
									12
				2 7 1				1
									2
									7					
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>									

#define TRUE 1
#define FALSE 0									

//The function Sorting is design to put
// 3 inputs into the right order (low to high)									
void Sorting (int Num1, int Num2, int Num3);
//
void IfEqual (int Num1, int Num2, int Num3);
//The Printing sub funtion will perform the display 
//of the 3 sorted numbers. 
void Printing (int Num1, int Num2, int Num3);

int main (int argc, char const *argv[]) {
	//-------------------Testing-------------------

//	printf("Please enter three numbers : ");
	int Num1, Num2, Num3;					//The first input will be assign to
	scanf ("%d %d %d", &Num1, &Num2, &Num3); //num1 and so on. 
	Sorting (Num1, Num2, Num3);				//after assigning,
	return 0;								//The Sorting function is call

}

void Sorting (int Num1, int Num2, int Num3) {
	//Note for sorting 3 numbers. There are only 6 cases to consider
	//
	if (Num1 <= Num2 && Num2 <= Num3 && Num1 <= Num3) {
		Printing (Num1, Num2, Num3);
	}else if (Num1 <= Num2 && Num2 >= Num3 && Num1 <= Num3) {

		Printing (Num1, Num3, Num2);
	}else if (Num1 <= Num2 && Num1 >= Num3 && Num2 >= Num3) {
		Printing (Num3, Num1, Num2);
	}else if (Num1 >= Num2 && Num2 <= Num3 && Num1 <= Num3)	{
		Printing (Num2, Num1, Num3);
	}else if (Num1 >= Num2 && Num1 > Num3 && Num2 > Num3) {
		Printing (Num3, Num2, Num1);
	}else if (Num1 > Num2 && Num1 > Num3 && Num2 < Num3) {
		Printing (Num2, Num3,Num1);
	}else{
		printf ("This logic is wrong\n");
	}
}

void Printing (int Num1, int Num2, int Num3) {
	printf ("%d\n%d\n%d\n", Num1, Num2, Num3);
}