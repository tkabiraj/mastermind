#include <stdio.h>
#include "userInput.h"
#include <string.h>
#include <stdlib.h>

gameInfo getInfo(){
   int seed, pos, guess;
   char maxLet;
   gameInfo g;
   printf("Enter the seed for random number generation: ");
   sSeed(&seed);
   flush();
   printf("Enter the maximum letter for the game (A-Z): ");
   mMaxLet(&maxLet);
   flush();
   g.maxLetter = maxLet;
   printf("Enter the number of positions for the game (1-8): ");
   pPos(&pos);
   flush();
   g.numPositions = pos;
   printf("Enter the number of guesses allowed for the game: ");
   gGuess(&guess);
   flush();
   g.numGuesses = guess;
   g = createBoard(seed, g);
   return g;
}

int show(int argc, char* argv[], gameInfo info){
   if(argc > 1) {
      if(strcmp(argv[1], "show")) {
         printf("Initialized Game Board: %s\n", info.gameBoard);
      }
      else {
         fprintf(stderr,"Usage: mastermind [-show]\n");
         return EXIT_FAILURE;
      }
   }
   return 0;
}

void sSeed(int* seed) {
   while(scan(seed)) {
      flush();
      printf("Seed must be an integer value, please try again\n");
      printf("Enter the seed for random number generation: ");
   }
}

void  mMaxLet(char* maxLet) {
   while(scanf(" %c",maxLet) <= 0 || *maxLet < 65 || *maxLet > 90) {
      printf("The letter must be an uppercase A-Z, please try again\n");
      printf("Enter the maximum letter for the game (A-Z): ");
   }
}

void pPos(int* pos) {
   while(scan(pos) || *pos < 1 || *pos > 8) {
      flush();
      printf("The number of positions must be 1-8, please try again\n");
      printf("Enter the number of positions for the game (1-8): ");
   }
}

void gGuess(int* guess) {
   while(scan(guess) || *guess <= 0) {
      flush();
      printf("The number of guesses must be a positive integer, ");
      printf("please try again\n");
      printf("Enter the number of guesses allowed for the game: ");
   }
}

int scan(int *input) {
   return scanf(" %d",input) <= 0;
}

void flush() {
   int c;
   while((c = getchar() != '\n' && c != EOF)) { 
   }
}

gameInfo createBoard(int seed, gameInfo g) {
   int i;
   srand(seed);
   for(i = 0; i < g.numPositions; i++) {
      g.gameBoard[i] = rand() % (g.maxLetter - 'A' + 1) + 'A';
   }
   g.gameBoard[g.numPositions] = '\0';
   return g;
}
