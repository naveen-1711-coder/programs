//function to update records in file

#include <stdio.h>
#define WRONG_CHOICE "Entered a wrong choice\n"
#define STATEMENT "Account not found!\n"
#define SIZE 15

extern FILE* fp_accounts;
extern const int IS_ACTIVE;
extern char* filename;
extern int choice;
extern char account_number[SIZE];
extern int record_size;

void update_name_or_balance(int, char*);
void deposit_or_withdrawal(int, char*);

void update_records()
{
	printf("For updating fields in record\n");
	printf("\nEnter the account number: ");
	scanf(" %14[^\n]", account_number);

	if (!is_exist(account_number, IS_ACTIVE))
	{
		printf(STATEMENT);
	}
	else
	{
		do
		{
			printf("1. Update Name\n2. Update Balance\n3. Deposit Money\n4. Withdraw Money\n5. EXIT\n\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			clear_input_buffer();

			switch (choice)
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
					printf(WRONG_CHOICE);
					break;
			}
		}while (1);
	}
}

void update_name_or_balance(int choice, char* account_number)
{
    fp_accounts = fopen(filename, "rb+");

	if (!find_record(fp_accounts, account_number, &record))
    {
        printf(STATEMENT);
        fclose(fp_accounts);
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

	seek_back(fp_accounts);
	fwrite(&record, record_size, 1, fp_accounts);
	fclose(fp_accounts);
}


void deposit_or_withdrawal(int choice, char* account_number)
{
    fp_accounts = fopen(filename, "rb+");
    int deposit_amount, withdraw_amount;

    if (!find_record(fp_accounts, account_number, &record))
    {
        printf(STATEMENT);
        fclose(fp_accounts);
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
	    	fclose(fp_accounts);
	    	return;
    	}
    }
    else if (choice == 4)
	{
		printf("Enter withdraw amount: ");
		scanf("%d", &withdraw_amount);
		clear_input_buffer();

		if (withdraw_amount <= record.account_balance && withdraw_amount > 0)
        {
			record.account_balance -= withdraw_amount;
        }
		else
		{
			printf("Insufficient balance\n");
			fclose(fp_accounts);
			return;
		}

	}

	seek_back(fp_accounts);
	fwrite(&record, record_size, 1, fp_accounts);
    fclose(fp_accounts);
}
