#include <stdio.h>
#include <stdlib.h>
#include "CDATAframe.h"

//4.1.1 columns
#define REALOC_SIZE 256

int length(char* str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

COLUMN create_column(char* title){
    COLUMN c;
    for (int i = 0; i < length(title); i++){
        c.title[i] = title[i];
    }
    return c;
}

//4.1.2 inserting a value in a column

