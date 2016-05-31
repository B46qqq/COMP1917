/*
 *  bmpServer.c
 *  1917 serve that 3x3 bmp from lab3 Image activity
 *
 *  Created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0. 
 *
 */
 // z5114676 Tony Bao
 // z5118939 Minqi Huang

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "mandelbrot.h"
#include "pixelColor.c"
//#include "pixelColor.h"

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
static void serveHTML (int socket);
static void createHeader (int socket);
static void imageProcess (double *x, double *y, int levels, int socket);
static void showMeSomeColor (int *iteration, int socket);



//Just testing;;;

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 8777         //The port for connection and URL
#define NUMBER_OF_PAGES_TO_SERVE 10
// after serving this many pages the server will halt
#define IMAGESIZE 512

int main (int argc, char *argv[]) {
      
   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   

   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");

   char request[REQUEST_BUFFER_SIZE];

   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);

      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation

      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      // were we able to read any data from the connection?
            
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);

      //send the browser a simple html page using http

      double x = 0, y = 0;
      int z;
      int yatCounter = 0;

      yatCounter = sscanf (request, "GET /tile_x%lf_y%lf_z%d.bmp", &x, &y, &z);

      createHeader (connectionSocket);

      if (yatCounter == 3)
      {
         imageProcess (&x, &y, z, connectionSocket);
      }else{
         serveHTML (connectionSocket);
      }
      
      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
   
   return EXIT_SUCCESS; 
}


int escapeSteps(double x, double y){

   double zr = 0, zi = 0;
   double zrsqr, zisqr;
   int counter = 0;

   zrsqr = zr * zr;
   zisqr = zi * zi;
   if (zrsqr * zisqr >= 4.000)
   {
      counter ++;

   }else{
      while((zrsqr + zisqr) < 4.0000 && counter < 256) {

          zi = zr * zi;
          zi += zi + y;
         // zi += y;
          zr = zrsqr - zisqr + x;
          zrsqr = zr * zr;
          zisqr = zi * zi;
          counter ++;
      }

   }
   return counter;
}

static void imageProcess (double *x, double *y, int levels, int socket){
   double xInital, yInital;
   double xFinal, yFinal;
   double xCounter, yCounter;
   int overallcounter = 0;
   double zoomValue = 2.000;
   int zoom = levels;
   while(zoom > 1) {
      zoomValue = zoomValue * 2.0000;
      zoom --;
   }
   zoomValue = 1/zoomValue;
   //pre-defined IMAGESIZE is 512 ;;;
   xInital = *x - (0.5 * IMAGESIZE * zoomValue);
   xFinal = *x + (0.5 * IMAGESIZE * zoomValue);
   yInital = *y - (0.5 * IMAGESIZE * zoomValue);
   yFinal = *y + (0.5 * IMAGESIZE * zoomValue);
   xCounter = xInital;
   yCounter = yInital;
   int iteration;

   while(yCounter < yFinal) {
      iteration = escapeSteps (xCounter, yCounter);
      showMeSomeColor (&iteration, socket);
      xCounter += zoomValue;

      if (xCounter == xFinal)
      {
         xCounter = xInital;
         yCounter += zoomValue;
      }
      overallcounter += 1;
   }
}

static void serveHTML (int socket) {
   char* message;
   // first send the http response header
   message =
      "HTTP/1.0 200 Found\n"
      "Content-Type: text/html\n"
      "\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
 
   message =
      "<!DOCTYPE html>\n"
      "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
      "\n";      
   write (socket, message, strlen (message));
}

static void showMeSomeColor (int *iteration, int socket){
   unsigned char color[] = {stepsToBlue(iteration), stepsToGreen(iteration), stepsToRed(iteration)};
   write (socket, color, 3);
}

static void createHeader (int socket){
   char* message;
   
   // first send the http response header
   
   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
   
   // now send the BMP
   unsigned char bmp[] = {
     0x42,0x4d,0x36,0x00,0x0C,0x00,0x00,0x00,
     0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
     0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
     0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x0C,0x00,0x13,0x0b,
     0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00};

   write (socket, bmp, sizeof(bmp));
}
//-1.482969497394909 -5.68854783693152

// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   memset ((char *) &serverAddress, 0,sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );

   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again

   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}