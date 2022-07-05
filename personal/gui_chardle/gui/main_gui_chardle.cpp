// UNSW COMP1511 22T2
// Assignment 0: cs_chardle
// This program is the original solution code for a mock program simulating a
//      a simple version of Wordle using characters.

#include <stdio.h>

#include "gui_chardle_lib.h"
    
int main(void) {
    /* Setup window GUI */
    open_window("GUI Chardle", WINDOW_WIDTH, WINDOW_HEIGHT);
    // load font for text
    load_font("gui_font", "arial.ttf");

    /* Render start page */
    render_start_page();
    
    /* Render guess page */
    render_guess_page();

    /* Render blank letterboxes */
    rectangle letterboxes[MAX_ROUNDS];
    render_blank_letterboxes(letterboxes);
    
    /* Game loop - take characters as input */
    // Listen for input
    int target_letterbox_index = 0;
    int player_won = false;
    process_events();
    while (!quit_requested()) {

        // Only play if rounds are available
        if (target_letterbox_index < MAX_ROUNDS && !player_won) {
            player_won = play_guess_round(letterboxes[target_letterbox_index]);
            target_letterbox_index++;
        }

        // Listen for input
        process_events();
    }

    return 0;
}