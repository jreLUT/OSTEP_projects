// ---- My-Zip ----
// Part of project 2, Unix Utilities

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Makes sure at least one file is given
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0; // run length
    int character; // the char being read
    int previous_char = EOF; // previous char

    // Loops through all file args given
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("my-zip: cannot open file\n");
            exit(1);
        }
        // Reads the file character by character until the end of the file
        while ((character = fgetc(file)) != EOF) {
            if (previous_char == EOF) {
                previous_char = character;
                count = 1;
            }
              // If the same chracters appears again, count++
            else if (character == previous_char) {
                count++;
            } else { // Else we write the sequence to stdout and start a new one
                fwrite(&count, sizeof(int), 1, stdout);
                fputc(previous_char, stdout);
                count = 1;
                previous_char = character;
            }

      }
    fclose(file);
    }
    // For the last character
    if (previous_char != EOF) {
        fwrite(&count, sizeof(int), 1, stdout);
        fputc(previous_char, stdout);
    }
    return 0;
}


// ---- End of My-Zip ----
