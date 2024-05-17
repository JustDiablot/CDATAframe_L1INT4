#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include <unistd.h>
#define REALOC_SIZE 256

//4.1.1

COLUMN *create_column(char *title) {

    // Allocate memory for the column
    COLUMN *new_column = (COLUMN *)malloc(sizeof(COLUMN));
    new_column->title = (char *)malloc(strlen(title) + 1);
    strcpy(new_column->title, title);

    // Initialize other attributes
    new_column->data = NULL;
    new_column->lsize = 0;
    new_column->psize = 0;

    return new_column;
}

//4.1.2

int insert_value(COLUMN *c, int value) {

    // Check if physical size is NULL or used up
    if (c->data == NULL || c->lsize >= c->psize) {
        // Trigger reallocation of memory
        int new_psize = c->psize + REALOC_SIZE;
        int *new_data = (int *)realloc(c->data, new_psize * sizeof(int));
        c->data = new_data;
        c->psize = new_psize;
    }

    // Insert the value into the column
    c->data[c->lsize++] = value;
    return 1; // Return 1 indicating success
}

//4.1.3

void print_col(COLUMN *c) {
    printf("Index\t%s\n", c->title);
    for (int i = 0; i < c->lsize; i++) {
        printf("[%d]\t%d\n", i, c->data[i]);
    }
}

//4.1.4

void delete_column(COLUMN **c) {

    free((*c)->data);
    free((*c)->title);
    free(*c);

    // Set the pointer to NULL for optimization purposes
    *c = NULL;
}

void clear() {
    printf("%c2J", 27);
}



