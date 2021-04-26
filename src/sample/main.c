#include <stdio.h>
#include "../stringAnsiManagement.h"

int main()
{
    char __buffer[512];
    char *buffer = __buffer;
    buffer += sprintf(buffer, "some text ");
    buffer += string_formatColorMode(buffer, color_create(255, 128, 0), SYSTEM_COLOR_GRAY, CONSOLE_FLAG_UNDERLINE);
    buffer += sprintf(buffer, "then some text");
    buffer += string_resetFormatting(buffer);
    buffer += sprintf(buffer, " some other text\n");
    printf("%s", __buffer);
    return 0;
}