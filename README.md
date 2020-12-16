# Console Management

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
        console_formatSystemForeground("hello world!", CONSOLE_COLOR_BRIGHT_BLUE);
        printf("\n");
        console_formatSystemColor("hello world!", CONSOLE_COLOR_BLUE, CONSOLE_COLOR_RED);
        printf("\n");
        console_formatSystemColorMode("hello world!", CONSOLE_COLOR_BLUE, CONSOLE_COLOR_RED, CONSOLE_FLAG_UNDERLINE);
        printf("\n");
        console_formatRGBBackground("hello world!", console_color(220, 50, 160));
        printf("\n");
        console_formatRGBColorMode("hello world!",
                                console_color(50, 150, 220),                                    //foreground
                                console_color(20, 20, 40),                                      //background
                                CONSOLE_FLAG_BLINK | CONSOLE_FLAG_BOLD | CONSOLE_FLAG_UNDERLINE //flags
        );
        printf("\n");
        return 0;
    }
```
![](display.gif)
- Can move/save/restore the cursor position in the console
- Clean the console or only the remaining characters in a line

## Installation

Just copy the [consoleManagement.h](src/consoleManagement.h) and [consoleManagement.c](src/consoleManagement.c) files into your source files, and compile `consoleManagement.c`.