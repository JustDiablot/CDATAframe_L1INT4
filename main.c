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
    int sum = 0;    int sum1 = 0;    int sum2 = 0;    int sum3 = 0;    int col_index = 0;    int col_index1 = 0;    int col_index2 = 0;    int col_index3 = 0;    int min = 0;    int max = 0;    int min1 = 0;    int max1 = 0;    int count = 0;    int l = 0;    int j = 0;

    printf("\tWelcome to Oscar's and Valentin's Project !\n");
    while (start == 0) {
        while (choice < 1 || choice > 6) {
            printf("Choose your option :\n");
            printf("1 - Create a new Data frame\n");
            printf("2 - Fill the Data frame\n");
            printf("3 - Display the Data frame\n");
            printf("4 - Modify the Data frame\n");
            printf("5 - Analyze the Data frame\n");
            printf("6 - Operations\n");
            printf("7 - Save the Data frame as a CSV file\n");
            printf("8 - Exit\n");
            scanf("%d", &choice);


        }
        switch (choice) {
            case 1:
                clear();
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
                clear();
                new_choice = 0;
            while (new_choice < 1 || new_choice > 2) {
                printf("1 - Fill the Data Frame\n");
                printf("2 - Fill the Data Frame with random values\nChoose your option :\n");
                scanf("%d", &new_choice);
            }
            switch (new_choice) {
                case 1:
                    clear();
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
                    clear();
                    auto_fill_dataframe(df, 10);
                printf("Auto Filling has been done.\n");
                break;
                default:
                    printf("ERROR\n");
                break;
            }
            break;

            case 3:
                clear();
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
                            clear();
                            print_dataframe(df);
                            break;
                        case 2:
                            clear();
                            printf("Enter the number of rows to display: ");
                            scanf("%d", &nb_row);
                            display_limited_rows(df, nb_row);
                            break;

                        case 3:
                            clear();
                            printf("Enter the number of columns to display: ");
                            scanf("%d", &limit);
                            display_limited_columns(df, limit);
                            break;

                        case 4:
                            clear();
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
                clear();
                if (df != NULL) {
                    printf("1 - Add a row of values to the Dataframe"
                           "\n2 - Delete a row of values from the Dataframe"
                           "\n3 - Add a column to the Dataframe"
                           "\n4 - Delete a column from the Dataframe"
                           "\n5 - Rename the title of a column in the Dataframe"
                           "\n6 - Replace a value in the Dataframe cell using its row and column number"
                           "\nChoose your option :\n");
                    scanf("%d",&lechoix);
                    switch(lechoix){
                        case 1:
                            clear();
                            add_row(df);
                            printf("Added a new row successfully\n");
                            break;
                        case 2:
                            clear();
                            delete_row(df);
                            printf("Deleted the row succesfully\n");
                            break;
                        case 3:
                            clear();
                            add_column(df);
                            printf("Added a column successfully\n");
                            break;
                        case 4:
                            clear();
                            delete_column_use(df);
                            printf("Deleted the column successfully\n");
                            break;
                        case 5:
                            clear();
                            rename_column(df);
                            printf("Column name changed successfully.\n");

                            break;
                        case 6:
                            clear();
                            int row, col;
                            printf("Enter row number: ");
                            scanf("%d", &row);
                            printf("Enter column number: ");
                            scanf("%d", &col);
                            access_or_replace_cell_value(df, row, col);
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
                clear();
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
                            clear();
                            printf("The number of rows is %d\n", df->columns[0]->lsize);
                            break;
                        case 2:
                            clear();
                            printf("The number of columns is %d\n", df->nb_columns);
                            break;
                        case 3:
                            clear();
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
                            clear();
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
                            clear();
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
                clear();
                if (df != NULL){
                    printf("1 - Sum of all the values in the Dataframe\n");
                    printf("2 - Average of all the values in the Dataframe\n");
                    printf("3 - average of all the values in a specified column\n");
                    printf("4 - Sum of all the values in a specified column\n");
                    printf("5 - Maximum value in the Dataframe\n");
                    printf("6 - Minimum value in the Dataframe\n");
                    printf("7 - Maximum value in a specified column\n");
                    printf("8 - Minimum value in a specified column\n");
                    printf("Choose your option :\n");
                    scanf("%d", &l);
                    switch (l) {
                        case 1:
                            clear();
                            sum = 0;
                            for (i = 0; i < df->nb_columns; i++) {
                                for (int j = 0; j < df->columns[i]->lsize; j++) {
                                    sum += df->columns[i]->data[j];
                                }
                            }
                            printf("The sum of all the values in the Dataframe is %d\n", sum);
                            break;
                        case 2:
                            clear();
                            sum1 = 0;
                            count = 0;
                            for (i = 0; i < df->nb_columns; i++) {
                                for (int j = 0; j < df->columns[i]->lsize; j++) {
                                    sum1 += df->columns[i]->data[j];
                                    count++;
                                }
                            }
                            printf("The average of all the values in the Dataframe is %f\n", (float) sum1 / count);
                            break;
                        case 3:
                            clear();
                            printf("Enter the column index: ");
                            scanf("%d", &col_index);
                            if (col_index < 0 || col_index >= df->nb_columns) {
                                printf("Invalid column index.\n");
                                break;
                            }
                            sum2 = 0;
                            for (i = 0; i < df->columns[col_index]->lsize; i++) {
                                sum2 += df->columns[col_index]->data[i];
                            }
                            printf("The average of all the values in column %d is %f\n", col_index,
                                   (float) sum2 / df->columns[col_index]->lsize);
                            break;
                        case 4:
                            clear();
                            printf("Enter the column index: ");
                            col_index1;
                            scanf("%d", &col_index1);
                            if (col_index1 < 0 || col_index1 >= df->nb_columns) {
                                printf("Invalid column index.\n");
                                break;
                            }
                            sum3 = 0;
                            for (i = 0; i < df->columns[col_index1]->lsize; i++) {
                                sum3 += df->columns[col_index1]->data[i];
                            }
                            printf("The sum of all the values in column %d is %d\n", col_index1, sum3);
                            break;
                        case 5:
                            clear();
                            max = df->columns[0]->data[0];
                            for (i = 0; i < df->nb_columns; i++) {
                                for (j = 0; j < df->columns[i]->lsize; j++) {
                                    if (df->columns[i]->data[j] > max) {
                                        max = df->columns[i]->data[j];
                                    }
                                }
                            }
                            printf("The maximum value in the Dataframe is %d\n", max);
                            break;
                        case 6:
                            clear();
                            min = df->columns[0]->data[0];
                            for (i = 0; i < df->nb_columns; i++) {
                                for (j = 0; j < df->columns[i]->lsize; j++) {
                                    if (df->columns[i]->data[j] < min) {
                                        min = df->columns[i]->data[j];
                                    }
                                }
                            }
                            printf("The minimum value in the Dataframe is %d\n", min);
                            break;
                        case 7:
                            clear();
                            printf("Enter the column index: ");
                            scanf("%d", &col_index2);
                            if (col_index2 < 0 || col_index2 >= df->nb_columns) {
                                printf("Invalid column index.\n");
                                break;
                            }
                            max1 = df->columns[col_index2]->data[0];
                            for (i = 0; i < df->columns[col_index2]->lsize; i++) {
                                if (df->columns[col_index2]->data[i] > max1) {
                                    max1 = df->columns[col_index2]->data[i];
                                }
                            }
                            printf("The maximum value in column %d is %d\n", col_index2, max1);
                            break;
                        case 8:
                            clear();
                            printf("Enter the column index: ");
                            scanf("%d", &col_index3);
                            if (col_index3 < 0 || col_index3 >= df->nb_columns) {
                                printf("Invalid column index.\n");
                                break;
                            }
                            min1 = df->columns[col_index3]->data[0];
                            for (i = 0; i < df->columns[col_index3]->lsize; i++) {
                                if (df->columns[col_index3]->data[i] < min1) {
                                    min1 = df->columns[col_index3]->data[i];
                                }
                            }
                            printf("The minimum value in column %d is %d\n", col_index3, min1);
                            break;
                        default:
                            printf("ERROR\n");
                            break;

                    }
                }
                else
                {
                    printf("Data frame is not created yet.\n");
                }
                break;

            case 7:
                clear();
                if (df != NULL) {
                    save_as_csv(df);
                    printf("Data frame has been saved to dataframe.csv\n");
                } else {
                    printf("Data frame is not created yet.\n");
                }
                break;
            case 8:
                clear();
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
