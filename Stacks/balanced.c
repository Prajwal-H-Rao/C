#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void push(char ch, char **brackets, int *top){
    *brackets = realloc(*brackets,sizeof(char)*(*top+2));
    ++(*top);
    (*brackets)[*top] = ch;
}

char pop(char **brackets, int* top){
    if(*top==-1) return '\0';
    char cj = (*brackets)[*top];
    (*brackets)[*top]=0;
    (*top)--;
    *brackets = realloc(*brackets, sizeof(char)*(*top+1));
    return cj;
}

bool isBalanced(char *braises, int length){
    char *stack = NULL;
    int top = -1;

    for (int i = 0; braises[i] != '\0'; i++) {
        if (braises[i] == '{' || braises[i] == '(' || braises[i] == '[') {
            push(braises[i], &stack, &top);
        }
        else if (braises[i] == '}' || braises[i] == ')' || braises[i] == ']') {
            if (top == -1) return false;

            char opening = stack[top];
            if ((braises[i] == '}' && opening != '{') ||
                (braises[i] == ')' && opening != '(') ||
                (braises[i] == ']' && opening != '[')) {
                return false;
            }

            pop(&stack, &top);
        }
    }

    return top == -1;
}

int main(){
    char ch[] = "{{}}";
    int length = sizeof(ch)/sizeof(ch[0]);
    printf("%d\n",isBalanced(ch,length));
    return 0;
}