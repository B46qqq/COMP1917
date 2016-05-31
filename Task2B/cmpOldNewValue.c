#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#ifdef OLD_MANDELBROT
int escapeSteps(double x, double y){
   //printf("%.06lf, %.06lf\n", x, y);

   double complex Z;
   double complex Z0;
   double complex Z1;

   int counter = 0;

   Z0 = Z1 = 0; //RESET the value of two equations

   double px, py;
   px = x;
   py = y;
   Z = px + py*I;

   px = creal(Z);
   py = cimag(Z);
   if (px*px + py*py >= 4){
         counter ++;
   }else{
     while (px*px + py*py < 4 && counter < 256){
          //printf ("%03d     %8.06lf, %8.06lf => ", counter, px, py);
        Z0 = pow(creal(Z1),2) - pow(cimag(Z1),2) + 2*creal(Z1)*cimag(Z1)*I + x + y*I;
        px = creal(Z0);
        py = cimag(Z0);
        Z1 = px + py*I;
        counter ++;
          //printf("%8.06lf, %8.06lf\n", px, py);
     }

   }
   return counter;
}
#else

int escapeSteps(double x, double y){
   //printf("%.06lf, %.06lf\n", x, y);

   double zr = 0, zi = 0;

   double zrsqr, zisqr;

   int counter = 0;

   zrsqr = zr * zr;
   zisqr = zi * zi;
   if (zrsqr * zisqr >= 4.000)
   {
      counter ++;

   }else{

      while(zrsqr + zisqr < 4.0000 && counter < 256) {
          //printf ("%03d     %8.06lf, %8.06lf => ", counter, zr, zi);
          zi = zr * zi;
          zi += zi + y;
         // zi += y;
          zr = zrsqr - zisqr + x;
          zrsqr = zr * zr;
          zisqr = zi * zi;
          counter ++;
          //printf("%8.06lf, %8.06lf\n", zr, zi);
      }

   }
   return counter;
}
#endif

