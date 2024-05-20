#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "column.h"
#include "CDATA.h"


int main() {
    int start = 0;
    int choice = 0;
    int nb_col = 0, nb_row = 0, i = 0;
    int new_choice = 0;
    char **titles = NULL;
    DF *df = NULL;

    printf("\tWelcome to Oscar's and Valentin's Project !\n");
    while (start == 0) {
        while (choice < 1 || choice > 6) {
            printf("Choose your option :\n");
            printf("1 - Create a new Data frame\n");
            printf("2 - Fill the Data frame\n");
            printf("3 - Display the Data frame\n");
            printf("4 - Modify the Data frame\n");
            printf("5 - Analyze the Data frame\n");
            printf("6 - Exit\n");
            scanf("%d", &choice);


        }
        switch (choice) {
            case 1:
                printf("Enter the number of columns :\n");
            scanf("%d", &nb_col);
            df = create_empty_dataframe(nb_col);

            titles = (char **)malloc(nb_col * sizeof(char *));
            printf("Enter the name of your columns :\n");
            for (i = 0; i < nb_col; i++) {
                titles[i] = (char *)malloc(100 * sizeof(char)); // Assuming max column name length is 100
                printf("Column %d name: ", i + 1);
                scanf("%s", titles[i]);
            }
            fill_dataframe(df, titles, nb_col);
            printf("Your Data Frame has been created\n");
            break;

            case 2:
                new_choice = 0;
            while (new_choice < 1 || new_choice > 2) {
                printf("1 - Fill the Data Frame\n");
                printf("2 - Fill the Data Frame with random values\n");
                scanf("%d", &new_choice);
            }
            switch (new_choice) {
                case 1:
                    printf("Which column do you want to fill (0 to %d):\n", nb_col-1);
                int col_index;
                scanf("%d", &col_index);
                if (col_index < 0 || col_index >= nb_col) {
                    printf("Invalid column index.\n");
                    break;
                }
                printf("How many rows do you want to fill :\n");
                scanf("%d", &nb_row);
                for (i = 0; i < nb_row; i++) {
                    int value;
                    printf("Enter value for row %d: ", i + 1);
                    scanf("%d", &value);
                    insert_value(df->columns[col_index], value);
                }
                printf("The values has been inserted !\n");
                break;
                case 2:
                    auto_fill_dataframe(df, 10);
                printf("Auto Filling has been done.\n");
                break;
                default:
                    printf("ERROR\n");
                break;
            }
            break;

            case 3:
                if (df != NULL) {
                    print_dataframe(df);
                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;

            case 4:
                if (df != NULL) {
                    int new_choice=0;
                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;

            case 5:
                if (df != NULL) {
                    // Implement your logic to analyze the DataFrame
                    printf("Analyze the Data frame functionality is not yet implemented.\n");
                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;

            case 6:
                printf("Exiting...\n");
            start = 1;
            break;

            default:
                printf("ERROR\n");
            break;
        }
        choice = 0; // Reset choice to re-enter the menu
    }

    // Free memory
    if (df != NULL) {
        for (i = 0; i < nb_col; i++) {
            delete_column(&(df->columns[i]));
        }
        free(df->columns);
        free(df);
    }
    if (titles != NULL) {
        for (i = 0; i < nb_col; i++) {
            free(titles[i]);
        }
        free(titles);
    }

    return 0;
}
//only way we found to compile C files on Windows PCs
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    printf("\t\tWelcome to the CDATAFrame\n\tBy Oscar Masdupuy & Auffray Valentin\n\n");

    char *titles[] = {"Big", "Column", "Bebou"};
    int num_columns = sizeof(titles) / sizeof(titles[0]);

    DF *df = create_empty_dataframe(num_columns); // Renamed to DF
    fill_dataframe(df, titles, num_columns);

    /*insert_value(df->columns[0], 1);
    insert_value(df->columns[0], 17);
    insert_value(df->columns[0], 24);
    insert_value(df->columns[0], 16);
    insert_value(df->columns[0], 72);
    insert_value(df->columns[1], 1234);
    insert_value(df->columns[2], 167);
    */
    auto_fill_dataframe(df, 5);
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


/*1. Filling
    • Creation of an empty CDataframe
    • Filling in the CDataframe with user input
    • Hard filling of the CDataframe
2. Displaying
    • Display the entire CDataframe
    • Display a part of the CDataframe rows according to a user-provided limit
    • Display a part of the columns of the CDataframe according to a limit supplied by the user
3. Usual operations
    • Add a row of values to the CDataframe
    • Delete a row of values from the CDataframe
    • Add a column to the CDataframe
    • Delete a column from the CDataframe
    • Rename the title of a column in the CDataframe
    • Check the existence of a value (search) in the CDataframe
    • Access/replace the value in a CDataframe cell using its row and column number
    • Display column names
4. Analysis and statistics
    • Display the number of rows
    • Display the number of columns
    • Display the number of cells equal to x (x given as parameter)
    • Display the number of cells containing a value greater than x (x given as a parameter)
    • Display the number of cells containing a value less than x(x given as parameter)*/