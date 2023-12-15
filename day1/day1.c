#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *digits[10] = {
    "zero",
    "one", 
    "two", 
    "three", 
    "four", 
    "five", 
    "six", 
    "seven", 
    "eight", 
    "nine"
};

int get_digit(char *word) {
    if (isdigit(word[0])) {
        return word[0]-48;
    } else {
        for (int i = 0; i < 10; i++) {
            if (strncmp(word, digits[i], strlen(digits[i])) == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    int BUF_SIZE = 255;
    char line[BUF_SIZE];
    int sum = 0; 

    while (fgets(line, BUF_SIZE,input)) {
        int leftmost = -1;
        int rightmost;
        int i = 0;
        while (line[i] != '\0') {
            int num = get_digit(&line[i]);
            if (num >= 0) {
                if (leftmost < 0) {
                    leftmost = num;
                }
                rightmost = num;
            }
            i++;
        }
        sum += leftmost*10 + rightmost; 
        printf("%d\n", sum);

    }
    fclose(input);
    return 0;
}
