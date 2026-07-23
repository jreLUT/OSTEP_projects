// ---- My-Grep ----
// Part of project 2, Unix Utilities

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchInFile(FILE *file, char *searchWord) {
    char *row = NULL;
    size_t size = 0;
    ssize_t read;
    // REads one line at the time even if the line is extremely long, allocating memory as needed
    while ((read = getline(&row, &size, file)) != -1) {
        if (strstr(row, searchWord) != NULL) { // strstr() returns a pointer to the first occurence of the >
            printf("%s", row);
        }
    }
    free(row);
}



int main(int argc, char *argv[]) {
  // Makes sure at least the search arg is given
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    char *searchWord = argv[1];
    // Stdin is used if no files are given
    if (argc == 2) {
        searchInFile(stdin, searchWord);
        return 0;
    }
    else {

        // Goes through every file and calls searchInFile()
        for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
          // Error handling
            if (file == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
            }
            searchInFile(file, searchWord);
            fclose(file);

        }
    }
    return 0;

}

// ---- End of My-Grep ----
