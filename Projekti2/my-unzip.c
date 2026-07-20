  GNU nano 7.2                                     my-unzip.c
//----- My-Unzip -----
// Part of project 2, unix utilities

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Makes sure at leat one file is provided
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count; // repeat char amount
    char character; // the char that repeats

    // Goes through all the files
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("my-unzip: cannot open file\n");
            exit(1);
        }

        // Reads the count and character from the binary file
        while (fread(&count, sizeof(int), 1, file) == 1) {
            if (fread(&character, sizeof(char), 1, file) != 1) {
                fclose(file);
                exit(1);
            }

            // Prints the character for 'count' times
            for (int j = 0; j < count; j++) {
                printf("%c", character);
            }
        }
        fclose(file);
    }
    return 0;
}

// ---- End of file ----
