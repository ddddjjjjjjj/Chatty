#include "display.h"
#include <stdarg.h>

void formatPrint(struct curPosition position, struct curPosition limit, char *format, ...) {
    uint16_t col = position.col;
    uint16_t row = position.row;
    char buffer[4096];

    va_list arglist;
    va_start(arglist, format);
    vsprintf(buffer, format, arglist);
    va_end(arglist);

    setCur(row++, col);

    int lineLen = limit.col - position.col;
    char *p = buffer;
    int len = 0;
    while(*p != '\0') {
        if(*p == '\n' || len > lineLen ){
            setCur(row++, col);
            len = 0;
            if(row > limit.row) break;
        }
        else{
            putchar(*p);
        }
        p++;
        len++;
    }
}
