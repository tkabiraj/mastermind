#include <stdio.h>
#include <string.h>
#include "nextStep.h"
#include "userInput.h"

int exactGuesses(gameInfo info){
   int i, count = 0;
   for(i = 0; i < info.numPositions; i++) {
      if(info.gameBoard[i] == info.guess[i]) {
         count++;
      }
   }
   return count;
}

int inexactGuesses(gameInfo info){
   int count = 0;
   int i;
   for(i = 0; i < info.numPositions; i++) {
      hInexact(&info, i, &count);
   }
   return count;
}
void hInexact(gameInfo* info, int i, int* count) {
   int j;
   for(j = 0; j < info ->numPositions; j++) {
      if(info-> gameBoard[i] == info->guess[j]) {
         ++*count;
         info->guess[j] = '\0';
         break;
      }
   }
}

void getGuess(gameInfo* info) {
   int i, c = 1;
   for(i = 0; i < info -> numPositions; i++) {
      while(scanf(" %c",info ->guess+ i) <= 0 && info ->guess[i] != '\n') {
         info -> guess[i+i] = '\0';
      }
      hGuess(&c, info -> guess[i], info -> maxLetter);
   }
   if(!c) {
      printf("Invalid guess, please try again\n\n");
      info -> guess[0] = '\0';
   }
}

void hGuess(int* c, char gc, char maxLetter) {
   if(gc < 65 || gc > maxLetter) {
      *c = 0;
   }
}
