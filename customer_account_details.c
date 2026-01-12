//a menu is shown to the customer as shown below`	q1

    /* menu options
    1. open an account
    2. show all records
    3. update records
    4. close account
    5. EXIT */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mytools.c"
#define size 15

void open_account();
void show_all_records();
void clear_input_buffer();
void update_records();
void update_name_or_balance(int, char*);
void deposit_or_withdrawal(int, char*);
void close_account();
int is_exist(char*, int);

FILE* fp_account;
char* filename = "customers_account_records.dat";

const int ACCOUNT_NUMBER_EXIST = 765;
const int IS_ACTIVE = 987;

struct customer_account_details
{
	char customer_account_number[size];
	char customer_name[size];
	int account_balance;
	char status;

}customer;

int record_size = sizeof(customer);
char account_number[size];
int choice;
struct customer_account_details record;

void main()
{
	do
	{
		printf("\n1. Open an Account\n2. Show All Records\n3. Update Records\n4. Close Account\n5. EXIT\n\n");
		printf("Enter yours choice: ");
		scanf("%d", &choice);
		clear_input_buffer();

		switch(choice)
		{
		case 1 :
			open_account();
			break;

		case 2 :
			show_all_records();
			break;

		case 3 :
			update_records();
			break;

		case 4 :
			close_account();
			break;

		case 5 :
			exit(0);

		default :
			printf("Entered a wrong choice ");
			break;
		}
	}while(1);
}

void open_account()
{
	printf("Reading account details of customer\n");
	printf("Enter the account number: ");
	scanf("%14[^\n]", customer.customer_account_number);
	clear_input_buffer();

	if(is_exist(customer.customer_account_number, ACCOUNT_NUMBER_EXIST))
	{
		printf("Account number already exists!\n");
		return;
	}

	printf("Enter the account name: ");
	scanf( "%14[^\n]", customer.customer_name);
	clear_input_buffer();

	printf("Enter the account balance: "); 
	scanf("%d", &customer.account_balance);
	clear_input_buffer();
	customer.status = '1';

	fp_account = fopen(filename, "ab");

	fwrite(&customer, record_size, 1, fp_account);
	fclose(fp_account);
}

void show_all_records()
{
    fp_account = fopen(filename, "rb");

    printf("\tCustomers account records\n\n");
    while (fread(&record, record_size, 1, fp_account) == 1)
    {
    	if(record.status == '1')
    	{
        printf("Account number: %s\n", record.customer_account_number);
        printf("Account holder name: %s\n", record.customer_name);
        printf("Account balance: %d\n\n", record.account_balance);
    	}
    }
    fclose(fp_account);
}


void update_records()
{
	printf("For updating fields in record\n");
	printf("\nEnter the account number: ");
	scanf(" %14[^\n]", account_number);

	if(!is_exist(account_number, IS_ACTIVE))
	{
		printf("The given account number doesn't exist!\n\n");
	}
	else
	{
		do
		{
			printf("1. update name\n2. update balance\n3. deposit money\n4. withdraw money\n5. EXIT\n\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			clear_input_buffer();

			switch(choice)
			{
				case 1 :
					update_name_or_balance(choice, account_number);
					break;

				case 2 :
					update_name_or_balance(choice, account_number);
					break;

				case 3 :
					deposit_or_withdrawal(choice, account_number);
					break;

				case 4 :
					deposit_or_withdrawal(choice, account_number);
					break;

				case 5 :
					return;

				default :
					printf("Entered wrong choice");
					break;
			}
		}while(1);
	}
}

void update_name_or_balance(int choice, char* account_number)
{
    fp_account = fopen(filename, "rb+");

	if (!find_record(fp_account, account_number, &record))
    {
        printf("Account not found\n");
        fclose(fp_account);
        return;
    }

    if (choice == 1)
    {
		printf("Enter new name: ");
        scanf( "%14[^\n]", record.customer_name);
        clear_input_buffer();
	}
	else if (choice == 2)
	{
		printf("Enter new balance: ");
		scanf("%d", &record.account_balance);
		clear_input_buffer();
	}

	fseek(fp_account, -record_size, SEEK_CUR);
	fwrite(&record, record_size, 1, fp_account);
	
        
    
    fclose(fp_account);
}


void deposit_or_withdrawal(int choice, char* account_number)
{
    fp_account = fopen(filename, "rb+");
    int deposit_amount, withdraw_amount;

    if (!find_record(fp_account, account_number, &record))
    {
        printf("Account not found\n");
        fclose(fp_account);
        return;
    }

	if (choice == 3)
    {
		printf("Enter deposit amount: ");
		scanf("%d", &deposit_amount);
		clear_input_buffer();

		if (deposit_amount > 0)
    	{
    		record.account_balance += deposit_amount;
		}
		else
		{
    	printf("Invalid deposit amount\n");
    	}
    }
    else if (choice == 4)
	{
		printf("Enter withdraw amount: ");
		scanf("%d", &withdraw_amount);
		clear_input_buffer();

		if (withdraw_amount <= record.account_balance)
        {
			record.account_balance -= withdraw_amount;
        }
		else
		{
			printf("Insufficient balance\n");
		}

	}

	fseek(fp_account, -record_size, SEEK_CUR);
	fwrite(&record, record_size, 1, fp_account);
    
    fclose(fp_account);
}

void close_account()
{
    fp_account = fopen(filename, "rb+");

    printf("For closing an account\n");
    printf("Enter the account number: ");
    scanf("%14[^\n]", account_number);
    clear_input_buffer();

    if (!find_record(fp_account, account_number, &record) || record.status != '1')
    {
        printf("Account does not exist or already closed\n");
        fclose(fp_account);
        return;
    }

    printf("Are you sure you want to close\n(Enter 1 for yes or 0 for no): ");
    scanf("%d", &choice);
    clear_input_buffer();

    if(choice == 1)
    {
    	record.status = '0';
        fseek(fp_account, -record_size, SEEK_CUR);
        fwrite(&record, record_size, 1, fp_account);
        printf("Account closed successfully\n");	
    }
    fclose(fp_account);
}

int is_exist(char* account_number, int mode)
{
	fp_account = fopen(filename, "rb");

	if(fp_account == NULL)
		return 0;
	while(fread(&record, record_size, 1, fp_account) == 1)
	{
		if(strcmp(record.customer_account_number, account_number) == 0)
		{
			if(mode == ACCOUNT_NUMBER_EXIST)
			{
			fclose(fp_account);
			return 1;
			}
			else if(mode == IS_ACTIVE && record.status == '1')
			{
				fclose(fp_account);
				return 1;
			}
		}
	}fclose(fp_account);
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
