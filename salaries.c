//read and print 5 salaries of employes

#include<stdio.h>

void main()
{
    int number_of_employees=5,employee_salaries[number_of_employees],counter;
    printf("Reading and printing the salaries of %d employees\n",number_of_employees);
    for (counter=0;counter<number_of_employees;counter++)
    {
        printf("Enter the salary of employee %d of %d :\n",counter+1,number_of_employees);
        scanf("%d",&employee_salaries[counter]);
    }
    printf("The salaries of %d employees is shown below\n",number_of_employees);
    for(counter=0;counter<number_of_employees;counter++)
    {
        printf("The salary of employee %d of %d is %d\n",counter+1,number_of_employees,employee_salaries[counter]);
    }
};