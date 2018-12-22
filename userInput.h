#ifndef USERINPUT_H
#define USERINPUT_H
typedef struct gameInfo {
   int maxLetter;
   int numPositions;
   int numGuesses;
   char gameBoard[9];
   char guess[12];
} gameInfo;

void flush();
void gGuess(int* guess);
void sSeed(int* seed);
void pPos(int* pos);
void mMaxLet(char* maxLet);
int scan(int* input);
int show(int argc, char* argv[], gameInfo info);
gameInfo getInfo();
gameInfo createBoard(int seed, gameInfo g);
#endif
