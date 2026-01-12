//a menu is shown to the customer to open an acoount and showing of account deetails

    /* menu options
    1.open an account
    2.show all records
    3.EXIT */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mytools.c"
#define size 15

void saving_acount_details();
void show_all_records();
void clear_buffer();

FILE* file_pointer;
char* filename = "customers_account_records.dat";

struct customer_account_details
{
	char customer_account_number[size];
	char customer_name[size];
	int account_balance;
}customer;

int length = sizeof(customer);

void main()
{
	int choice;

	do
	{
		printf("\n1.open an account\n2.show all records\n3.EXIT\n\n");
		printf("Enter you choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			saving_acount_details();
			break;

		case 2 :
			show_all_records();
			break;

		case 3 :
			exit(0);

		default :
			printf("Entered a wrong choice ");
			break;
		}
	}while(1);
}

void saving_acount_details()
{
	printf("Reading account details of customer\n");
	getchar();
	printf("Enter the account number: ");
	scanf("%14s", customer.customer_account_number);
	clear_buffer();
	printf("Enter the account name: ");
	scanf("%14s", customer.customer_name);
	clear_buffer();
	printf("Enter the account balance: ");
	scanf("%d", &customer.account_balance);
	clear_buffer();

	file_pointer = fopen(filename,"a");

	fwrite(&customer, length, 1, file_pointer);
	fclose(file_pointer);
}

void show_all_records()
{
	file_pointer = fopen(filename, "rb");
	printf("\tCustomers account records\n\n");
	while(fread(&customer, length, 1, file_pointer) == 1)
	{

		printf("Account number: %s\n", customer.customer_account_number);
		printf("Account holder name: %s\n", customer.customer_name);
		printf("Account balance: %d\n\n",customer.account_balance);
	}fclose(file_pointer);
	
}

void clear_buffer()
{
	while(getchar() != '\n')
	{

	}
}



