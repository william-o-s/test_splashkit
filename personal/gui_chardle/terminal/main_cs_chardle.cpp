// UNSW COMP1511 22T2
// Assignment 0: cs_chardle
// This program is the original solution code for a mock program simulating a
//      a simple version of Wordle using characters.

#include <stdio.h>
#include <ctype.h>

#include "splashkit.h"
#include "cs_chardle_lib.h"

#define MAX_ROUNDS 10
    
int main(void) {
    print_instructions();

    char correct_letter = prompt_correct_letter();

    int round_num = 1;
    while (round_num <= MAX_ROUNDS) {
        if (play_guess_round(round_num, correct_letter))
            return 0;

        round_num++;
    }

    return 0;
}