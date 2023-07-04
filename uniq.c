//
// Created by Russ Sobti on 4/9/23.
// The uniq program is a common utility available in many Unix installations.
// This program echoes (to stdout) its input,
// but will print only a single instance of consecutive matching lines.
//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Variables:
    // 512 is the max length of a line
    char prev_line[512] = "";
    char curr_line[512];
    // Open the file
    FILE *fp;
    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
    }
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    // Loop through and read each line
    while (fgets(curr_line, 512, fp) != NULL) {
        // If the current line is not the same as the previous line
        if (strcmp(curr_line, prev_line) != 0) {
            // Print the current line
            printf("%s", curr_line);
            // Set the previous line to the current line
            strcpy(prev_line, curr_line);
        }
    }
    // Close the file
    fclose(fp);
    // print a newline if there is no newline at the end of the file
    if (curr_line[strlen(curr_line) - 1] != '\n') {
        printf("\n");
    }
//    printf("\n");

    return 0;

}