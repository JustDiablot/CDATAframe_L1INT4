#include <stdlib.h>
#include <stdio.h>
#include "CDATA.h"
#include "column.h"

DF *create_empty_dataframe(int nb_columns) {
    // Allocate memory for the DataFrame structure
    DF *df = (DF *)malloc(sizeof(DF));
    df->columns = (COLUMN **)malloc(nb_columns * sizeof(COLUMN *));
    df->nb_columns = nb_columns;

    // Initialize each column pointer to NULL
    for (int i = 0; i < nb_columns; i++) {
        df->columns[i] = NULL;
    }

    return df;
}

void fill_dataframe(DF *df, char **titles, int nb_columns) {
    for (int i = 0; i < nb_columns; i++) {
        // Create a new column with the provided title
        df->columns[i] = create_column(titles[i]);
    }
}

void print_dataframe(DF *df) {
    printf("CDATAframe:\n");
    printf("index\t");
    for (int i = 0; i < df->nb_columns; i++) {
        printf("%s\t", df->columns[i]->title);
    }
    printf("\n");

    int max_rows = 0;
    for (int i = 0; i < df->nb_columns; i++) {
        if (df->columns[i]->lsize > max_rows) {
            max_rows = df->columns[i]->lsize;
        }
    }

    for (int i = 0; i < max_rows; i++) {
        printf("%d\t", i);
        for (int j = 0; j < df->nb_columns; j++) {
            if (i < df->columns[j]->lsize) {
                printf("%d\t", df->columns[j]->data[i]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

void auto_fill_dataframe(DF *df, int nb_rows) {
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < df->nb_columns; j++) {
            insert_value(df->columns[j], rand() % 100);
        }
    }
}