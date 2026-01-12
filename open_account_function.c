#include <stdio.h>

extern FILE* fp_accounts;
extern const int ACCOUNT_NUMBER_EXIST;
extern char* filename;
extern int record_size;


void open_account()
{
	printf("Reading account details of customer\n");
	printf("Enter the account number: ");
	scanf("%14[^\n]", customer.customer_account_number);
	clear_input_buffer();

	if (is_exist(customer.customer_account_number, ACCOUNT_NUMBER_EXIST))
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

	fp_accounts = fopen(filename, "ab");
	fwrite(&customer, record_size, 1, fp_accounts);
	fclose(fp_accounts);
}