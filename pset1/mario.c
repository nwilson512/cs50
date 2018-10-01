/*
- Write, in a file called mario.c in your ~/workspace/pset1/mario/more/ directory, a program that recreates these half-pyramids using hashes (#) for blocks.
- To make things more interesting, first prompt the user for the half-pyramids' heights, a non-negative integer no greater than 23. (The height of the half-pyramids pictured above happens to be 4, the width of each half-pyramid 4, with an a gap of size 2 separating them.)
- If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again.
- Then, generate (with the help of printf and one or more loops) the desired half-pyramids.
- Take care to left-align the bottom-left corner of the left-hand half-pyramid with the left-hand edge of your terminal window.
*/

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cs50.h>

int hash(int count), space(int count, int height);      // declare functions

int count = 0, height = 0;                              // instantiate global integer variables "count" and "height"

int main(void){                                         // start main function
// int count = 0, height = 0;                           // declare variables

  while (height >= 32 || height <= 0){                  // repeatedly check if input is acceptable
    height = get_int("Enter a valid height: ");         // prompt for input
    count = height;                                     // store counter variable to compare to height
  }
  while (count > 0){                                    // loop with "count", drawing the vertical slices of the pyramid
    space(count, height);                               // print leading spaces
    hash(count);                                        // print leading blocks
    printf("  ");                                       // print the two spaces
    hash(count);                                        // print trailing blocks
    printf("\n");                                       // new line
    count--;                                            // decrement "count"
    }
  return 0;                                             // indicate success
}

int hash(int count){                                    // declare a function: "hash"
  for(int x = count; height - x >= 0; x++){             // count up to the difference between number of lines run and orignal value
    printf("#");                                        // print "#"
  }
  return 0;
}

int space(int count, int height){                       // declare a function: "space"
  for(int x = count; x > 0; x--){                       // starting at "count", decrement to "0"
    printf(" ");                                        // print " "
  }
  return 0;
}

/*
Thoughts:
- I can create a function that prints the blocks, that way I don't need any duplicate code for the second half of the pyramid
- Leading spaces need only be printed at the beginning. We do not need trailing spaces
- Interior spaces will be a constant
- I'm still searching for a way to increment the spaces and decrement the hashes using only one variable. It may not be possible to do that. I could create an array to hold both the original value and the counter value. I think doing so would keep them adjecent in memory.
- I'm trying to use "count" and "height" as both variables in the main function and parameters in the functions themselves. I don't think this is possible.
*/
