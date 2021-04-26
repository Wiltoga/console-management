#include <stdio.h>
#include <stdlib.h>
#include "consoleManagement.h"
#include <termios.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
//https://www.includehelp.com/c-programs/gotoxy-clrscr-getch-getche-for-gcc-linux.aspx
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);                 //grab old terminal i/o settings
    new = old;                          //make new settings same as old settings
    new.c_lflag &= ~ICANON;             //disable buffered i/o
    new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &new);        //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/*
Read 1 character without echo
getch() function definition.
*/
char getch(void)
{
    return getch_(0);
}

/*
Read 1 character with echo
getche() function definition.
*/
char getche(void)
{
    return getch_(1);
}

void console_formatMode(char *content, uint8_t flags, ...)
{
    va_list args;
    va_start(args, flags);
    char str[50] = "";
    bool firstAdded = false;
    if (flags & CONSOLE_FLAG_BOLD)
    {
        strcat(str, "1");
        firstAdded = true;
    }
    if (flags & CONSOLE_FLAG_UNDERLINE)
    {
        if (firstAdded)
            strcat(str, ";4");
        else
        {
            strcat(str, "4");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_BLINK)
    {
        if (firstAdded)
            strcat(str, ";5");
        else
        {
            strcat(str, "5");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
    {
        if (firstAdded)
            strcat(str, ";7");
        else
            strcat(str, "7");
    }
    printf("\x1b[%sm", str);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatBackground(char *content, color_t background, ...)
{
    va_list args;
    va_start(args, background);
    if (isColorCustom(background))
        printf("\x1b[48;2;%d;%d;%dm", color_getRed(background), color_getGreen(background), color_getBlue(background));
    else
        printf("\x1b[%dm", background + 10);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatBackgroundMode(char *content, color_t background, uint8_t flags, ...)
{
    va_list args;
    va_start(args, flags);
    if (isColorCustom(background))
        printf("\x1b[48;2;%d;%d;%dm", color_getRed(background), color_getGreen(background), color_getBlue(background));
    else
        printf("\x1b[%dm", background + 10);
    char str[50] = "";
    bool firstAdded = false;
    if (flags & CONSOLE_FLAG_BOLD)
    {
        strcat(str, "1");
        firstAdded = true;
    }
    if (flags & CONSOLE_FLAG_UNDERLINE)
    {
        if (firstAdded)
            strcat(str, ";4");
        else
        {
            strcat(str, "4");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_BLINK)
    {
        if (firstAdded)
            strcat(str, ";5");
        else
        {
            strcat(str, "5");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
    {
        if (firstAdded)
            strcat(str, ";7");
        else
            strcat(str, "7");
    }
    printf("\x1b[%sm", str);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatForeground(char *content, color_t foreground, ...)
{
    va_list args;
    va_start(args, foreground);
    if (isColorCustom(foreground))
        printf("\x1b[38;2;%d;%d;%dm", color_getRed(foreground), color_getGreen(foreground), color_getBlue(foreground));
    else
        printf("\x1b[%dm", foreground);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatForegroundMode(char *content, color_t foreground, uint8_t flags, ...)
{
    va_list args;
    va_start(args, flags);
    if (isColorCustom(foreground))
        printf("\x1b[38;2;%d;%d;%dm", color_getRed(foreground), color_getGreen(foreground), color_getBlue(foreground));
    else
        printf("\x1b[%dm", foreground);
    char str[50] = "";
    bool firstAdded = false;
    if (flags & CONSOLE_FLAG_BOLD)
    {
        strcat(str, "1");
        firstAdded = true;
    }
    if (flags & CONSOLE_FLAG_UNDERLINE)
    {
        if (firstAdded)
            strcat(str, ";4");
        else
        {
            strcat(str, "4");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_BLINK)
    {
        if (firstAdded)
            strcat(str, ";5");
        else
        {
            strcat(str, "5");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
    {
        if (firstAdded)
            strcat(str, ";7");
        else
            strcat(str, "7");
    }
    printf("\x1b[%sm", str);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatColor(char *content, color_t foreground, color_t background, ...)
{
    va_list args;
    va_start(args, background);
    if (isColorCustom(background))
        printf("\x1b[48;2;%d;%d;%dm", color_getRed(background), color_getGreen(background), color_getBlue(background));
    else
        printf("\x1b[%dm", background + 10);
    if (isColorCustom(foreground))
        printf("\x1b[38;2;%d;%d;%dm", color_getRed(foreground), color_getGreen(foreground), color_getBlue(foreground));
    else
        printf("\x1b[%dm", foreground);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_formatColorMode(char *content, color_t foreground, color_t background, uint8_t flags, ...)
{
    va_list args;
    va_start(args, flags);
    if (isColorCustom(background))
        printf("\x1b[48;2;%d;%d;%dm", color_getRed(background), color_getGreen(background), color_getBlue(background));
    else
        printf("\x1b[%dm", background + 10);
    if (isColorCustom(foreground))
        printf("\x1b[38;2;%d;%d;%dm", color_getRed(foreground), color_getGreen(foreground), color_getBlue(foreground));
    else
        printf("\x1b[%dm", foreground);
    char str[50] = "";
    bool firstAdded = false;
    if (flags & CONSOLE_FLAG_BOLD)
    {
        strcat(str, "1");
        firstAdded = true;
    }
    if (flags & CONSOLE_FLAG_UNDERLINE)
    {
        if (firstAdded)
            strcat(str, ";4");
        else
        {
            strcat(str, "4");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_BLINK)
    {
        if (firstAdded)
            strcat(str, ";5");
        else
        {
            strcat(str, "5");
            firstAdded = true;
        }
    }
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
    {
        if (firstAdded)
            strcat(str, ";7");
        else
            strcat(str, "7");
    }
    printf("\x1b[%sm", str);
    vprintf(content, args);
    printf("\x1b[0m");
    va_end(args);
}
void console_saveCursorPosition()
{
    printf("\x1b[s");
}
void console_restoreCursorPosition()
{
    printf("\x1b[u");
}
void console_eraseEndOfLine()
{
    printf("\x1b[K");
}
void console_setCursorPosition(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}
void console_clearScreen()
{
    printf("\x1b[2J\x1b[1;1H");
}

int console_getArrowPressed()
{
    //https://stackoverflow.com/a/10473315
    int var = getch();
    if (var == 27)
    {
        getch();
        switch (getch())
        {
        case 65:
            return CONSOLE_KEY_UP;
        case 66:
            return CONSOLE_KEY_DOWN;
        case 68:
            return CONSOLE_KEY_LEFT;
        case 67:
            return CONSOLE_KEY_RIGHT;
        default:
            return CONSOLE_KEY_OTHER;
        }
    }
    else if (var == 10)
        return CONSOLE_KEY_RETURN;
    else
        return CONSOLE_KEY_OTHER;
}
