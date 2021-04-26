# Console Management

> `2021/04/27` : Ok, I feel kinda sad that I just learned the existence of ncurses, and now I feel like this repo is totally useless (perhaps the grid stuff could be great, still). I won't update much from now on.

Small file that provides utility functions to format the console. Only works for Linux for now.

## Features

- Changing the color of the console and formatting the text
The following code should output the next gif (sorry for the bad quality) :
```c
    #include <stdio.h>
    #include "consoleManagement.h"

    int main()
    {
        printf("hello world!");
        printf("\n");
        console_formatMode("hello world!", CONSOLE_FLAG_BOLD);
        printf("\n");
        console_formatMode("hello world!", CONSOLE_FLAG_BOLD | CONSOLE_FLAG_UNDERLINE);
        printf("\n");
        console_formatForeground("hello world!", SYSTEM_COLOR_BRIGHT_BLUE);
        printf("\n");
        console_formatColor("hello world!", SYSTEM_COLOR_BLUE, SYSTEM_COLOR_RED);
        printf("\n");
        console_formatColorMode("hello world!", SYSTEM_COLOR_BLUE, SYSTEM_COLOR_RED, CONSOLE_FLAG_UNDERLINE);
        printf("\n");
        console_formatBackground("hello world!", color_create(220, 50, 160));
        printf("\n");
        console_formatColorMode("hello world!",
                                color_create(50, 150, 220),                                    //foreground
                                color_create(20, 20, 40),                                      //background
                                CONSOLE_FLAG_BLINK | CONSOLE_FLAG_BOLD | CONSOLE_FLAG_UNDERLINE //flags
        );
        printf("\n");
        return 0;
    }
```
![](https://raw.githubusercontent.com/WildGoat07/console-management/f0f3854f95a5424c61d47efff6df50ac3e7bb38c/display.gif)
- Can move/save/restore the cursor position in the console
- Clean the console or only the remaining characters in a line
- Can format only a string instead of the console
- Can draw tables (need presentation)

## Installation

Just copy the files into your source files, and compile them.
