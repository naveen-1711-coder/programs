// main function of bank account management

#include <stdio.h>
#include <stdlib.h>
#define MENU_FILE "menu_options.config"
#define FIELD_SIZE 100
#define SIZE 20

int size = 100;
int choice;

void open_account(char*);
void print_menu_options(char*);

int main()
{
	print_menu_options(MENU_FILE);
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
		
	}

	open_account(MENU_FILE);
	return 0;
}

void open_account(char* menu_file)
{
	FILE* fp_field, *fp_data;
	char field[FIELD_SIZE];
	char value[SIZE];

	fp_field = fopen(menu_file, "r");
	fp_data = fopen("bank_accounts_management.dat", "ab");

	printf("Enter details:\n");

	while(fgets(field, FIELD_SIZE, fp_field) != NULL)
	{
		printf("Enter %s", field);
		scanf("19[^\n]", value);

		fwrite(value, SIZE, 1, fp_data);
	}

	fclose(fp_field);
	fclose(fp_data);
}

void print_menu_options(char *menu_file)
{
    FILE* fp_accounts = fopen(menu_file, "r");
    char line[FIELD_SIZE];
    
    while (fgets(line, FIELD_SIZE, fp_accounts))
    {
        printf("%s", line);
    }
    fclose(fp_accounts);
}