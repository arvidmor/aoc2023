#include <string.h>
#include <stdio.h>
#include "../utils.c"

#define BLUE_MAX 14 
#define GREEN_MAX 13 
#define RED_MAX 12 

char *colors[] = {"blue", "green", "red"};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    int BUF_SIZE = 255;
    char line[BUF_SIZE];
    const char *delim = ": \n,";

    while (fgets(line, BUF_SIZE, input)) {
        char *token = strtok(line, delim); // Reads "Game"
        strtok(NULL, delim); // Reads index of game
        int num = 0;
        while ((token = strtok(NULL, delim)) != NULL) {
            if (isnumber(token)) {
                num = atoi_str(token);
            } else {
                for (int i = 0; i < 3; i++) {
                    if (strcmp(token, colors[i]) == 0) {
                        if (i == 0) {
                            printf("Blue: %d\n", num);
                        } else if (i == 1) {
                            printf("Green: %d\n", num);
                        } else {
                            printf("Red: %d\n", num);
                        }
                    }
                }
            }

        }
    }

    fclose(input);
    return 0;
}