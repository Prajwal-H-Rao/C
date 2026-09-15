#include<stdio.h>
#include<stdlib.h>

void push(char **stack, char alpha,int *top){
    *stack = realloc(*stack, sizeof(char) * (*top + 2));
    (*top)++;
    (*stack)[*top] = alpha;
}

char pop(char **stack, int *top){
    if(*top==-1){
        printf("Stack empty\n");
        return '\0';
    }
    char ch = (*stack)[*top];
    (*top)--;
    if (*top >= 0)
        *stack = realloc(*stack, sizeof(char) * (*top + 1));
    else {
        free(*stack);
        *stack = NULL;
    }
    return ch;
}

int main(){
    char ch[6]="hello";
    char *stack = NULL;
    int top = -1;
    int i=0;
    while(i<5){
        push(&stack,ch[i],&top);
        i++;
    }
    printf("Push completed\n");
    i=0;
    while(i<5){
        ch[i]=pop(&stack,&top);
        i++;
    }
    ch[5] = '\0';
    printf("Reversed String:%s",ch);

    return 0;
}