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

int atoi_str(char *str) {
    int i = 0;
    int num = 0;
    int len = strlen(str);
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return -1;
        } else {
            num += atoi(str[i]) * 10^len;
        }
        i++;
        len--;
    }
    return num;
}