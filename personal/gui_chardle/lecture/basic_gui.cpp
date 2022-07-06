#include "splashkit.h"

int main(void) {
    /* Initialize main GUI window */
    open_window("Hi COMP1511!", 800, 600);
    clear_screen(COLOR_BLANCHED_ALMOND);
    refresh_screen();

    /* Draw rectangles */
    fill_rectangle(COLOR_BLUE, 10.0, 10.0, 1000.0, 1000.0);
    refresh_screen();

    /* Draw words */
    draw_text("Welcome to bonus lecture comp1511!", COLOR_BLACK, 40, 40);
    refresh_screen();

    /* GUI loop - wait until window is closed */
    while (!quit_requested()) {
        process_events();
    }

    return 0;
}