// program for inventory management using linked list


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATAFILE "inventory.dat"
#define LIST_EMPTY "\nList is empty\n"
#define SIZE 25
#include "mytools.c"
#define ITEM_NOT_FOUND "\nItem not found\n"

typedef struct item_details
{
    char item_id[SIZE];
    char item_name[SIZE];
    float item_price;
} item_details;

typedef struct item_node
{
    item_details item_data;
    struct item_node* next;
} item_node;

typedef enum
{
    SORT_BY_NAME,
    SORT_BY_PRICE,
    NO_SORT
} sort_type;

item_node *head = NULL;
int item_record_size = sizeof(item_details);

void add_item();
void show_all_items(item_node*, sort_type);
void modify_item_details(int);
void delete_item(item_node*);
void append_item(item_node*);
void save_data_to_file();
void load_data_from_file();
void clear_data_in_list(item_node*);
void print_options();
item_node *find_item();
item_node *get_last_node();
int null_node_checker(item_node*);
int null_file_checker(FILE*);
void get_id(char*);
void sort_list(item_node*, sort_type);
item_node* create_temp_list();
void show_sorted_items(sort_type sorting_type);

int main()
{
	int choice;

    load_data_from_file();

	do
    {
        print_options();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice)
        {
            case 1:
                add_item();
                save_data_to_file();
                break;

            case 2:
                show_all_items(head, NO_SORT);
                break;

            case 3:
            case 4:
            case 5:
                modify_item_details(choice);
                save_data_to_file();
                break;

            case 6:
                show_sorted_items(SORT_BY_NAME);
                break;

            case 7:
                show_sorted_items(SORT_BY_PRICE);
                break;

            case 8:
                save_data_to_file();
                clear_data_in_list(head);
                head = NULL;
                printf("\nData saved. Program exited.\n");
                break;

            default:
                printf("Invalid option!\n");
        }

    } while (choice != 8);

    return 0;
}

void print_options()
{
    printf("\n----- INVENTORY MANAGEMENT -----\n");
    printf("1. Add Item\n");
    printf("2. Show All Items\n");
    printf("3. Modify Item Name\n");
    printf("4. Modify Item Price\n");
    printf("5. Delete an Item\n");
    printf("6. Show Items Sorted by Name\n");
    printf("7. Show Items Sorted by Price\n");
    printf("8. Save & Exit\n");

    printf("\nEnter choice: ");
}

void add_item()
{
    item_node* temp;
	item_node* new_item = (item_node*)malloc(sizeof(item_node));

	printf("\nEnter the item id: ");
	scanf("%24s", new_item->item_data.item_id);
    clear_input_buffer();

    temp = find_item(new_item->item_data.item_id);

    if (temp != NULL)
    {
        printf("Item id already exists\n");
        free(new_item);
        return;
    }

	printf("Enter the item name: ");
	scanf("%24[^\n]", new_item->item_data.item_name);
    clear_input_buffer();

	printf("Enter the item price: ");
	scanf("%f", &new_item->item_data.item_price);
    clear_input_buffer();

	new_item->next = NULL;

	append_item(new_item);

    printf("\nItem added successfully\n");
}

void append_item(item_node *new_item_node)
{
	item_node *temp;

    if (head == NULL)
    {
        head = new_item_node;
    }
    else
    {
        temp = get_last_node();
        temp->next = new_item_node;
    }
}

void show_all_items(item_node* head_node, sort_type sorting_type)
{
	item_node* temp = head_node;

    if (null_node_checker(temp))
    {
        printf(LIST_EMPTY);
        return;
    }

    printf("\n\tItems List ");

    if (sorting_type == SORT_BY_NAME)
    {
        printf("(sorted by name)");
    }
    
    if (sorting_type == SORT_BY_PRICE)
    {
        printf("(sorted by price)");
    }

    while (temp != NULL)
    {
        printf("\n\nItem id   : %s\nItem name : %s\nItem price: %.2f\n", temp->item_data.item_id, temp->item_data.item_name, temp->item_data.item_price);
        temp = temp->next;
    }
}

void modify_item_details(int choice)
{
    char id[SIZE];
    item_node *target_node;
    int item_deleted = 0;

    if (null_node_checker(head))
    {
        printf(LIST_EMPTY);
        return;
    }

    get_id(id);

    target_node = find_item(id);

    if (null_node_checker(target_node))
    {
        printf(ITEM_NOT_FOUND);
        return;
    }

    clear_input_buffer();

    switch (choice)
    {
        case 3:
            printf("Enter new item name: ");
            scanf("%24[^\n]", target_node->item_data.item_name);
            clear_input_buffer();
            break;

        case 4:
            printf("Enter new item price: ");
            scanf("%f", &target_node->item_data.item_price);
            clear_input_buffer();
            break;

        case 5:
            delete_item(target_node);
            item_deleted++;
            break;
    }
    
    if (item_deleted == 0)
    {
        printf("\nItem updated successfully\n");
    }
}

void get_id(char *id)
{
    printf("Enter item id: ");
    scanf("%24s", id);
}

item_node* find_item(char id[])
{
    item_node* temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->item_data.item_id, id) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void delete_item(item_node* target_node)
{
    item_node **indirect = &head;

    while (*indirect != NULL && *indirect != target_node)
    {
        indirect = &(*indirect)->next;
    }

    *indirect = target_node->next;
    free(target_node);

    printf("\nItem deleted successfully\n");
}

void save_data_to_file()
{
    FILE *fp_items = fopen(DATAFILE, "wb");
    item_node *temp = head;

    if (null_file_checker(fp_items))
    {
        return;
    }

    while (temp != NULL)
    {
        fwrite(&temp->item_data, item_record_size, 1, fp_items);
        temp = temp->next;
    }

    fclose(fp_items);
}

item_node* get_last_node()
{
    item_node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

int null_file_checker(FILE* fp_items)
{
	if (fp_items == NULL)
	{
		printf("File not found");
        return 1;
	}
    return 0;
}

int null_node_checker(item_node* item_node)
{
	if (item_node == NULL)
    {
        return 1;
    }
    return 0;
}

void load_data_from_file()
{
    FILE *fp_items = fopen(DATAFILE, "rb");
    item_details item_buffer;

    if (null_file_checker(fp_items))
    {
        return;
    }

    while (fread(&item_buffer, item_record_size, 1, fp_items))
    {
        item_node *new_item = (item_node*)malloc(sizeof(item_node));
        new_item->item_data = item_buffer;
        new_item->next = NULL;
        append_item(new_item);
    }

    fclose(fp_items);
}

void clear_data_in_list(item_node* head_node)
{
    item_node *temp;

    while (head_node != NULL)
    {
        temp = head_node;
        head_node = head_node->next;
        free(temp);
    }
}

item_node* create_temp_list()
{
    item_node* temp_head = NULL;
    item_node* temp_tail = NULL;
    item_node* current_item = head;

    if (null_node_checker(current_item))
    {
        printf(LIST_EMPTY);
        return NULL;
    }
    
    while (current_item != NULL)
    {
        item_node* new_node = (item_node*)malloc(sizeof(item_node));
        new_node->item_data = current_item->item_data;
        new_node->next = NULL;

        if (temp_head == NULL)
        {
            temp_head = new_node;
            temp_tail = new_node;
        }
        else
        {
            temp_tail->next = new_node;
            temp_tail = new_node;
        }
        current_item = current_item->next;
    }

    return temp_head;    
}

void sort_list(item_node *temp_head, sort_type sorting_type)
{
    item_node *current_item;
    item_node *next_item;
    item_details temp_item_details;
    
    for (current_item = temp_head; current_item->next != NULL; current_item = current_item->next)
    {
        for (next_item = current_item->next; next_item != NULL; next_item = next_item->next)
        {
            if ((sorting_type == SORT_BY_NAME && strcmp(current_item->item_data.item_name, next_item->item_data.item_name) > 0) || (sorting_type == SORT_BY_PRICE && current_item->item_data.item_price > next_item->item_data.item_price))
            {
                temp_item_details = current_item->item_data;
                current_item->item_data = next_item->item_data;
                next_item->item_data = temp_item_details;
            }   
        }    
    } 
}

void show_sorted_items(sort_type sorting_type)
{
    item_node *temp_head = create_temp_list();
    
    if (null_node_checker(temp_head))
    {
        return;
    }
    sort_list(temp_head, sorting_type);
    show_all_items(temp_head, sorting_type);
    clear_data_in_list(temp_head);
}