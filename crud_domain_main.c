// main function of bank account management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"

#define MENU_FILE "menu_options.config"
#define DATA_FILE "crud_operation_data.dat"
#define FIELDS_FILE "fields.config"
#define FIELD_SIZE 100
#define ENTER_CHOICE "\nEnter your choice: "
#define FILE_NOT_FOUND "Unable to open files\n"
#define RECORD_NOT_FOUND "\nRecord not found or already closed\n"
#define SIZE 20
#define ACTIVE 'A'
#define CLOSED 'C'

void create_record(int, char*, int);
void print_menu_options();
void show_records(int, char*, int, int);
int get_field_count();
void update_record(int, char*);
int get_record_size(int);
void load_fields(int);
void close_record(int, int);
int is_record_found(FILE*, int, char*, int*);
int record_is_active(FILE*, int, char*, int*);
int is_null(FILE*);

int choice;
char status;
char **field_names;

int main()
{
	int field_count = get_field_count();
	int field_counter;
	load_fields(field_count);
	char value[SIZE];
	int record_fields_size = field_count * SIZE;

	do
	{
		print_menu_options();
		printf(ENTER_CHOICE);
		scanf("%d", &choice);
		clear_input_buffer();

		switch (choice)
		{
			case 1 :
				create_record(field_count, value, field_counter);
				break;

			case 2 :
				show_records(field_count, value, record_fields_size, field_counter);
				break;
			case 3 :
				update_record(field_count, value);
				break;

			case 4 :
				close_record(field_count, record_fields_size);
				break;

			case 5 :
				exit(0);
		}

	}while (1);	
	return 0;
}

void create_record(int field_count, char* value, int field_counter)
{
	FILE *fp_data;
	fp_data = fopen(DATA_FILE, "ab");

	printf("\nEnter details:\n");

	for (field_counter = 0; field_counter < field_count; field_counter++)
	{
		printf("Enter %s: ", field_names[field_counter]);
		scanf("%19[^\n]", value);
		clear_input_buffer();

        if (field_counter == 0)
        {
            int record_start_position;

            if (is_record_found(fp_data, field_count, value, &record_start_position))
            {
                printf("Record already exists\n\n");
                fclose(fp_data);
                return;
            }
        }

		fwrite(value, SIZE, 1, fp_data);
	}

	status = ACTIVE;
	fwrite(&status, sizeof(status), 1, fp_data);

	fclose(fp_data);

    printf("Record created successfully\n");
}

void show_records(int field_count, char* value, int record_fields_size, int field_counter)
{
    FILE *fp_data;
    int record_start_positon;

    fp_data = fopen(DATA_FILE, "rb");

    if (is_null(fp_data))
    {
        return;
    }

    printf("\n\tActive Records\n\n");

    while (1)
    {	
    	record_start_positon = get_record_position(fp_data);

    	if (fseek(fp_data, record_fields_size, SEEK_CUR) != 0)
    	{
    		break;
    	}

    	fread(&status, 1, 1, fp_data);

    	if (status == ACTIVE)
    	{
    		fseek(fp_data, record_start_positon, SEEK_SET);

        	for (field_counter = 0; field_counter < field_count; field_counter++)
        	{
                fread(value, SIZE, 1, fp_data);
        		printf("%-20s : %s\n", field_names[field_counter], value);
        	}

        	fread(&status, 1, 1, fp_data);
        	printf("\n");
		}
	}
	fclose(fp_data);
}

void update_record(int field_count, char* value)
{
    FILE *fp_data;
    char field_value[SIZE];
    int record_start_position;
    int field_counter;

    fp_data = fopen(DATA_FILE, "rb+");

    if (is_null(fp_data))
    {
        return;
    }

    printf("Enter %s to update that record: ", field_names[0]);
    scanf("%19[^\n]", field_value);
    clear_input_buffer();

    if (!record_is_active(fp_data, field_count, field_value, &record_start_position))
    {
        printf(RECORD_NOT_FOUND);
        fclose(fp_data);
        return;
    }

    printf("\nSelect field to update:\n");

    for (field_counter = 0; field_counter < field_count; field_counter++)
    {
        printf("%d. %s\n", field_counter + 1, field_names[field_counter]);
    }

    printf(ENTER_CHOICE);
    scanf("%d", &choice);
    clear_input_buffer();

    if (choice < 1 || choice > field_count)
    {
        printf("Invalid choice\n");
        fclose(fp_data);
        return;
    }

    fseek(fp_data, record_start_position + (choice - 1) * SIZE, SEEK_SET);

    printf("Enter new value for %s: ", field_names[choice - 1]);
    scanf("%19[^\n]", value);
    clear_input_buffer();

    fwrite(value, SIZE, 1, fp_data);
    printf("\n\nRecord updated successfully\n\n");

    fclose(fp_data);
}

void close_record(int field_count, int record_fields_size)
{
    FILE *fp_data;
    char field_value[SIZE];
    int record_start_position;

    fp_data = fopen(DATA_FILE, "rb+");

    if (is_null(fp_data))
    {
        return;
    }

    printf("Enter %s to close that record: ", field_names[0]);
    scanf("%19[^\n]", field_value);
    clear_input_buffer();

    if (record_is_active(fp_data, field_count, field_value, &record_start_position))
    {
        fseek(fp_data, record_start_position + record_fields_size, SEEK_SET);

        status = CLOSED;
        fwrite(&status, 1, 1, fp_data);

        printf("\nRecord closed successfully\n\n");
    }
    else
    {
        printf(RECORD_NOT_FOUND);
    }

    fclose(fp_data);
}

int get_field_count()
{
    FILE *fp_fields = fopen(FIELDS_FILE, "rb");
    char fields[FIELD_SIZE];
    int field_count = 0;

    if (is_null(fp_fields))
    {
        return;
    }

    while (fgets(fields, FIELD_SIZE, fp_fields) != NULL)
    {
        field_count++;
    }

    fclose(fp_fields);
    return field_count;
}

int get_record_size(int field_count)
{
	return (field_count * SIZE) + sizeof(char);
}

void print_menu_options()
{
    FILE* fp_menu = fopen(MENU_FILE, "r");
    char line[FIELD_SIZE];
    
    while (fgets(line, FIELD_SIZE, fp_menu))
    {
        printf("%s", line);
    }
    fclose(fp_menu);
}

void load_fields(int field_count)
{
	FILE *fp_fields = fopen(FIELDS_FILE, "r");
	int counter;
	field_names = (char**)malloc(field_count * sizeof(char*));

	for (counter = 0;counter < field_count; counter++)
	{
		field_names[counter] = (char*)malloc(FIELD_SIZE);

		if (fgets(field_names[counter], FIELD_SIZE, fp_fields) == NULL)
		{
			exit(1);
		}
		removenewline(field_names[counter]);
	}
	
	fclose(fp_fields);	
}

int get_record_position(FILE *fp_data)
{
	int record_start_position = ftell(fp_data);
	return record_start_position;
}

int is_record_found(FILE *fp_data, int field_count, char *field_value, int *record_start_position)
{
    char value[SIZE];
    int record_data_size = get_record_size(field_count) - SIZE;

    while (1)
    {
        *record_start_position = ftell(fp_data);

        if (fread(value, SIZE, 1, fp_data) != 1)
        {
			break; 
		}

        if (strcmp(value, field_value) == 0)
        {
            return 1;
        }

        fseek(fp_data, record_data_size, SEEK_CUR);
    }
    return 0;
}

int record_is_active(FILE* fp_data, int field_count, char* field_value, int *record_start_position)
{
    int record_fields_size = (field_count - 1) * SIZE;

    if (is_record_found(fp_data, field_count, field_value, record_start_position) == 1)
    {
        fseek(fp_data, *record_start_position + record_fields_size, SEEK_CUR);

        fread(&status, 1, 1, fp_data);

        if (status == ACTIVE)
        {
            return 1;
        }
    }
return 0;
}

int is_null(FILE* file_pointer)
{
    if (file_pointer == NULL)
    {
        printf(FILE_NOT_FOUND);
        return 1;
    }
    return 0;
}