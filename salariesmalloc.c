//read and print n salaries of employees using malloc 

#include<stdio.h>

void main()
{
   int number_of_employees,counter;
   printf("Enter how many salaries of employees you want to read and print :\n");
   scanf("%d",&number_of_employees);
   int *employee_salaries;
   employee_salaries=(int*)malloc(number_of_employees*sizeof(int));
   for(counter=0;counter<number_of_employees;counter++)
   {
    printf("Enter the salary of employee %d of %d :\n",counter+1,number_of_employees);
    scanf("%d",&employee_salaries[counter]);
   }
   printf("The salaries of %d employeesis shown below \n",number_of_employees);
   for(counter=0;counter<number_of_employees;counter++)
   {
       printf("The salary of employee %d of %d is %d\n",counter+1,number_of_employees,employee_salaries[counter]);
   }
   free(employee_salaries);

}