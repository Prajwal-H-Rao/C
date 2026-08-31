#include<stdio.h>
#include<stdlib.h>

int* create_array(int size){
    int *array =(int*)malloc(size*sizeof(int));
    return array;
}

void print_array(int size, int *array){
    for(int i=0;i<size;i++){
        printf("%d",*array++);
    }
}

void initialize(int **arrray, int size){
    for(int i=0;i<size;i++){
        scanf("%d", &*(*arrray+i));
    }
}

void free_memory( int **array){
    free(*array);
}

int main(){
    int size;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    printf("Creating a new array\n");
    int *array = create_array(size);

    printf("Enter the values of the array\n");
    initialize(&array,size);

    printf("The array created is:\n");
    print_array(size,array);

    printf("Freein memory\n");
    free_memory(&array);
    return 0;
}