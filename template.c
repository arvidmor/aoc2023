#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    int BUF_SIZE = 255;
    char line[BUF_SIZE];
    while (fgets(line, BUF_SIZE, input)) {
    }
    fclose(input);
    return 0;
}