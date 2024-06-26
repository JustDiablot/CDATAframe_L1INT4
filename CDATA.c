#include <stdlib.h>
#include <stdio.h>
#include "CDATA.h"

#include <bemapiset.h>

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

void display_limited_rows(DF *df, int row_limit) {
    if(df ==NULL) {
        printf("DataFrame does not exist or is empty\n");
        return;
    }
    int max_row=0;

    for(int i= 0;i< df->nb_columns;i++) {
        if(df->columns[i]->lsize > max_row) {
            max_row = df->columns[i]->lsize;
        }
    }
    max_row = (row_limit < max_row) ? row_limit : max_row;

    printf("Printing the first %d rows\n", max_row);
    for(int i=0; i<df->nb_columns;i++) {
        printf("%s\t", df->columns[i]->title);
    }
    printf("\n");
    for(int row = 0; row<max_row; row++) {
        for(int col = 0; col<df->nb_columns;col++) {
            if (row < df->columns[col]->lsize) {
                printf("%d\t", df->columns[col]->data[row]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
        }
    }


void display_limited_columns(DF *df, int limit) {
    if (!df || df->nb_columns == 0) {
        printf("DataFrame is empty or does not exist.\n");
        return;
    }
    int cols_to_print = (limit < df->nb_columns) ? limit : df->nb_columns;

    printf("Printing the first %d columns:\n", cols_to_print);
    for (int i = 0; i < cols_to_print; i++) {
        printf("%s\t", df->columns[i]->title);
    }
    printf("\n");

    int max_rows = 0;
    for (int i = 0; i < cols_to_print; i++) {
        if (df->columns[i]->lsize > max_rows) {
            max_rows = df->columns[i]->lsize;
        }
    }
    for (int row = 0; row < max_rows; row++) {
        for (int col = 0; col < cols_to_print; col++) {
            if (row < df->columns[col]->lsize) {
                printf("%d\t", df->columns[col]->data[row]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

void add_row_to_dataframe(DF *df, int *row_values) {
    for (int i = 0; i < df->nb_columns; i++) {
        insert_value(df->columns[i], row_values[i]);
    }
}
void delete_row_from_dataframe(DF *df, int row_index) {
    for (int i = 0; i < df->nb_columns; i++) {
        remove_value_at_index(df->columns[i], row_index);
    }
}

void add_row(DF *df) {
    int nb_columns = df->nb_columns;
    int *row_values = malloc(nb_columns * sizeof(int));
    if (row_values == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter %d values for the new row:\n", nb_columns);
    for (int i = 0; i < nb_columns; i++) {
        scanf("%d", &row_values[i]);
    }
    add_row_to_dataframe(df, row_values);
    free(row_values);
}
void delete_row(DF *df) {
    int row_index;
    printf("Enter the row index to delete: ");
    scanf("%d", &row_index);
    delete_row_from_dataframe(df, row_index);
}

void add_column_to_dataframe(DF *df, COLUMN *col) {
    if (df->nb_columns % REALOC_SIZE == 0) {
        COLUMN **new_columns = realloc(df->columns, (df->nb_columns + REALOC_SIZE) * sizeof(COLUMN *));
        if (new_columns == NULL) {
            printf("Memory reallocation failed\n");
            return;
        }
        df->columns = new_columns;
    }
    df->columns[df->nb_columns++] = col;
}
void delete_column_from_dataframe(DF *df, int column_index) {
    if (column_index < 0 || column_index >= df->nb_columns) {
        printf("Column index out of bounds\n");
        return;
    }
    delete_column(&df->columns[column_index]);
    for (int i = column_index; i < df->nb_columns - 1; i++) {
        df->columns[i] = df->columns[i + 1];
    }
    df->nb_columns--;

    // Shrink the array if needed
    if ((df->nb_columns % REALOC_SIZE) == 0 && df->nb_columns > 0) {
        COLUMN **new_columns = realloc(df->columns, df->nb_columns * sizeof(COLUMN *));
        if (new_columns == NULL) {
            printf("Memory reallocation failed\n");
            return;
        }
        df->columns = new_columns;
    }
}
void add_column(DF *df) {
    char column_title[100];
    printf("Enter column title: ");
    scanf("%99s", column_title);

    COLUMN *new_column = create_column(column_title);
    if (new_column == NULL) {
        printf("Failed to create new column.\n");
        return;
    }

    add_column_to_dataframe(df, new_column);
    printf("Column added successfully.\n");
}

void delete_column_use(DF *df) {
    int column_index;
    printf("Enter the index of the column to delete: ");
    scanf("%d", &column_index);

    delete_column_from_dataframe(df, column_index);
    printf("Column deleted successfully.\n");
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
    df->columns[df->nb_columns+1]->lsize=df->columns[df->nb_columns+1]->lsize+1;

}

void access_or_replace_cell_value(DF *df, int row, int col) {
    if (col < 0 || col >= df->nb_columns || row < 0 || row >= df->columns[col]->lsize) {
        printf("Row or column index out of bounds.\n");
        return;
    }

    int current_value = df->columns[col]->data[row];
    printf("Current value at row %d, column %d: %d\n", row, col, current_value);

    char choice;
    printf("Do you want to replace this value? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int new_value;
        printf("Enter new value: ");
        scanf("%d", &new_value);
        df->columns[col]->data[row] = new_value;
        printf("Value updated successfully.\n");
    }
}

void save_as_csv(DF *df) {
    FILE *f = fopen("dataframe.csv", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < df->nb_columns; i++) {
        fprintf(f, "%s", df->columns[i]->title);
        if (i != df->nb_columns - 1) {
            fprintf(f, ";");
        }
    }
    fprintf(f, "\n");
    int max_rows = 0;
    for (int i = 0; i < df->nb_columns; i++) {
        if (df->columns[i]->lsize > max_rows) {
            max_rows = df->columns[i]->lsize;
        }
    }
    for (int row = 0; row < max_rows; row++) {
        for (int col = 0; col < df->nb_columns; col++) {
            if (row < df->columns[col]->lsize) {
                fprintf(f, "%d", df->columns[col]->data[row]);
            } else {
                fprintf(f, " ");
            }
            if (col != df->nb_columns - 1) {
                fprintf(f, ";");
            }
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

void getch() {
    printf("\n\nPress ENTER to continue...\n");
    getchar();
    getchar();
}