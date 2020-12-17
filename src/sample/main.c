#include <stdio.h>
#include "../consoleManagement.h"

int main()
{
    int currentValue = 0;
    int selection = 0;

    console_clearScreen();

    while (1)
    {
        console_setCursorPosition(2, 1);
        console_formatSystemColor("Result:%d", CONSOLE_COLOR_GREEN, CONSOLE_COLOR_WHITE, currentValue);
        console_eraseEndOfLine();
        console_setCursorPosition(0, 2);
        if (selection == 0)
            console_formatMode(" 1 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 1 ");
        if (selection == 1)
            console_formatMode(" 2 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 2 ");
        if (selection == 2)
            console_formatMode(" 3 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 3 ");
        console_setCursorPosition(0, 3);
        if (selection == 3)
            console_formatMode(" 4 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 4 ");
        if (selection == 4)
            console_formatMode(" 5 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 5 ");
        if (selection == 5)
            console_formatMode(" 6 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 6 ");
        console_setCursorPosition(0, 4);
        if (selection == 6)
            console_formatMode(" 7 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 7 ");
        if (selection == 7)
            console_formatMode(" 8 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 8 ");
        if (selection == 8)
            console_formatMode(" 9 ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" 9 ");
        if (selection == 9)
            console_formatMode(" END ", CONSOLE_FLAG_REVERSE_COLOR);
        else
            printf(" END ");
        int key;
        while ((key = console_getArrowPressed()) == CONSOLE_KEY_OTHER)
            ;
        if (key == CONSOLE_KEY_RETURN)
            if (selection < 9)
                currentValue = currentValue * 10 + selection + 1;
            else
                break;
        else if (key == CONSOLE_KEY_LEFT &&
                 selection != 0 &&
                 selection != 3 &&
                 selection != 6)
            selection--;
        else if (key == CONSOLE_KEY_RIGHT &&
                 selection != 2 &&
                 selection != 5 &&
                 selection != 9)
            selection++;
        else if (key == CONSOLE_KEY_UP &&
                 selection != 0 &&
                 selection != 1 &&
                 selection != 2 &&
                 selection != 9)
            selection -= 3;
        else if (key == CONSOLE_KEY_UP &&
                 selection == 9)
            selection -= 4;
        else if (key == CONSOLE_KEY_DOWN &&
                 selection != 6 &&
                 selection != 7 &&
                 selection != 8 &&
                 selection != 9)
            selection += 3;
    }
    console_setCursorPosition(0, 5);
    return 0;
}