//read and print average of section wise marks

#include <stdio.h>

void read_marks(int marks[], int m)
{
    int counter;;
    for (counter = 0; counter < m; counter++)
    {
        printf("Enter marks of student %d: ", counter + 1);
        scanf("%d", &marks[counter]);
    }
}

void main()
{
    int number_of_sections, number_of_students, section_counter, student_counter;
    float average, sum;
    
    printf("Enter number of sections: ");
    scanf("%d", &number_of_sections);
    
    printf("Enter number of students in each section: ");
    scanf("%d", &number_of_students);

    int marks[number_of_students];  

    for (section_counter = 0; section_counter < number_of_sections; section_counter++)
    {
        printf("\nSection %d\n", section_counter + 1);
        read_marks(marks, number_of_students);   // function call
        
        sum = 0;
        for (student_counter = 0; student_counter < number_of_students; student_counter++)
        {
            sum += marks[student_counter];
        }
    } 
        average = sum / number_of_students;
        printf("Average marks of section %d = %.2f\n", section_counter + 1, average);
    


}
