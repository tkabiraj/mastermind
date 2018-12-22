#include <stdio.h>
#include "userInput.h"
#include <string.h>
#include "nextStep.h"
#include <stdlib.h> 
int main(int argc, char* argv[]){
   int i, eguess, iguess;
   gameInfo info;
   info = getInfo();
   if(show(argc, argv, info)) {
      return EXIT_FAILURE;
   }
   info.guess[0] = '\0';
   printf("\n");
   for(i = 1; i <= info.numGuesses; i++){
      while(info.guess[0] == '\0') {
         printf("Enter guess %d: ", i);
         getGuess(&info);
      }
      eguess = exactGuesses(info);
      if (eguess == info.numPositions) {
         printf("\nWow, you won in %d guesses - well done!\n", i);
         return 0;
      }
      iguess = inexactGuesses(info) - eguess;
      info.guess[0] = '\0';
      printf("Nope, %d exact guesses and %d inexact guesses\n\n",
         eguess, iguess);
   }
   printf("Game over, you ran out of guesses. Better luck next time!\n");
   return EXIT_SUCCESS;
}
