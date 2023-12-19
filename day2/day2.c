#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils.c"

#define BLUE_MAX 14 
#define GREEN_MAX 13 
#define RED_MAX 12 

int parse_game(char *line, bool *game) {
    int num;
    char *delim =  " :;,\n";
    char *token = strtok(line, " "); // Should be "Game"
    token = strtok(NULL, delim); // Should be game id
    int game_num = atoi(token); 
    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;

    while ((token = strtok(NULL, delim)) != NULL) {
        num = atoi(token);
        token = strtok(NULL, delim);
        if (strncmp(token, "blue", 4) == 0) {
            if (num > max_blue) {
                max_blue = num;
            }
        } else if (strncmp(token, "green", 5) == 0) {
            if (num > max_green) {
                max_green = num;
            }
            
        } else if (strncmp(token, "red", 3) == 0) {
            if (num > max_red) {
                max_red = num;
            }
        }
    }

    return max_red*max_green*max_blue;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    int BUF_SIZE = 255;
    char line[255] = {0};
    int count = 0;
    bool success;
    int id;
    while (fgets(line, BUF_SIZE, input)) {
        success = true;
        id = parse_game(line, &success);
        if (success) {
            count += id;
        }
    }
    printf("Sum of game powers: %d\n", count);
    fclose(input);
    return 0;
}