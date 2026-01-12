//read adn print the marks of l subjects of m sections of n students each

#include <stdio.h>
#include <stdlib.h>
 
 void main()
 {
 	int student_counter, student_count, subject_count, subject_counter, section_counter, section_count;

 	printf("Reading and printing the marks of l subject of m sections of n students each\n");
 	printf("Enter the number for l : ");
 	scanf("%d", &subject_count);
 	printf("Enter the number for n : ");
 	scanf("%d", &student_count);
 	printf("Enter the number for m : ");
 	scanf("%d", &section_count);
    
    int ***marks;

    marks = (int***)malloc(section_count * sizeof(int**));

 	for (section_counter = 0; section_counter < section_count; section_counter++)
 	{
 		marks[section_counter] = (int**)malloc(subject_count * sizeof(int*));

 		for (student_counter = 0; student_counter < student_count; student_counter++)
 		{
 			marks[section_counter][student_counter] = (int*)malloc(subject_counter * sizeof(int));

 			for (subject_counter = 0;subject_counter < subject_count; subject_counter++)
 			{
 				printf("Enter the marks of student %d in subject %d of section %d : ",student_counter + 1, subject_counter + 1, section_counter + 1);
 				scanf("%d",&marks[section_counter][student_counter][subject_counter]);

 			}
 		}
 	}

    printf("\n");

 	for (section_counter = 0; section_counter < section_count; section_counter++)
 	{
    	printf("\tSECTION %d\n",section_counter + 1);

 		for (student_counter = 0; student_counter < student_count; student_counter++)
 		{
			for (subject_counter = 0;subject_counter < subject_count; subject_counter++)
 			{
 				printf("The marks of student %d in subject %d is %d\n ", student_counter + 1, subject_counter + 1,marks[section_counter][student_counter][subject_counter]);
 			}
 		}
 	}
}