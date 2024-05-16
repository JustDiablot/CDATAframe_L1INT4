#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "column.h"
#include "CDATA.h"

int main{
    bool start = True;
    int choice = 0;
    printf("\tWelcome to Oscar's and Valentin's Project !\n");
    while (start==True){
        while(choice<1||choice>6){
            printf("Choose your option :\n");
            printf("1 - Create a new Data frame\n");
            printf("2 - Fill the Data frame\n");
            printf("3 - Display the Data frame\n");
            printf("4 - Modifiy the Data frame\n");
            printf("5 - Analyse the Data frame\n");
            printf("6 - Exit\n");
            scanf("%d",&choice);}
        switch(choice){
            case 1:
                int nb_col,,nb_row,i;
                printf("Enter the number of columns :\n");
                scanf("%d",&nb_col)
                char *titles[nb_col] = {};
                DF df* = create_empty_dataframe(int nb_col);
                printf("Enter the name of your colums :\n");
                for(i=1,i<nb_col,i++){
                    printf("Column %d name",i);
                    scanf("%c",*titles[i]);
                }
                fill_dataframe(DF *df, *titles,nb_col)
                break;
            
            case 2:
                int new_choice = 0;
                while(new_choice<1||new_choice>2){
                    printf("1 - Fill the Data Frame\n");
                    printf("2 - Fill the Data Frame with random values\n");
                    scanf("%d",&new_choice);
                }
                switch(new_choice){
                    case 1:
                    printf("Which column do you want to fill :\n");
                    scanf("%d",nb_col);
                    printf("How many rows do you want to fill :\n");
                    scanf("%d",nb_row);
                    for(i=1, i<nb_row,i++){
                        insert_value(df->column[nb_col],scanf("%d"))
                    }
                    
                }
                break;
            
            case 3:
                //code
                break;
            
            case 4:
                //code
                break;
            
            case 5:
                //code
                break;
            
            case 6:
                //code
                break;
            
            default:
                printf("ERROR");
                break;
            
            

            

        

        }

        
        
        
        



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


1. Filling
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
    • Display the number of cells containing a value less than x(x given as parameter)