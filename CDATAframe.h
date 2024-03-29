#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "CDATAframe.c"
#define REALOC_SIZE 256

typedef struct {
    char* title;
    int lsize;
    int Psize;
    int data;
} COLUMN;

int length(char* str);

COLUMN create_column(char* title);

#endif // CDATAFRAME_H