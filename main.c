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
    int lechoix=0;
    int m=0;

    printf("\tWelcome to Oscar's and Valentin's Project !\n");
    while (start == 0) {
        while (choice < 1 || choice > 6) {
            printf("Choose your option :\n");
            printf("1 - Create a new Data frame\n");
            printf("2 - Fill the Data frame\n");
            printf("3 - Display the Data frame\n");
            printf("4 - Modify the Data frame\n");
            printf("5 - Analyze the Data frame\n");
            printf("6 - Save the Data frame as a CSV file\n");
            printf("7 - Exit\n");
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
                printf("2 - Fill the Data Frame with random values\nChoose your option :\n");
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
                    int var = 0;
                    int limit =0;
                    printf("1 - Display the entire Data frame\n");
                    printf("2 - Display a part of the Data frame rows\n");
                    printf("3 - Display a part of the Data frame columns\n");
                    printf("4 - Display the column names\n");
                    printf("Choose your option :\n");
                    scanf("%d", &var);
                    switch (var) {
                        case 1:
                            print_dataframe(df);
                            break;
                        case 2:
                            printf("Enter the number of rows to display: ");
                            scanf("%d", &nb_row);
                            display_limited_rows(df, nb_row);
                            break;

                        case 3:
                            printf("Enter the number of columns to display: ");
                            scanf("%d", &limit);
                            display_limited_columns(df, limit);
                            break;

                        case 4:
                            print_titles(df->columns, df->nb_columns);
                            break;

                        default:
                            printf("ERROR\n");
                            break;
                    }
                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;

            case 4:
                if (df != NULL) {
                    printf("1 - Add a row of values to the Dataframe"
                           "\n2 - Delete a row of values from the Dataframe"
                           "\n3 - Add a column to the Dataframe"
                           "\n4 - Delete a column from the Dataframe"
                           "\n5 - Rename the title of a column in the Dataframe"
                           "\n6 - Check the existence of a value in the Dataframe"
                           "\n7 - Replace a value in the Dataframe cell using its row and column number\nChoose your option :\n");
                    scanf("%d",&lechoix);
                    switch(lechoix){
                        case 1:
                            add_row(df);
                            printf("Added a new row successfully\n");
                            break;
                        case 2:
                            delete_row(df);
                            printf("Deleted the row succesfully\n");
                            break;
                        case 3:
                            add_column(df);
                            printf("Added a column successfully\n");
                            break;
                        case 4:
                            delete_column_use(df);
                            printf("Deleted the column successfully\n");
                            break;
                        case 5:

                            break;
                        case 6:

                            break;
                        case 7:

                            break;


                        default:
                            printf("ERROR\n");
                            break;
                    }

                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;

            case 5:
                if (df != NULL) {
                    printf("1 - Display the number of rows\n");
                    printf("2 - Display the number of columns\n");
                    printf("3 - Display the number of cells equal to x\n");
                    printf("4 - Display the number of cells containing a value greater than x\n");
                    printf("5 - Display the number of cells containing a value less than x\n");
                    printf("Choose your option :\n");
                    scanf("%d", &m);
                    switch (m){
                        case 1:
                            printf("The number of rows is %d\n", df->columns[0]->lsize);
                            break;
                        case 2:
                            printf("The number of columns is %d\n", df->nb_columns);
                            break;
                        case 3:
                            printf("Enter the value of x: ");
                            int x;
                            scanf("%d", &x);
                            int count = 0;
                            for (i = 0; i < df->nb_columns; i++) {
                                for (int j = 0; j < df->columns[i]->lsize; j++) {
                                    if (df->columns[i]->data[j] == x) {
                                        count++;
                                    }
                                }
                            }
                            printf("The number of cells equal to %d is %d\n", x, count);
                            break;
                        case 4:
                            printf("Enter the value of x: ");
                            int x1;
                            scanf("%d", &x1);
                            int count1 = 0;
                            for (i = 0; i < df->nb_columns; i++) {
                                for (int j = 0; j < df->columns[i]->lsize; j++) {
                                    if (df->columns[i]->data[j] > x1) {
                                        count1++;
                                    }
                                }
                            }
                            printf("The number of cells containing a value greater than %d is %d\n", x1, count1);
                            break;
                        case 5:
                            printf("Enter the value of x: ");
                            int x2;
                            scanf("%d", &x2);
                            int count2 = 0;
                            for (i = 0; i < df->nb_columns; i++) {
                                for (int j = 0; j < df->columns[i]->lsize; j++) {
                                    if (df->columns[i]->data[j] < x2) {
                                        count2++;
                                    }
                                }
                            }
                            printf("The number of cells containing a value less than %d is %d\n", x2, count2);
                            break;
                        default:
                            printf("ERROR\n");
                            break;
                    }
                } else {
                    printf("Data frame is not created yet.\n");
                }
            break;
            case 6:
                if (df != NULL) {
                    save_as_csv((df));
                    printf("Data frame has been saved to dataframe.csv\n");
                } else {
                    printf("Data frame is not created yet.\n");
                }
            case 7:
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
