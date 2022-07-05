#ifndef __CS_CHARDLE_LIB_H
#define __CS_CHARDLE_LIB_H

// Takes a letter and returns its lowercase version.
//
// @param target_char       The target letter to make lowercase.
//
// @returns                 The lowercase version of the input letter.
char make_lowercase(char target_char);

// (ass0 Stage 1) Prints the instructions for playing gui_chardle.
void print_instructions(void);

// Gets a character from user input.
//
// @returns                 The character received from user input
char get_input_char(void);

// Prompts the user for a letter to act as the desired correct answer.
//
// @returns                 The letter provided by the user.
char prompt_correct_letter(void);

// (ass0 Stage 3) Plays a round of guessing by the user.
//
// @param round_num         The number identifying the round being played.
// @param correct_letter    The correct letter that ends the game.
//
// @returns                 A success flag indicating the state of the round.
bool play_guess_round(int round_num, char correct_letter);

#endif // __CS_CHARDLE_LIB_H