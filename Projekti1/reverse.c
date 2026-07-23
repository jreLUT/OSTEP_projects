#define _GNU_SOURCE // For getline() as its a GNU extension not a standard C function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Library imports ^^^^

typedef struct Node {
    char *row;
    struct Node *next;
} Node;

void freeLinkedList(Node *head);


int main(int argc, char const *argv[])
{
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    // Input and output file pointers
    FILE *file_in = stdin;
    FILE *file_out = stdout;

    // If the user gave at least one argument try to open the input file
    if (argc > 1) {
        if ((file_in = fopen(argv[1], "r")) == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }

    // If the user gave two arguments try to open the output file too (file name is first argument)
    if (argc == 3) {
        if (strcmp(argv[2], argv[1]) == 0) {
            fprintf(stderr, "Input and output file must differ\n");
            if (file_in != stdin) {
                fclose(file_in);
            }
            exit(1);
        }
    

        if ((file_out = fopen(argv[2], "w")) == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            if (file_in != stdin) {
                fclose(file_in);
            }
            exit(1);
        }
    }
    // The head of the linked list and a pointer to the current row
    Node *head = NULL;
    char *buffer = NULL;

    // The size of the row and the number of chars read
    // size_t makes sure we have enough space for the row and ssize_t makes sure we can store the number of chars read
    size_t size = 0;
    ssize_t read;

    // Read each row from the input file and add it to the linked list
    // Getline allocates memory for the row itself and reallocates it as needed
    while ((read = getline(&buffer, &size, file_in)) != -1) {

        // Creates a new node and adds it to the head of our linked list
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) { // If mallocs fails free and close everything returning 1
            fprintf(stderr, "malloc failed\n");
            free(buffer);
            freeLinkedList(head);
            if (file_in != stdin) {
                fclose(file_in);
            }
            if (file_out != stdout) {
                fclose(file_out);
            }
            exit(1);
        }

        // Allocates memory for the row in newNode
        newNode->row = malloc((read + 1) * sizeof(char));
        if (newNode->row == NULL) {
            fprintf(stderr, "error: malloc failed\n");
            free(newNode);
            free(buffer);
            freeLinkedList(head);
            if (file_in != stdin) {
                fclose(file_in);
            }
            if (file_out != stdout) {
                fclose(file_out);
            }
            exit(1);
        }

        // Copy the row into a new node
        strcpy(newNode->row, buffer);

        // Adds the new node to the head of our list
        newNode->next = head;
        head = newNode;
        
    }
    Node *ptr = head;
    while (ptr != NULL) {
        fprintf(file_out, "%s", ptr->row);
        ptr = ptr->next;
    }

    // Close files, if they were opened in the first place
    if (file_in != stdin) {
        fclose(file_in);
    }
    if (file_out != stdout) {
        fclose(file_out);
    }
    free(buffer);
    freeLinkedList(head);
    
    return 0;
    
    
}

// Frees the linked list and all of its nodes
void freeLinkedList(Node *head) {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current->row); 
        free(current);
        current = next;
    }
}
// EOF
