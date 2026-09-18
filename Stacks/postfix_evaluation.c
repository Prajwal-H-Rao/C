#include <stdio.h>
#include <stdlib.h>

void push(int *top, char **stack, char ch)
{
    *stack = realloc(*stack, sizeof(char) * (*top + 2));
    (*top)++;
    (*stack)[*top] = ch;
}

char pop(int *top, char **stack)
{
    if (*top == -1)
        return '\0';
    char popped = (*stack)[*top];
    (*stack)[*top] = 0;
    (*top)--;
    *stack = realloc(*stack, sizeof(char) * (*top + 1));
    if (*top == -1)
        *stack = NULL;
    return popped;
}

void evaluate(char ch[], int length)
{
    char *stack = NULL;
    int top = -1;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= '0' && ch[i] <= '9')
        {
            push(&top, &stack, (char)(ch[i] - '0'));
        }
        else
        {
            int A = (int)pop(&top, &stack);
            int B = (int)pop(&top, &stack);
            if (ch[i] == '*')
                push(&top, &stack, (char)(B * A));
            if (ch[i] == '+')
                push(&top, &stack, (char)(B + A));
            if (ch[i] == '-')
                push(&top, &stack, (char)(B - A));
            if (ch[i] == '/')
                push(&top, &stack, (char)(B / A));
        }
    }
    printf("result:%d\n", pop(&top, &stack));
}

int main()
{
    char postfix[] = "23*4+";
    evaluate(postfix, sizeof(postfix) - 1);

    return 0;
}