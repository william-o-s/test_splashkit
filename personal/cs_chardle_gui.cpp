#include "splashkit.h"

#define TRUE 1
#define FALSE 0

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define TEST_WORD "UNSW"
#define TEST_WORD_LEN 4

#define LETTERBOX_LEN 200
#define LETTERBOX_MARGIN 20
#define LETTERBOX_TOTAL_WIDTH (TEST_WORD_LEN*LETTERBOX_LEN + (TEST_WORD_LEN-1)*LETTERBOX_MARGIN)
#define LETTERBOX_STARTING_COORD_X ((WINDOW_WIDTH - LETTERBOX_TOTAL_WIDTH) / 2)
#define LETTERBOX_WINDOW_CENTER_COORD_Y ((WINDOW_HEIGHT / 2) - (LETTERBOX_LEN / 2))

#define COLOR_LETTER COLOR_BLACK
#define COLOR_CORRECT COLOR_GREEN
#define COLOR_ALMOST COLOR_GOLD
#define COLOR_WRONG COLOR_GRAY

///////////////////////////////// PROTOTYPES /////////////////////////////////
color check_letter(char target_letter, int position);

///////////////////////////////// PROCEDURES /////////////////////////////////
/*
    init_window(): Initializes the main SplashKit window.
        Input   --> (void)
        Output  --> (void) Initializes in-place.
*/
void init_window(void) {
    open_window("Basic Window", WINDOW_WIDTH, WINDOW_HEIGHT);
}

/*
    draw_letter(): Draws a single letter on the main window.
        Input   --> (char) The letter to draw
                --> (int) The x-coordinate of the letter
                --> (int) The y-coordinate of the letter
        Output  --> (void) Draws in-place.
*/
void draw_letter(char target_letter, double coord_x, double coord_y) {
    char convert_str[2] = { target_letter, 0 };

    draw_text(convert_str, COLOR_LETTER, "Arial", 11, coord_x, coord_y);
}

/*
    draw_letterbox(): Draws a box to contain a letter on the main window.
        Input   --> (char) The letter to draw
                --> (int) The x-coordinate of the letter
                --> (int) The y-coordinate of the letter
        Output  --> (void) Draws in-place.
*/
void draw_letterbox(void) {
    clear_screen(COLOR_ANTIQUE_WHITE);

    int letter_counter = 0;
    while (letter_counter < TEST_WORD_LEN) {
        int coord_x = LETTERBOX_STARTING_COORD_X + letter_counter*(LETTERBOX_LEN + LETTERBOX_MARGIN);
        fill_rectangle(COLOR_CORRECT, coord_x, LETTERBOX_WINDOW_CENTER_COORD_Y, LETTERBOX_LEN, LETTERBOX_LEN);
        draw_letter(TEST_WORD[letter_counter], coord_x + 20, LETTERBOX_WINDOW_CENTER_COORD_Y + 20);

        letter_counter++;
    }

    refresh_screen();
}

//////////////////////////////////// MAIN ////////////////////////////////////
int main(void) {
    init_window();

    draw_letterbox();

    delay(20000);

    return 0;
}

////////////////////////////////// FUNCTIONS //////////////////////////////////
/*
    check_letter(): Checks if a letter in a given position (zero-based) is correct.
        Input   --> (char) The letter to check
                --> (int) The (zero-based) coordinate of the letter
        Output  --> (color) The appropriate color code of the letter's position
*/
color check_letter(char target_letter, int position) {
    if (target_letter == TEST_WORD[position]) {
        return COLOR_CORRECT;
    } else {
        int counter = 0;
        int within_word_flag = FALSE;
        while (counter < TEST_WORD_LEN) {
            if (target_letter == TEST_WORD[counter]) {
                within_word_flag = TRUE;
            }

            counter++;
        }

        if (within_word_flag == TRUE) {
            return COLOR_ALMOST;
        } else {
            return COLOR_WRONG;
        }
    }
}