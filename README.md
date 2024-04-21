# CDATAframe_L1INT4
Project in C S2 EFREI Paris (Oscar MASDUPUY &amp; Valentin AUFFRAY)

## [👉 visit our github 👈](https://github.com/JustDiablot/CDATAframe_L1INT4) 

This project is the beginning of the implementationof a C library to create and manipulate dataframes.Hope you'll like it

## Functions
### COLUMN *create_column(char *title)
Creates a new column with the given title.

### int insert_value(COLUMN *c, int value)
Inserts a value into the column.

### void print_col(COLUMN *c)
Prints the content of the column.

### DF *create_empty_dataframe(int nb_columns)
Creates an empty dataframe with the specified number of columns.

### void fill_dataframe(DF *df, char **titles, int nb_columns)
Fills the dataframe with columns using the provided titles.

### void print_dataframe(DF *df)
Prints the content of the dataframe.

# New functionalities are coming soon ...