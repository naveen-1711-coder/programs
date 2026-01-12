//program for student admission details management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"

#define SIZE 20

typedef enum
{
    STUDENT_ID_EXIST = 111,
    STUDENT_IS_ACTIVE = 222
} student_check_mode;

char *filename = "student_admission_records.dat";

struct student_details
{
    char student_id[SIZE];
    char student_name[SIZE];
    int student_age;
    char status;   
};

FILE *fp_students;
int record_size = sizeof(struct student_details);
int choice;
char search_student_id[SIZE];

void add_student();
void show_all_students();
void update_student();
void delete_student();
int is_student_exist(char *, student_check_mode);
int find_student_record(FILE *, char *, struct student_details *);

int main()
{
    while (1)
    {
        printf("\nChoose an option from the following menu.\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Update Student Details\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice)
        {
            case 1:
                add_student();
                break;

            case 2:
                show_all_students();
                break;

            case 3:
                update_student();
                break;

            case 4:
                delete_student();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

void add_student()
{
    struct student_details student;
    printf("\nEnter student ID: ");
    scanf("%19[^\n]", student.student_id);
    clear_input_buffer();

    if (is_student_exist(student.student_id, STUDENT_ID_EXIST))
    {
        printf("Student ID already exists!\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%19[^\n]", student.student_name);
    clear_input_buffer();

    printf("Enter student age: ");
    scanf("%d", &student.student_age);
    clear_input_buffer();

    student.status = '1';

    fp_students = fopen(filename, "ab");
    fwrite(&student, record_size, 1, fp_students);
    fclose(fp_students);

}

void show_all_students()
{
    struct student_details student_record;
    fp_students = fopen(filename, "rb");
    
    if (fp_students == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n\tStudent Records\n\n");
    while (fread(&student_record, record_size, 1, fp_students) == 1)
    {
        if (student_record.status == '1')
        {
            printf("Student ID   : %s\n", student_record.student_id);
            printf("Student Name : %s\n", student_record.student_name);
            printf("Student Age  : %d\n\n", student_record.student_age);
        }
    }
    fclose(fp_students);
}

void update_student()
{
    struct student_details student_record;
    printf("\nEnter student ID to update: ");
    scanf("%19[^\n]", search_student_id);
    clear_input_buffer();

    if (!is_student_exist(search_student_id, STUDENT_IS_ACTIVE))
    {
        printf("Student not found!\n");
        return;
    }

    fp_students = fopen(filename, "rb+");

    if (!find_student_record(fp_students, search_student_id, &student_record))
    {
        printf("Student record not found.\n");
        fclose(fp_students);
        return;
    }

    printf("\n1. Update Name\n2. Update Age\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clear_input_buffer();

    if (choice == 1)
    {
        printf("Enter new name: ");
        scanf("%19[^\n]", student_record.student_name);
        clear_input_buffer();
    }
    else if (choice == 2)
    {
        printf("Enter new age: ");
        scanf("%d", &student_record.student_age);
        clear_input_buffer();
    }
    else
    {
        printf("Invalid option\n");
        fclose(fp_students);
        return;
    }

    fseek(fp_students, -record_size, SEEK_CUR);
    fwrite(&student_record, record_size, 1, fp_students);
    fclose(fp_students);

    printf("Student details updated successfully!\n");
}

void delete_student()
{
    struct student_details student_record;
    printf("\nEnter student ID to delete: ");
    scanf("%19[^\n]", search_student_id);
    clear_input_buffer();

    fp_students = fopen(filename, "rb+");

    if (!find_student_record(fp_students, search_student_id, &student_record) || student_record.status != '1')
    {
        printf("Student not found or already deleted.\n");
        fclose(fp_students);
        return;
    }

    printf("Are you sure you want to delete this record? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);
    clear_input_buffer();

    if (choice == 1)
    {
        student_record.status = '0';
        fseek(fp_students, -record_size, SEEK_CUR);
        fwrite(&student_record, record_size, 1, fp_students);
        printf("Student record deleted successfully!\n");
    }

    fclose(fp_students);
}

int is_student_exist(char *student_id, student_check_mode mode)
{
    struct student_details student_record;
    fp_students = fopen(filename, "rb");

        if (find_student_record(fp_students, student_id, &student_record))
        {
            if (mode == STUDENT_ID_EXIST)
            {
                fclose(fp_students);
                return 1;
            }
            else if (mode == STUDENT_IS_ACTIVE && student_record.status == '1')
            {
                fclose(fp_students);
                return 1;
            }
        }
    fclose(fp_students);
    return 0;
}

int find_student_record(FILE *file_pointer, char *student_id, struct student_details *record)
{
    rewind(file_pointer);

    while (fread(record, record_size, 1, file_pointer) == 1)
    {
        if (strcmp(record->student_id, student_id) == 0)
        {
            return 1;
        }
    }
    return 0;
}