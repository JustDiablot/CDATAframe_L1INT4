#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "column.h"
#include "CDATA.h"

//only way we found to compile C files on Windows PCs
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    printf("\t\tWelcome to the CDATAFrame\n\tBy Oscar Masduppuy & Auffray Valentin\n\n");
    
    char *titles[] = {"Big", "Column", "Bebou"};
    int num_columns = sizeof(titles) / sizeof(titles[0]);

    DF *df = create_empty_dataframe(num_columns); // Renamed to DF
    fill_dataframe(df, titles, num_columns);

    insert_value(df->columns[0], 1);
    insert_value(df->columns[0], 17);
    insert_value(df->columns[0], 24);
    insert_value(df->columns[0], 16);
    insert_value(df->columns[0], 72);
    insert_value(df->columns[1], 1234);
    insert_value(df->columns[2], 167);

    print_dataframe(df); // Renamed to DF

    for (int i = 0; i < num_columns; i++) {
        free(df->columns[i]->title);
        free(df->columns[i]->data);
        free(df->columns[i]);
    }
    free(df->columns);
    free(df);

    return 0;
}

