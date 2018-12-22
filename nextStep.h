#ifndef NEXTSTEP_H
#define NEXTSTEP_H
#include "userInput.h"

int exactGuesses(gameInfo info);
int inexactGuesses(gameInfo info);
void getGuess(gameInfo* info);
void hInexact(gameInfo* info, int i, int* count);
void hGuess(int* c, char gc, char maxLetter);
#endif
