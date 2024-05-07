#include <stdint.h>
#include <stdio.h>

#ifndef _DISPLAY_H
#define _DISPLAY_H 1

#define clearScreen() \
    { printf("\033[2J"); }
#define setCur(x, y) \
    { printf("\033[%d;%dH", x, y); }
#define saveCur() \
    { printf("\033[s"); }
#define restoreCur() \
    { printf("\033[u"); }

struct curPosition {
    uint16_t  row,col;
};

void formatPrint(struct curPosition position, struct curPosition limit, char *format, ...);

void clear(struct curPosition start, struct curPosition limit);
#endif
