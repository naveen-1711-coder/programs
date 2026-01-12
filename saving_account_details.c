//read save the account detaisl of one customer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 50

struct customer_account_details
{
	char customer_account_number[size];
	char customer_name[size];
	int account_balance;
};

void main()
{
	struct customer_account_details customer;
	FILE* fp;

	printf("Reading account details of customer\n");
	printf("Enter the account number: ");
	fgets(customer.customer_account_number, size, stdin);
	printf("Enter the account name: ");
	fgets(customer.customer_name, size , stdin);
	printf("Enter the account balance: ");
	scanf("%d", &customer.account_balance);

	fp = fopen("customer_account_details.txt","a");
	fprintf(fp, "\tCustomer details\n\n", fp);
	fprintf(fp, "Account number: %s", customer.customer_account_number);
	fprintf(fp, "Account holder name: %s", customer.customer_name);
	fprintf(fp, "Account balance: %d\n", customer.account_balance);
	fclose(fp);
}