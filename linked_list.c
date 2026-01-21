#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create_list();
void display();
void insert_begin();
void insert_end();
void insert_position();
void delete_begin();
void delete_end();
void delete_position();

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create_list(); 
                break;
            case 2: 
                display(); 
                break;
            case 3: 
                insert_begin();
                break;
            case 4: 
                insert_end();
                break;
            case 5:
                insert_position();
                break;
            case 6: 
                delete_begin();
                break;
            case 7: 
                delete_end(); 
                break;
            case 8: 
                delete_position(); 
                break;
            case 9: 
                exit(0);
            default: 
                printf("Invalid choice!\n");
        }
    }
}

void create_list()
{
    struct node *newnode, *temp;
    int value, choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter value: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("\nAdd another node? (1/0): ");
        scanf("%d", &choice);
    }
}

void display()
{   
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert_begin()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    struct node *newnode, *temp; 
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert_position()
{
    struct node *newnode, *temp;
    int value, position, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &position);

    temp = head;
    for (i = 1; i < position - 1; i++)
    {
        if (temp->next == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void delete_position()
{
    struct node *temp, *prev;
    int position, i;

    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 1)
    {
        delete_begin();
        return;
    }

    temp = head;
    for (i = 1; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nInvalid position\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}