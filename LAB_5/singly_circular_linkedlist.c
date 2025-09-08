#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end.\n", value);
}

// Insert After a Node
void insertAfter(int key, int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        if (temp->data == key)
        {
            struct Node *newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d after %d.\n", value, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key %d not found.\n", key);
}

// Delete from Beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
    }
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from End
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head)
    {
        head = NULL;
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// Delete by Value
void deleteByValue(int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Special case for head
    if (head->data == key)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
            printf("Deleted %d.\n", key);
            return;
        }
        struct Node *last = head;
        while (last->next != head)
            last = last->next;
        last->next = head->next;
        free(head);
        head = last->next;
        printf("Deleted %d.\n", key);
        return;
    }

    // General case
    do
    {
        prev = temp;
        temp = temp->next;
        if (temp->data == key)
        {
            prev->next = temp->next;
            free(temp);
            printf("Deleted %d.\n", key);
            return;
        }
    } while (temp != head);
    printf("Value %d not found.\n", key);
}

// Search
void search(int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    int pos = 1;
    do
    {
        if (temp->data == key)
        {
            printf("Value %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value %d not found.\n", key);
}

// Display
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete by Value\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insertAfter(key, value);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}