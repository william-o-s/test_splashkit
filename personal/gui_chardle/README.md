# ***GUI Chardle***

## Overview
COMP1511 22T2 introduced Assignment 0, [**cs_chardle**](https://cgi.cse.unsw.edu.au/~cs1511/22T2/flask.cgi/assignments/ass0/index.html), which simulated a version of Wordle using characters instead of words. In ***gui_chardle***, that is extended further with a functioning Graphical User Interface (GUI).

## How to Compile and Run

### Compilation
Install [SplashKit](https://splashkit.io/articles/installation/). There are two versions of this program, one using the Terminal and another using a GUI:
1. To run the Terminal version, execute
```
$ skm clang++ terminal/main_cs_chardle.cpp terminal/cs_chardle_lib.cpp -o cs_chardle
$ ./cs_chardle
```
2. To run the GUI version, execute
```
$ skm clang++ gui/main_gui_chardle.cpp gui/gui_chardle_lib.cpp -o gui_chardle
$ ./gui_chardle
```

### Environment Configurations
**Windows**
- Use MSYS2 MinGW to compile and run your programs. DO NOT USE WSL!

**VSCode**

Include these folders in *C/C++: Edit Configurations*:
- {wherever splashkit is installed}\\.splashkit\\clang++\\include
- {wherever splashkit is installed}\\.splashkit\\clang++\\win_include

## Other Resources
**Documentation**

While building GUI Chardle, I relied on the following pages for information:
- On [Graphics](https://splashkit.io/api/graphics/), i.e. drawing rectangles and text.
- On [Input](https://splashkit.io/api/input/), i.e. getting input from the user, like *scanf()*.
- On [Terminal](https://splashkit.io/api/terminal/), i.e. basic I/O to through the Terminal.
- On [Types](https://splashkit.io/api/types/), i.e. what data types and variables are available.
- On [Windows](https://splashkit.io/api/windows/), i.e. how to control the screen.

**Guides**

I referred to the following sample guides for reference:
- [Getting Started Drawing using Procedures](https://splashkit.io/articles/guides/tags/starter/get-started-drawing/)
- [Reading Text](https://splashkit.io/articles/guides/tags/starter/reading-text/)

**Related Projects**
- [Cave Escape](https://github.com/jakerenzella/cave-escape) by Jake Renzella (@jakerenzella).
- [Social Chardle](https://github.com/zazer0/social_chardle) by Zac S (@zazer0).