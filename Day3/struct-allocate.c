#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int roll;
    float marks;
};

struct Student *create_student(char name[], int roll, float marks)
{
    struct Student *s1;
    s1 = (struct Student *)malloc(sizeof(struct Student));
    strcpy(s1->name, name);
    s1->marks = marks;
    s1->roll = roll;
    return s1;
}

void print_struct(struct Student student)
{
    printf("The details of %s\n", student.name);
    printf("His marks:%f\n", student.marks);
    printf("%d\n", student.roll);
}

void free_memory(struct Student **str)
{
    printf("Freein memory associated with %s\n", (*str)->name);
    free(*str);
};

int main()
{
    struct Student *str;
    printf("Creating a student\n");
    str = create_student("Prajwal", 21, 95.7);
    printf("the cerated student was:\n");
    print_struct(*str);
    free_memory(&str);
    return 0;
}
