#include<stdio.h>
#include<stdlib.h>

int** create_array(int m, int n){
    int **array;
    array = (int**)malloc(m*sizeof(int*));

    for(int i=0;i<m;i++){
        *(array+i) = (int*)malloc(n*sizeof(int));
    }

    return array;
}

void print_array(int **array, int m, int n){
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(array+i)+j));
        }
        printf("\n");
    }
}

void intialize_array(int ***array, int m, int n){
    printf("Enter the elements of Array\n");
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&(*(*(*array+i)+j))); //(*array)[i][j]
        }
    }
}

void add_arrays(int ***array1, int*** array2, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            *(*((*array1)+i)+j)+=*(*((*array2)+i)+j);
        }
    }
}



int main(){

    int **arr1,**arr2;
    int m,n;

    printf("Enter the number of rows and columns in each matrix\n");
    scanf("%d%d",&m,&n);

    arr1 = create_array(m,n);
    arr2 = create_array(m,n);

    printf("Initialize arrays\n");
    intialize_array(&arr1,m,n);
    intialize_array(&arr2,m,n);

    printf("\nCreated Array1 and Array2\n");
    print_array(arr1,m,n);
    print_array(arr2,m,n);

    printf("\nAdded Array1 and Array2\n");
    add_arrays(&arr1,&arr2,m,n);
    print_array(arr1,m,n);

    for(int i=0;i<m;i++){
        free(*(arr1+i));
        free(*(arr2+i));
    }
    free(arr1);
    free(arr2);
    return 0;
}