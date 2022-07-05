#ifndef __GUI_CHARDLE_LIB_H
#define __GUI_CHARDLE_LIB_H

#include "splashkit.h"
/* GUI */
// Window settings
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// Lettterbox settings
#define LETTERBOX_LEN 200
#define LETTERBOX_MARGIN 50
#define LETTERBOX_PER_ROW 5
#define LETTERBOX_ROWS 2
#define LETTERBOX_ROW_ONE_Y 100.0
#define LETTERBOX_ROW_TWO_Y 350.0

// Letterbox color state settings
#define LETTERBOX_BLANK COLOR_AQUA
#define LETTERBOX_INVALID COLOR_RED
#define LETTERBOX_EARLIER COLOR_YELLOW
#define LETTERBOX_LATER COLOR_ORANGE
#define LETTERBOX_CORRECT COLOR_GREEN

/* Game */
// Game settings
#define MAX_ROUNDS 10
#define CORRECT_LETTER 'j'

// Takes a letter and returns its lowercase version.
//
// @param target_char       The target letter to make lowercase.
//
// @returns                 The lowercase version of the input letter.
char make_lowercase(char target_char);

// Draws text on the main window.
//
// @param text              The text to draw on screen.
// @param x_coord           The x-coordinate of the textbox.
// @param y_coord           The y-coordinate of the textbox.
void render_text_on_screen(string text, double x_coord, double y_coord);

// Draws a letterbox on the main window using a rectangle and a central letter.
//
// @param color_status      The letterbox color according to letter state.
// @param target_rect       The letterbox rectangle object to target.
// @param letter            The letter contained within the letterbox.
void render_letterbox(color color_status, rectangle target_rect, string letter);

// Draws the game's start page.
void render_start_page(void);

// Draws the game's guessing page.
void render_guess_page(void);

// Draws the game's guessing page's initial state of blank letterboxes.
//
// @param letterboxes       An array of rectangles containing rectangles' info.
void render_blank_letterboxes(rectangle letterboxes[MAX_ROUNDS]);

// Initiates one round of the game loop.
//
// @param letterbox         The target rectangle for the letterbox.
//
// @returns                 A Boolean corresponding to the state of the round.
bool play_guess_round(rectangle letterbox);

#endif // __GUI_CHARDLE_LIB_H