#include<stdio.h>

int findMax(int *arr, int n){
    int max = -999;
    for(int i=0;i<n;i++){
        if(*(arr)>max){
            max = *(arr); 
        }
        arr++;
    }
    return max;
}

int main(){
    int array[8] = {1,121,21,3,4,5,55,120};
    printf("The maximum element in the array is: %d\n",findMax(array,8));
    return 0;
}