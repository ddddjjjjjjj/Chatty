#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "net.h"

extern char currentUser[32];
extern struct curPosition inputZoneStart, inputZoneEnd, displayZoneStart, displayZoneEnd;

void logout() {
    struct package package;
    package.method = LOGOUT;
    sendMessage(&package);
    strcpy(currentUser, "");
    closeConnect();
    positionPrint(inputZoneStart, inputZoneEnd, "log out\n");
    exit(1);
}