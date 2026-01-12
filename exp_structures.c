#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    float marks;
};

int main() {

    struct Student s1;

    s1.id = 1;
    s1.marks = 89.5;
    printf("Enter a name : ");
    scanf("%s", s1.name);

    printf("Student ID: %d\n", s1.id);
    printf("Student Name: %s\n", s1.name);
    printf("Student Marks: %.2f\n", s1.marks);

    return 0;
}
