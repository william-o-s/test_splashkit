#include <string>

#include "splashkit.h"
#include "cs_chardle_lib.h"

char make_lowercase(char target_char) {
    if (target_char >= 'a' && target_char <= 'z') {
        // Letter is already lowercase
        return target_char;

    } else if (target_char >= 'A' && target_char <= 'Z') {
        // Letter is uppercase; convert to lowercase
        return (target_char - 'A') + 'a';

    } else {
        // Letter is invalid; return EOF as error
        return EOF;
    }
}

void print_instructions(void) {
    write_line("[COMP1511 Guessing Game: CS Chardle]");
    write_line("Welcome to the COMP1511 guessing game.");
    write_line("You will need to input a letter to guess,");
    write_line("Then let the player see the screen, and make guesses.");
}

char get_input_char(void) {
    char input_char = read_char();
    
    return input_char;
}

char prompt_correct_letter(void) {
    // Prompt user for letter
    write("What letter will the player guess? ");
    char correct_letter = get_input_char();

    // Make letter lowercase
    correct_letter = make_lowercase(correct_letter);

    // Error-check on entered letter
    if (correct_letter != EOF) {
        // Letter is valid; Remind user of entered letter
        string correct_letter_str = 
                                std::string("The answer is '") +
                                std::to_string(correct_letter) +
                                std::string("' (ascii ") +
                                std::to_string((int) correct_letter) +
                                std::string(").");
        write_line(correct_letter_str);

        return correct_letter;

    } else {
        // Letter is invalid; return EOF as error
        write_line("The answer must be a valid letter!");
        
        return EOF;
    }
}

bool play_guess_round(int round_num, char correct_letter) {
    // Prompt user for letter
    string guess_letter_str = 
                            std::string("What is guess #") +
                            std::to_string(round_num) +
                            std::string("? ");
    write(guess_letter_str);
    char guess_letter = get_input_char();

    // Make letter lowercase
    guess_letter = make_lowercase(guess_letter);

    if (guess_letter != EOF) {
        // Letter is valid

        if (guess_letter < correct_letter) {
            // Letter is incorrect; correct letter is later in the alphabet
            write_line("Not quite! Guess later in the alphabet.");
            return false;

        } else if (guess_letter > correct_letter) {
            // Letter is incorrect; correct letter is earlier in the alphabet
            write_line("Not quite! Guess earlier in the alphabet.");
            return false;

        } else {
            // Letter is correct
            write_line("Congratulations! You got the letter right!");
            return true;
        }

    } else {
        // Letter is invalid, return FALSE as error
        write_line("Your guess must be a valid letter!");
        return false;
    }
}