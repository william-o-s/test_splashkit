#include <string>

#include "splashkit.h"
#include "gui_chardle_lib.h"

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

void render_text_on_screen(string text, double x_coord, double y_coord) {
    draw_text(text, COLOR_BLACK, font_named("gui_font"), 24, x_coord, y_coord);

    // Render UI elements on screen
    refresh_screen();

    return;
}

void render_letterbox(color color_status, rectangle target_rect, string letter) {
    // Render the letterbox
    fill_rectangle(color_status, target_rect);
    
    // Render text on the letterbox
    double letter_x_coord = target_rect.x + (target_rect.width / 2);
    double letter_y_coord = target_rect.y + (target_rect.height / 2);
    render_text_on_screen(letter, letter_x_coord - 10, letter_y_coord - 10);

    // Render UI elements on screen
    refresh_screen();

    return;
}

void render_start_page(void) {
    // Reset screen to white
    clear_screen(COLOR_WHITE);

    // Load prompt text
    render_text_on_screen("[COMP1511 Guessing Game: CS Chardle]", 424, 200); // 36
    render_text_on_screen("Welcome to the COMP1511 guessing game.", 412, 230); // 38
    render_text_on_screen("You will need to type a letter to guess,", 400, 260); // 40
    render_text_on_screen("Then let the player see the screen, and make guesses.", 322, 290); // 53
    render_text_on_screen("Press the SPACEBAR to start!", 472, 600); // 28
    
    // Render UI elements on screen
    refresh_screen();

    // Wait for user input to end start page
    while (!key_typed(SPACE_KEY)) {
        process_events();
    }

    return;
}

void render_guess_page(void) {
    // Reset screen to white
    clear_screen(COLOR_WHITE);

    // Load prompt text
    render_text_on_screen("What letter will the player guess? (Type your character, then press Enter)", 196, 20); // 74
    render_text_on_screen("Red = Invalid", 1000, 600);
    render_text_on_screen("Yellow = Earlier", 1000, 630);
    render_text_on_screen("Orange = Later", 1000, 660);
    render_text_on_screen("Green = Correct", 1000, 690);

    // Render UI elements on screen
    refresh_screen();
}

void render_blank_letterboxes(rectangle letterboxes[MAX_ROUNDS]) {
    // NOTE: x-coordinates calculated by taking full width of letterboxes and
    //       subtracting from window width, then centering
    double letterbox_x_coords[LETTERBOX_PER_ROW] = { 40.0,
                                                     290.0,
                                                     540.0,
                                                     790.0,
                                                     1040.0 };
    double letterbox_y_coords[LETTERBOX_ROWS] = { LETTERBOX_ROW_ONE_Y,
                                                  LETTERBOX_ROW_TWO_Y };
    int letterbox_row_counter = 0;
    int total_letterboxes = 0;
    while (letterbox_row_counter < LETTERBOX_ROWS) {
        // Make row of letterboxes

        int letterbox_counter = 0;
        while (letterbox_counter < LETTERBOX_PER_ROW) {
            // Make each letterbox
            rectangle new_letterbox;
            new_letterbox.height = LETTERBOX_LEN;
            new_letterbox.width = LETTERBOX_LEN;
            new_letterbox.x = letterbox_x_coords[letterbox_counter];
            new_letterbox.y = letterbox_y_coords[letterbox_row_counter];
            
            // Store letterbox
            letterboxes[total_letterboxes] = new_letterbox;
            // Render letterbox
            render_letterbox(LETTERBOX_BLANK, new_letterbox, " ");

            letterbox_counter++;
            total_letterboxes++;
        }

        letterbox_row_counter++;
    }
}

bool play_guess_round(rectangle letterbox) {
    
    /* Listen for input */
    start_reading_text(letterbox);
    process_events();

    while (reading_text()) {
        // Listen for input
        process_events();
    }
    
    /* Get input character from user and make it lowercase */
    string user_input = text_input();
    char guess_letter = user_input[0];
    guess_letter = make_lowercase(guess_letter);
    
    /* Check answer */
    if (guess_letter != EOF) {
        // Letter is valid

        if (guess_letter < CORRECT_LETTER) {
            // Letter is incorrect; correct letter is later in the alphabet
            render_letterbox(LETTERBOX_EARLIER, letterbox, user_input);
            return false;

        } else if (guess_letter > CORRECT_LETTER) {
            // Letter is incorrect; correct letter is earlier in the alphabet
            render_letterbox(LETTERBOX_LATER, letterbox, user_input);
            return false;

        } else {
            // Letter is correct
            render_letterbox(LETTERBOX_CORRECT, letterbox, user_input);
            return true;
        }

    } else {
        // Letter is invalid
        render_letterbox(LETTERBOX_INVALID, letterbox, "?");
        return false;
    }
}