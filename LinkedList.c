#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void begInsert()
{
    int dataElement;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to be Inserted : ");
    scanf("%d", &dataElement);
    ptr->data = dataElement;
    ptr->next = head;
    head = ptr;
    printf("Node Inserted\n");
}

void indexInsert()
{
    int dataElement, index;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to be Inserted : ");
    scanf("%d", &dataElement);
    ptr->data = dataElement;
    printf("Enter index : ");
    scanf("%d", &index);
    struct Node *cell = head;
    for (int i = 0; i < index; i++)
    {
        if (cell == NULL)
        {
            printf("\nInvalid Index");
        }
        else
        {
            cell = cell->next;
        }
    }

    ptr->next = cell->next;
    cell->next = ptr;
}

void lastInsert()
{
    int dataElement;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to be Inserted : ");
    scanf("%d", &dataElement);
    ptr->data = dataElement;
    ptr->next = NULL;
    struct Node *cell = head;
    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        while (cell->next != NULL)
        {
            cell = cell->next;
        }
        cell->next = ptr;
    }

    printf("Node Inserted\n");
}

void displayList()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void begDelete()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("ALready Empty");
    }
    else
    {
        head = ptr->next;
        free(ptr);
        printf("Node Deleted\n");
    }
}

void lastDelete()
{
    struct Node *ptr = head;
    struct Node *backptr = head;
    if (head == NULL)
    {
        printf("ALready Empty");
    }
    else
    {
        ptr = head->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            backptr = backptr->next;
        }
        backptr->next = NULL;
        free(ptr);
        printf("Node Deleted\n");
    }
}
int main()
{
    int choice;
    while (choice != 8)
    {
        printf("\n1 : Insert at Beginning\n2 : Insert at Index\n3 : Insert at Last\n4 : Display List\n5 : Delete from Beginning\n7 : Delete from Last\n8 : Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            begInsert();
            break;
        case 2:
            indexInsert();
            break;
        case 3:
            lastInsert();
            break;
        case 4:
            displayList();
            break;
        case 5:
            begDelete();
            break;
        case 7:
            lastDelete();
            break;
        case 8:
            exit;

        default:
            break;
        }
    }
}