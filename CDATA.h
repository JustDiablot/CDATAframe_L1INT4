#ifndef CDATAFRAME_CDATA_H
#define CDATAFRAME_CDATA_H
#include "column.h"

typedef struct {
    COLUMN **columns; // Array of column pointers
    int nb_columns; // Number of columns
} DF;

DF *create_empty_dataframe(int num_columns);
void fill_dataframe(DF *df, char **titles, int num_columns);
void print_dataframe(DF *df);
void auto_fill_dataframe(DF *df, int num_rows);
void display_limited_rows(DF *df, int row_limit);
void display_limited_columns(DF *df, int limit);
void add_row_to_dataframe(DF *df, int *row_values);
void delete_row_from_dataframe(DF *df, int row_index);
void add_row(DF *df);
void delete_row(DF *df);
void add_column_to_dataframe(DF *df, COLUMN *col);
void delete_column_from_dataframe(DF *df, int column_index);
void add_column(DF *df);
void delete_column(DF *df);
void save_as_csv(DF *df);


#endif //CDATAFRAME_CDATA_H
