#include<stdio.h>
#include<stdlib.h>

void print_array(int **array, int rows, int columns);
void free_memory(int ***array, int rows);
int** create_array(int rows, int columns);
void initialize_array(int rows, int columns, int ***array);

int main(){
    int **array, rows, columns;
    printf("Enter the number of rows and columns in the array\n");
    scanf("%d %d", &rows, &columns);

    printf("Creating an array\n");
    array = create_array(rows,columns);
    printf("Created array\n");

    printf("Enter the elements of the array\n");
    initialize_array(rows,columns,&array);

    printf("The initialized array:\n");
    print_array(array,rows,columns);

    printf("Freeing the memory\n");
    free_memory(&array,rows);
    return 0;
}

void free_memory(int ***array, int rows){
    for(int i=0;i<rows;i++){
        free(*(*array+i));
    }
    free(*array);
    *array=NULL;
}

void print_array(int **array, int rows, int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d",*(*(array+i)+j));
        }
        printf("\n");
    }
}

void initialize_array(int rows, int columns, int ***array){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            scanf("%d",&(*(*(*array+i)+j)));
        }
    }
}

int** create_array(int rows, int columns){
    int **new_array;
    new_array = (int **)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        *(new_array+i) = (int*)malloc(columns*sizeof(int));
    }
    return new_array;
}

