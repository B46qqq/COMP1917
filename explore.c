//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//This C file is for playing around 
//Tony Bao, Harris Yang
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
long add (int x, int y);
void FindSizeUnsigned(unsigned long a, unsigned int b, unsigned long long c, unsigned short d);
void FindSizeSigned(signed long a, signed int b, signed long long c, signed short d);
void FindSizeofChar(char a);
void Others(long a, int b, long long c, short d, float e, double f);
void GetTheirAddress(unsigned long a, unsigned int b, unsigned long long c, unsigned short d);
void overORunderflowing(unsigned long a, unsigned int b, unsigned long long c, unsigned short d);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long total;
   unsigned long *ptr1;
   unsigned int *ptr2;
   unsigned long long *ptr3;
   unsigned short *ptr4;
 
   x = 40;
   y = 2;
 
   total = add (x, y);
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
 
   //total = add (x, y);
 
  // printf("the sum of %d and %d is %ld\n", x, y, total);
 
   char c ='a';
 
   unsigned long ul       = 0;
   ptr1 = &ul;
   unsigned int ui        = 1;
   ptr2 = &ui;
   unsigned long long ull = 2;
   ptr3 = &ull;
   unsigned short us      = 3;
   ptr4 = &us;


   signed long sl         = 4;
   signed int si          = 5;
   signed long long sll   = 6;
   signed short ss        = 7;
 
   long l       = 8;
   int i        = 9;
   long long ll = 10;
   short s      = 11;
 
   float f = 3.1;
   double d = 3.14;

   FindSizeUnsigned(ul,ui, ull, us);
   FindSizeSigned(sl, si, sll, ss);
   FindSizeofChar(c);
   Others(l, i, ll, s, f, d);

   printf("The address of each\n");
   printf("This test also shows that the same value in \ndifferent functions are different\n");
   printf("Address of unsigned variables in the main function: \n");
   printf("The address for unsigned long - ul :       %p\n", ptr1);
   printf("The address for unsigned int - ul :        %p\n", ptr2);
   printf("The address for unsigned long long - ul :  %p\n", ptr3);
   printf("The address for unsigned short - ul :      %p\n", ptr4);

   printf("compare to the same value but in another function\n");
   printf("\n");
   GetTheirAddress(ul, ui, ull, us);

   printf("---------------------------------------------\n");
   printf("\n");
   printf("-------------------------\n");
   overORunderflowing(ul, ui, ull, us);

 //  GetTheirAddress(ul, ui, ull, us);
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
 

void FindSizeUnsigned(unsigned long a, unsigned int b, unsigned long long c, unsigned short d){
   printf("The size of unsigned long is:     %lu \n", sizeof(a));
   printf("The size of unsigned int is:      %lu \n", sizeof(b));
   printf("The size of unsigned long long:   %lu \n", sizeof(c));
   printf("The size of unsigned short:       %lu \n", sizeof(d));
   printf("\n");
}

void FindSizeSigned(signed long a, signed int b, signed long long c, signed short d){
   printf("The size of signed long is:       %lu \n", sizeof(a));
   printf("The size of signed int is:        %lu \n", sizeof(b));
   printf("The size of signed long long:     %lu \n", sizeof(c));
   printf("The size of signed short:         %lu \n", sizeof(d));
   printf("\n");
}

void FindSizeofChar(char a){
   printf("The size of char:                 %lu \n", sizeof(a));
   printf("\n");
}

void Others(long a, int b, long long c, short d, float e, double f){
   printf("The size of long :                %lu \n", sizeof(a));
   printf("The size of int :                 %lu \n", sizeof(b));
   printf("The size of long long             %lu \n", sizeof(c));
   printf("The size of short :               %lu \n", sizeof(d));
   printf("The size of float :               %lu \n", sizeof(e));
   printf("The size of double :              %lu \n", sizeof(f));
   printf("\n");

}

void GetTheirAddress(unsigned long a, unsigned int b, unsigned long long c, unsigned short d){

   unsigned long *ptrA = &a;
   unsigned int  *ptrB = &b;
   unsigned long long *ptrC = &c;
   unsigned short *ptrD = &d;

   printf("The address for unsigned long - ul :       %p\n", ptrA);
   printf("The address for unsigned int - ul :        %p\n", ptrB);
   printf("The address for unsigned long long - ul :  %p\n", ptrC);
   printf("The address for unsigned short - ul :      %p\n", ptrD);
 //  unsigned LOOOOOP[4] = {*ptrA, *ptrB, *ptrC, *ptrD};
 /*  for (int i = 0; i < 4; i++)
   {
      printf("The address is : %x\n", LOOOOOP[i]);
   }*/
}

void overORunderflowing(unsigned long a, unsigned int b, unsigned long long c, unsigned short d){
   int maxunsignedlong = pow(2, 31) -1 ;
   int maxunsignint = pow(2, 31)-1;
   int maxunsignlonglong = pow( 2, 31) -1;
   int maxunsignedshort = pow(2, 15)-1;

   printf("Since the unsigned long variables type take up to 8 bytes\n");
   printf("That means, it also take up to 8 x 8 = 64 bits\n");
   printf("however since this machine have a 32bits compiler thus, \n");
   printf("in theory it can compile maximum of 32 bits\n");
   printf("also it does NOT use it's first bit to represent the sign \n");
   printf("which for the maximum value is equal to %d\n", maxunsignedlong);
   printf("\n");
   printf("----------------------------------------\n");
   printf("\n");
   printf("Unsigned int type take up to 4 bytes\n");
   printf("For which it can store up to %d\n", maxunsignint);
   printf("\n");
   printf("--------------------------------------\n");
   printf("\n");
   printf("unsigned long long can have same bytes as unsigned long\n");
   printf("since the machine have 32 bits compiler\n");
   printf("Thus, it can also store up to %d\n", maxunsignlonglong);
   printf("\n");
   printf("-----------------------------------------\n");
   printf("\n");
   printf("Unsigned short type can take up to 2 bytes\n");
   printf("which is the same as 2 x 8 = 16 bits\n");
   printf("which is equal to %d\n", maxunsignedshort);
   printf("\n");
   printf("\n");

}

