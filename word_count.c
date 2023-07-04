//
// Created by Russ Sobti on 4/9/23.
//
//Write a program (with main function in a file named word_count.c)
// that takes a single (optional) command-line argument specifying a file name.
// The program must read the contents of the file (read from stdin if no file is specified) and print
// the number of lines, number of words, and number of bytes.
// Print these values as integers, with a space between each integer followed by a single newline character.

#include <stdio.h>
int main(int argc, char *argv[]) {
    // Variables to be returned:
    int lines = 0;
    int words = 0;
    int bytes = 0;
    int c = 0;  // current character
    int inword = 0; // 1 if in a word, 0 if not
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

    // Loop through and read each character
    while (1) { // while not end of file
        c = fgetc(fp); // get the next character
        if (c == EOF) { // if end of file
            break; // break out of the loop
        }
        bytes++; // increment bytes
        char character = (char) c; // cast c to a char
        if (character == '\n' || character == '\r') { // if newline or carriage return
            lines++; // increment lines
            inword = 0; // not in a word
        }
        else if (character == ' ' || character == '\t') { // if space or tab
            inword = 0; // not in a word
        }
        else if (inword == 0) { // if there's a character that isn't a newline or space and not in a word
            words++; // increment words
            inword = 1; // in a word
        }


    }
    // Print the results
    printf("%d %d %d", lines, words, bytes);
    // Close the file
    fclose(fp);
    // print a newline
    printf("\n");
    return 0;
}