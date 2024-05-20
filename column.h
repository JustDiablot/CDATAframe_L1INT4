#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#define REALOC_SIZE 256

typedef struct {
    char* title;
    int lsize;              //look at void* notion
    int psize;
    int *data;
} COLUMN;



COLUMN *create_column(char* title);
int insert_value(COLUMN *c, int value);
void print_col(COLUMN *c);
void delete_column(COLUMN **col);
void clear();
int remove_value_at_index(COLUMN *col, int index);
void print_titles(COLUMN **columns, int nb_columns);


#endif // CDATAFRAME_H