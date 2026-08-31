#include<stdlib.h>
#include<stdio.h>

void swap_elements(int i,int j, int ***array);
void print_array(int m, int **array);
void initialize_array(int m, int ***array);
int** create_array(int m);
void transpose(int m,int ***array);
void free_mem(int m, int ***array);

int main(){
    int **array ;
    int m;
    printf("Enter the number of rows and columns\n");
    scanf("%d", &m);

    printf("Creating the array\n");
    array = create_array(m);

    printf("Enter the elements of teh square matrix\n");
    initialize_array(m, &array);

    printf("The current matrix before transpose is:\n");
    print_array(m,array);

    printf("The matrix after transpose\n");
    transpose(m,&array);
    print_array(m,array);

    printf("Freeing the memory\n");
    free_mem(m,&array);

    return 0;
}

void transpose(int m,int ***array){
    for(int i=0;i<m;i++){
        for(int j = i+1;j<m;j++){
            swap_elements(i,j,array);
        }
    }
}

int** create_array(int m){
    int **array =(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
    *(array+i)=(int*)malloc(m*sizeof(int));
    return array;
}

void swap_elements(int i,int j, int ***array){
    int temp = *(*(*array+i)+j);
    *(*(*array+i)+j) = *(*(*array+j)+i);
    *(*(*array+j)+i) = temp;
}

void initialize_array(int m, int ***array){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&(*(*(*array+i)+j)));
        }
    }
}

void print_array(int m, int **array){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d ",*(*(array+i)+j));
        }
        printf("\n");
    }
}

void free_mem(int m, int ***array){
    for(int i=0;i<m;i++){
        free(*(*array+i));
    }
    free(*array);
}