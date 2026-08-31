#include<stdio.h>

int main(){
    int p = 5;
    int *pointer = &p;
    int **pointer_to_p = &pointer;

    *(*pointer_to_p)+=1;
    printf("Using double pointer %d Using single Pointer %d using variable %d",**pointer_to_p,*pointer,p);
    return 0;
}