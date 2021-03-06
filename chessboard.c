/*
 *  chessboard.c
 *  create a 512x512 BMP of a chessboard, with user specified size (in pixels)
 *  of the black and white squares on the board.  bottom right square must be white.
 *
 *  Created by Richard Buckland on 14/04/11, edited 5/4/14
 *  Licensed under Creative Commons BY 3.0.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
 
#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0
 
#define SIZE 512
#define BMP_FILE "chess.bmp"
 
typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;
 
void writeHeader (FILE *file);
 
int main (int argc, char *argv[]) {
 
   // check that the types have the size i'm relying on here
   assert (sizeof(bits8)  == 1);
   assert (sizeof(bits16) == 2);
   assert (sizeof(bits32) == 4);
   
   FILE *outputFile;
   int input;
 
   outputFile = fopen(BMP_FILE, "wb");
   assert ((outputFile!=NULL) && "Cannot open file");
 
   writeHeader(outputFile);
 
   printf ("Enter square size (must be a factor of %d): \n", SIZE);
   scanf ("%d", &input);

   assert (SIZE % input == 0);

   bits8 RGB = 0;
   bits8 white = 255;
   bits8 black = 0;

   RGB = black;

   int k = 0;  //for 'k' is a overall counter to the loop
   int totalPixel = (SIZE * SIZE * BYTES_PER_PIXEL);

   while (k < totalPixel) {

       while (k % (input *BYTES_PER_PIXEL != 0) && (k != 0)) {
           fwrite (&RGB, sizeof RGB, 1, outputFile);
           k++;
       }
       if (k %(input * BYTES_PER_PIXEL) == 0 && k != 0) {
          if (k % (BYTES_PER_PIXEL * SIZE * input) == 0) {
            //printf("did nothing\n");
          }
          else if (RGB == white) RGB = black;
          else if (RGB == black) RGB = white;
       }
       if (k < totalPixel) {
         fwrite (&RGB , sizeof RGB, 1, outputFile);
         k ++;
       }
   }
   fclose (outputFile);
   return EXIT_SUCCESS;
}
 
void writeHeader (FILE *file) {
   assert(sizeof (bits8) == 1);
   assert(sizeof (bits16) == 2);
   assert(sizeof (bits32) == 4);
 
   bits16 magicNumber = MAGIC_NUMBER;
   fwrite (&magicNumber, sizeof magicNumber, 1, file);
 
   bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&fileSize, sizeof fileSize, 1, file);
 
   bits32 reserved = 0;
   fwrite (&reserved, sizeof reserved, 1, file);
 
   bits32 offset = OFFSET;
   fwrite (&offset, sizeof offset, 1, file);
 
   bits32 dibHeaderSize = DIB_HEADER_SIZE;
   fwrite (&dibHeaderSize, sizeof dibHeaderSize, 1, file);
 
   bits32 width = SIZE;
   fwrite (&width, sizeof width, 1, file);
 
   bits32 height = SIZE;
   fwrite (&height, sizeof height, 1, file);
 
   bits16 planes = NUMBER_PLANES;
   fwrite (&planes, sizeof planes, 1, file);
 
   bits16 bitsPerPixel = BITS_PER_PIXEL;
   fwrite (&bitsPerPixel, sizeof bitsPerPixel, 1, file);
 
   bits32 compression = NO_COMPRESSION;
   fwrite (&compression, sizeof compression, 1, file);
 
   bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&imageSize, sizeof imageSize, 1, file);
 
   bits32 hResolution = PIX_PER_METRE;
   fwrite (&hResolution, sizeof hResolution, 1, file);
 
   bits32 vResolution = PIX_PER_METRE;
   fwrite (&vResolution, sizeof vResolution, 1, file);
 
   bits32 numColors = NUM_COLORS;
   fwrite (&numColors, sizeof numColors, 1, file);
 
   bits32 importantColors = NUM_COLORS;
   fwrite (&importantColors, sizeof importantColors, 1, file);
 
}