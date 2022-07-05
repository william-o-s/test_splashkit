# ***gui_chardle***

## Overview
COMP1511 22T2 introduced Assignment 0, [**cs_chardle**](https://cgi.cse.unsw.edu.au/~cs1511/22T2/flask.cgi/assignments/ass0/index.html), which simulated a version of Wordle using characters instead of words. In ***gui_chardle***, that is extended further with a functioning Graphical User Interface (GUI).

## How to Compile and Run
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