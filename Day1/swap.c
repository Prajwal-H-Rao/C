#include<stdio.h>

void swap_numbers(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
    return;
}

void main(){
    int a = 5;
    int b = 10;
    printf("A:%d B:%d\n",a,b);
    swap_numbers(&a,&b);
    printf("A:%d B:%d\n",a,b);
}