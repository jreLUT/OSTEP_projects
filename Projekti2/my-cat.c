// ---- My-Cat ----
// ---- Part of Unix Utilities project 2 ----

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // If no files, end the program
    if (argc < 2) {
        return 0;
    }

    // Goes through all the files
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        // Error handling
        if (file == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }
        // Reads up to 1024 char and simply prints out the contents
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
    }

    return 0;
}

// ---- End of My-Cat ----
