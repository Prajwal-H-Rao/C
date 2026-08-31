#include<stdio.h>
#include<stdlib.h>

int** create_array(int m, int n){
    int **array;
    array = (int**)malloc(m*sizeof(int*));

    for(int i=0;i<m;i++){
        *(array+i)=(int*)malloc(n*sizeof(int));
    }
    return array;
}

void initialize_array(int*** array, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&(*(*(*array+i)+j))); //*array = 2d matrix ith array of 2d matrix = *(*array+i), j the element in the ith array is *(*(*array+i)+j)
        }
    }
}

void print_array(int **array, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(array+i)+j)); //*(array+i) gives the ith array (each row), *(*(array+i)+j) gives the jth element in the ith array
        }
        printf("\n");
    }
}

void multiply(int **array1, int**array2, int ***result, int m, int n, int p){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<p;k++){
                *(*(*result+i)+k)=*(*(array1+i)+j)* *(*(array2+j)+k);
            }
        }
    }
}

void free_mem(int ***array, int m){
    for(int i=0;i<m;i++){
        free(*(*array+i));
    }
    free(*array);
}

int main(){

    int **array1,**array2, **result;
    int m,n,p;

    printf("Enter the m,n,p\n");
    scanf("%d %d %d",&m,&n,&p);

    array1=create_array(m,n);
    array2=create_array(n,p);
    result = create_array(m,p);

    printf("Enter the elements of the array\n");
    initialize_array(&array1,m,n);
    initialize_array(&array2,n,p);

    printf("Array1:\n");
    print_array(array1,m,n);
    printf("\nArray2:\n");
    print_array(array2,n,p);

    printf("The product is:\n");
    multiply(array1,array2,&result,m,n,p);
    print_array(result,m,p);

    printf("Freeing memory\n");
    free_mem(&array1,m);
    free_mem(&array2,n);
    free_mem(&result,m);

    return 0;
}