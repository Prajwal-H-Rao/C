#include <stdio.h>
#include <stdlib.h>

int precidence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void push(char ch, int *top, char **stack){
    *stack = realloc(*stack, sizeof(char)*(*top+2));
    *top+=1;
    (*stack)[*top]=ch;
}

char pop(char **stack, int *top){
    if(*top==-1) return '\0';
    char ret = (*stack)[*top];
    (*stack)[*top]=0;
    (*top)--;
    *stack = realloc(*stack,sizeof(char)*(*top+1));
    return ret;
}

void infixToPrefix(char infix[], int length){
    char postfix[length];
    char *stack=NULL;
    int top=-1;
    int k=0;
    for(int i=0;infix[i]!='\0';i++){
        if(infix[i]=='*' || infix[i]=='+' || infix[i]=='/' || infix[i]=='-' || infix[i]=='^'){
            if(stack!=NULL && precidence(infix[i])<precidence(stack[top])){
                postfix[k++]=pop(&stack,&top);
                push(infix[i], &top, &stack);
            }
            else{
                push(infix[i], &top, &stack);
            }
        }
        else if(infix[i]=='('){
            push(infix[i],&top,&stack);
        }
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[k++]=pop(&stack,&top);
            }
            pop(&stack,&top);
        }
        else{
            postfix[k++]=infix[i];
        }
    }
    while(top!=-1){
        postfix[k++]=pop(&stack,&top);
    }
    postfix[k]='\0';
    printf("Postfix:%s\n",postfix);
}

int main()
{
    char infix[100];

    printf("Enter an infix expression: ");
    scanf("%99s", infix);
    infixToPrefix(infix, sizeof(infix));
    return 0;
}