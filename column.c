#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include <unistd.h>
#include "CDATA.h"
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
int remove_value_at_index(COLUMN *col, int index) {
    if (index < 0 || index >= col->lsize) {
        printf("Index out of bounds\n");
        return -1;
    }


    for (int i = index; i < col->lsize - 1; i++) {
        col->data[i] = col->data[i + 1];
    }
    col->lsize--;


    if (col->psize - col->lsize > REALOC_SIZE) {
        int new_size = col->lsize + REALOC_SIZE;
        int *new_data = realloc(col->data, new_size * sizeof(int));
        if (new_data == NULL) {
            printf("Memory reallocation error\n");
            return -1;
        }
        col->data = new_data;
        col->psize = new_size;
    }

    return 0;
}

void print_titles(COLUMN **columns, int nb_columns) {
    for (int i = 0; i < nb_columns; i++) {
        printf("%d - %s\n", i, columns[i]->title);
    }
}

void change_column_name(COLUMN *col, const char *new_name) {
    if (col->title) {
        free(col->title);
    }
    col->title = (char *)malloc(strlen(new_name) + 1);
    if (col->title) {
        strcpy(col->title, new_name);
    } else {
        printf("Memory allocation failed for new column name.\n");
    }
}
void rename_column(DF *df) {
    int column_index;
    char new_name[100];

    printf("Enter the index of the column to rename: ");
    scanf("%d", &column_index);
    if (column_index < 0 || column_index >= df->nb_columns) {
        printf("Column index out of bounds.\n");
        return;
    }
    printf("Enter the new name for the column: ");
    scanf("%99s", new_name);
    change_column_name(df->columns[column_index], new_name);
    printf("Column name changed successfully.\n");
}

