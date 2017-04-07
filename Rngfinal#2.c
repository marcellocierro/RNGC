#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


/* Marcello Cierro
   Assignent #1-B Due Friday Sept. 23 2016

   This program will generate a sequence of random nubmers provided
   with command line options to specify the numbers to produce as well
   as the range into which they fall into(default is set to 10 number
   which range from 1 to 100)

   The primary data stucture utilized is a while loop to obtain user input for command line
	 options. Additionally, there is a for loop which generates random numbers using the user inputed
	 parameters.
   numbers based on the information that we gathered from the user.

   Uses "getopt" for command-line options

	 User input involves the amount of numbers to be generated, n, the lowerbound for the numbers
	 generated, l, and the upperbound for the numbers generated, u.


	 Errors found will be handled with an error message, errors occur if user enters no input.

   The data included are; user variables, options, random number generator, and
   opt out.

   Code reference from Odendahl
   http://cs.oswego.edu/~odendahl/coursework/csc344/notes/c/getopt/b/main.c

  */

 // Formula to calculate lower bounds and upperbounds
int rng (int l, int u){
	return (rand() % (u+1 - l) + l);
}
int main(int argc, char *argv[]) {
	// default case for random number generator
   int n = 10;
   int l = 1;
   int u = 100;

	 //uses internal clock to seed random number generator
   srand (time(NULL));
   int c = 0;

   //provides options
   char *options = ":n:l:u:";


	 //while loop to start collecting user options
   while ((c = getopt(argc,argv,options)) != -1) {
     //prompts user to put correct input, catching any erros made through error messaging
      if (c == '?') {
         c = optopt;
         printf("Error %c\n",c);
      } else if (c == ':') {
         c = optopt;
         printf("Please enter the missing value %c\n",c);
      }
      else {
				//case switches for command line inputs
         switch (c) {
            case 'n':
            n = atoi(optarg); // reads user input
               break; //stops case to start next case
            case 'l':
            l = atoi(optarg);// see above " "
               break;  // see above " "
            case 'u':
            u = atoi(optarg); // " "
               break;// " "

         }

      }
   }
   // for loop printing n numbers b/c n inputed by the user

      for (int i = 0; i < n; ++i){
   		printf("%d\n", rng(l, u));
   }
   return 0; //exit case, when the program runs sucessfully, since main is of type int.
}
