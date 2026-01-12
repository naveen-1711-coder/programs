//function to show records from the file

#include <stdio.h>

extern FILE* fp_accounts;
extern const int ACTIVE_ACCOUNTS, CLOSED_ACCOUNTS;
extern char* filename;
extern int record_size;

void show_records(int mode)
{
    fp_accounts = fopen(filename, "rb");
    printf("\tCustomer account records\n\n");
    while (fread(&record, record_size, 1, fp_accounts) == 1)
    {
    	if ((record.status == '1' && mode == ACTIVE_ACCOUNTS) || (mode == CLOSED_ACCOUNTS && record.status == '0'))
    	{
        printf("Account number     : %s\n", record.customer_account_number);
        printf("Account holder name: %s\n", record.customer_name);
        printf("Account balance    : %d\n\n", record.account_balance);
 		}  	
    }
    fclose(fp_accounts);
}