/*
 *  pixelColor.h
 *  mandelbrot colors
 *
 *  Created by Richard Buckland on 13/04/11.
 *  Licensed under Creative Commons SA-BY-NC 3.0.  
 *
 */
/*
int statement (int steps){
	unsigned char returnValue;
	if (steps == 256)
	{
	returnValue = 0;
	}else{
	returnValue = 255;
	}
	return returnValue;
}*/

	
//#include "pixelColor.h"

unsigned char stepsToRed (int *steps){
	if (*steps == 0 || *steps == 256){
		*steps = 0;
	}else{
		*steps = (*steps/5) + 153;
	}
	return *steps;
}

unsigned char stepsToBlue (int *steps){
	if (*steps == 0 || *steps == 256){
		*steps = 0;
	}else{
		*steps = 255 - ((*steps*3)/5);
	}
	return *steps;
}

unsigned char stepsToGreen (int *steps){
	if (*steps == 0 || *steps == 256){
		*steps = 0;
	}else{
		*steps = (*steps/5) + 204;
	}
	return *steps;
}
