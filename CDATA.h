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


#endif //CDATAFRAME_CDATA_H