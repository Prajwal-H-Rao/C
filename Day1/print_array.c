#include<stdio.h>
#include<stdlib.h>

void print_array(int *array, int array_size){
    for(int i = 0; i<array_size; i++){
        printf("%d",*(array+i));
    }
}

void main(){
    // int array[5] = {1,2,3,4,5};
    int *array = malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        *(array+i)=i+1;
    }
    print_array(array, 5);
    free(array);
    array=NULL;
}