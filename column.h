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

#endif // CDATAFRAME_H