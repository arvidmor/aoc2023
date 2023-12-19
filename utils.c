#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


bool isnumber(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}
