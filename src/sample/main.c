#include <stdio.h>
#include "../consoleManagement.h"
#include "../stringAnsiManagement.h"
#include "../stringTable.h"

int main()
{
    table_t table;
    tableCell_t cells[3];
    table.cells = cells;
    table.nCells = 3;
    char *content1[] = {"test"};
    char *content2[] = {"4"};
    char *content3[] = {"", "très grand", "test"};
    content3[0] = malloc(sizeof(char) * 200);
    char *ptr = content3[0];
    ptr += string_formatForeground(ptr, SYSTEM_COLOR_BRIGHT_BLUE);
    ptr += sprintf(ptr, "un beau et");
    ptr += string_resetFormatting(ptr);
    size_t sizeCont1[] = {4};
    size_t sizeCont2[] = {1};
    size_t sizeCont3[] = {10, 10, 4};
    cells[0].alignement = CELL_ALIGNEMENT_TOP_LEFT;
    cells[0].content = content1;
    cells[0].contentSize = sizeCont1;
    cells[0].contentLines = 1;
    cells[0].posX = 0;
    cells[0].posY = 0;
    cells[1].alignement = CELL_ALIGNEMENT_MIDDLE;
    cells[1].content = content2;
    cells[1].contentSize = sizeCont2;
    cells[1].contentLines = 1;
    cells[1].posX = 1;
    cells[1].posY = 0;
    cells[2].alignement = CELL_ALIGNEMENT_TOP_RIGHT;
    cells[2].content = content3;
    cells[2].contentSize = sizeCont3;
    cells[2].contentLines = 3;
    cells[2].posX = 2;
    cells[2].posY = 1;
    table.CellsCountH = 3;
    table.CellsCountV = 2;
    table.minWidth = 80;
    table.minHeight = 11;
    table.tableLinesType = TABLE_LINES_SINGLE;
    table.titleLeftSize = 2;
    table.titleTopSize = 1;
    char buffer[2048];
    size_t s = table_render(table, 3, 2, buffer);
    console_clearScreen();
    printf("%s\n%d\n", buffer, s);
    return 0;
}