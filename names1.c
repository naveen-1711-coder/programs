//to read and print 5 names of employees

#include<stdio.h>

void main()
{
    int number_of_employees=5,counter;
    char employee_names[number_of_employees][40];
    printf("Reading and printing the names of %d employees\n",number_of_employees);
    for(counter=0;counter<number_of_employees;counter++)
    {
        printf("Enter the name of employee %d of %d :  \n",counter+1,number_of_employees);
        scanf("%s",employee_names[counter]);

    }
    printf("The names of %d employees is shown below\n",number_of_employees);
    for(counter=0;counter<number_of_employees;counter++)
    {
        printf("The name of employee %d of %d is %s\n",counter+1,number_of_employees,employee_names[counter]);

    }
}