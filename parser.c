#include <stdio.h>

int parsePriority(char* str) {
    int u = 0;
    sscanf(str, "u=%d", &u);
    return u;
}