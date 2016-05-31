//More testing to be done

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define IMAGESIZE 512

int testOfCounters (int x, int y, int z);
int imageProcess (double x, double y, int levels);
int numberCounter (void);

int main(int argc, char const *argv[])
{
	int overallCounter = 0;
	int a = 23;

	imageProcess (1, 1, 29);

	overallCounter = imageProcess (1, 1, 29);
	printf("It took %d loops\n", overallCounter);

	return 0;
}

int testOfCounters (int x, int y, int z){

	int xInital, yInital;
	int xFinal, yFinal;

	int xCounter, yCounter;
	int overallCounter = 0;

	//pre-defined IMAGESIZE is 512 ;;;

	//typed all un-nesscary codes, cause I was lazy so I did copy and paste
	//turned out the time to change ever value took more time 
	//shit

	xInital = 0;
	xFinal = x;

	yInital = 0;
	yFinal = y;

	xCounter = xInital;
	yCounter = yInital;

	int a = 0;

	while(yCounter < yFinal) {
		a = numberCounter();
	    xCounter += 1;
	    overallCounter += 1;
	    if (xCounter == xFinal)
	    {
	    	xCounter = xInital;
	    	yCounter += 1;
	    }
	}

	return a;
}

int numberCounter (void) {
	int anotherCounter = 0;
	anotherCounter += 1;

	return anotherCounter;
}

int imageProcess (double x, double y, int levels){

  double xInital, yInital;
  double xFinal, yFinal;

  double xCounter, yCounter;

  double zoomValue;

  int counter = 0;
  zoomValue = pow(2, -levels);
  //pre-defined IMAGESIZE is 512 ;;;
  xInital = x - (0.5 * IMAGESIZE * zoomValue);
  xFinal = x + (0.5 * IMAGESIZE * zoomValue);

  yInital = y - (0.5 * IMAGESIZE * zoomValue);
  yFinal = y + (0.5 * IMAGESIZE * zoomValue);

  xCounter = xInital;
  yCounter = yInital;

/*
  printf ("value of xInital is : %lf \n", xInital);
  printf ("value of xFinal is : %lf \n", xFinal);
  printf ("value of yInital is : %lf \n", yInital);
  printf ("value of yFinal is : %lf \n", yFinal);*/

  while(yCounter < yFinal) {
      //call escape function plug in xCounter and yCounter
      xCounter += zoomValue;
      counter += 1;
      
      if (xCounter == xFinal)
      {
         xCounter = xInital;
         yCounter += zoomValue;
      }
  }

  return counter;
}