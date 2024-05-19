#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    if (strcmp(parameter, "-c") == 0) {
        fseek(file, 0, SEEK_END);
        count = ftell(file);
    } else if (strcmp(parameter, "-w") == 0) {
        char prev = ' ';
        char current;
        while ((current = fgetc(file)) != EOF) {
            if (current == ' ' || current == '\n' || current == '\t') {
                if (prev != ' ' && prev != '\n' && prev != '\t') {
                    count++;
                }
            }
            prev = current;
        }
        if (prev != ' ' && prev != '\n' && prev != '\t') {
            count++;
        }
    } else {
        printf("Invalid parameter. Please use -c or -w.\n");
        return 1;
    }

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("µ¥´ÊÊý£º%d\n", count);
    }

    return 0;
}

