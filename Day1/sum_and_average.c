#include<stdio.h>

void print_sum_and_average(int *array, int size){
    int sum = 0,i = 0;
    while(i<size){
        sum+=*(array++);
        i++;
    }
    double av = (double)sum/size;
    printf("Sum: %d Average: %f",sum,av);
}

int main(){
    int array[5] = {1,2,3,4,5};
    print_sum_and_average(array,5);
    return 0;
}