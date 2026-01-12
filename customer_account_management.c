//a menu is shown to the customer as shown below

    /* menu options
    1. Open an Account
    2. Show Active Accounts
    3. Update Records
    4. Close Account
    5. Show Closed Accounts
    6. EXIT */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mytools.c"
#include "structure.c"
#include "open_account_function.c"
#include "show_records_function.c"
#include "update_records.c"
#define SIZE 15
#define STATEMENT "Account not found!\n"
#define WRONG_CHOICE "Entered a wrong choice\n"

void update_name_or_balance(int, char*);
void deposit_or_withdrawal(int, char*);
void close_account();
int is_exist(char*, int);
int find_record(FILE *, char *, struct customer_account_details *);
void seek_back(FILE*);

FILE* fp_accounts;
char* filename = "customers_account_records.dat";

const int ACCOUNT_NUMBER_EXIST = 765;
const int IS_ACTIVE = 987;
const int ACTIVE_ACCOUNTS = 876;
const int CLOSED_ACCOUNTS = 234;

int record_size = sizeof(struct customer_account_details);
char account_number[SIZE];
int choice;
struct customer_account_details record;

void main()
{
	do
	{
		printf("\nChoose an option from the following menu.\n");
		printf("\n1. Open an Account\n2. Show Active Accounts\n3. Update Record\n4. Close Account\n5. Show Closed Accounts\n6. EXIT\n\n");
		printf("Enter yours choice: ");
		scanf("%d", &choice);
		clear_input_buffer();

		switch (choice)
		{
		case 1 :
			open_account();
			break;

		case 2 :
			show_records(ACTIVE_ACCOUNTS);
			break;

		case 3 :
			update_records();
			break;

		case 4 :
			close_account();
			break;

		case 5 :
			show_records(CLOSED_ACCOUNTS);
			break;

		case 6 :
			exit(0);

		default :
			printf(WRONG_CHOICE);
			break;
		}
	}while (1);
}

void close_account()
{
    fp_accounts = fopen(filename, "rb+");

    printf("For closing an account\n");
    printf("Enter the account number: ");
    scanf("%14[^\n]", account_number);
    clear_input_buffer();

    if (!find_record(fp_accounts, account_number, &record) || record.status != '1')
    {
        printf(STATEMENT);
        fclose(fp_accounts);
        return;
    }

    printf("Are you sure you want to close\n(Enter 1 for yes or 0 for no): ");
    scanf("%d", &choice);
    clear_input_buffer();

    if (choice == 1)
    {
    	record.status = '0';
		seek_back(fp_accounts);
        fwrite(&record, record_size, 1, fp_accounts);
        printf("Account closed successfully\n");	
    }
    fclose(fp_accounts);
}

int is_exist(char* account_number, int mode)
{
	fp_accounts = fopen(filename, "rb");

	if (find_record(fp_accounts, account_number, &record))
	{
		if (mode == ACCOUNT_NUMBER_EXIST)
		{
			fclose(fp_accounts);
			return 1;
		}
		else if (mode == IS_ACTIVE && record.status == '1')
		{
			fclose(fp_accounts);
			return 1;
		}
	}
	
	fclose(fp_accounts);
	return 0;
}

int find_record(FILE *fp, char *account_number, struct customer_account_details *record)
{
    rewind(fp);

    while (fread(record, record_size, 1, fp) == 1)
    {
        if (strcmp(record->customer_account_number, account_number) == 0)
        {
            return 1;
        }
    }
    return 0;           
}