//print the marks of p students in q subjects

#include <stdio.h>
#include <stdlib.h>

void main() 
{
	int student_count,student_counter,subject_count,subject_counter;
	printf("Enter the number of students : ");
	scanf("%d", &student_count);
	printf("Enter the number of subjects : ");
	scanf("%d", &subject_count);

	int **marks;
	marks = (int**)malloc(student_count * sizeof(int*));

	for(student_counter = 0; student_counter < student_count; student_counter++)
	{
		marks[student_counter] = (int*)malloc(subject_count * sizeof(int));

		for (subject_counter = 0; subject_counter < subject_count; subject_counter++)
		{
			printf("Enter the marks of student %d in subject %d : ",student_counter + 1, subject_counter + 1);
			scanf("%d", &marks[student_counter][subject_counter]);
	    }
	}

	for(student_counter = 0; student_counter < student_count; student_counter++)
	{

		for (subject_counter = 0; subject_counter < subject_count; subject_counter++)
		{
			printf("The marks of student %d in subject %d is %d \n",student_counter + 1, subject_counter + 1, marks[student_counter][subject_counter]);
		}
	}

	for (student_counter = 0; student_counter < student_count; student_counter++)
    {
        free(marks[student_counter]);
    }
    free(marks);

    
}	
