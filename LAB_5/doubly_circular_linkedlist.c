/* Doubly Circular Linked List in C .
Essential Operations for Doubly Circular Linked List

    Insert at Beginning

    Insert at End

    Insert After a Node (by key)

    Delete from Beginning

    Delete from End

    Delete by Value

    Search for a Value

    Display Forward

    Display Backward

    Exit


*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Create new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at Beginning
void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        head->next = head->prev = head;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

// Insert at End
void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        head->next = head->prev = head;
    }
    else
    {
        struct Node *last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("Inserted %d at end.\n", value);
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
            struct Node *nextNode = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;
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
        struct Node *last = head->prev;
        head = head->next;
        head->prev = last;
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
    struct Node *last = head->prev;
    if (last == head)
    {
        head = NULL;
    }
    else
    {
        struct Node *secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
    }
    printf("Deleted %d from end.\n", last->data);
    free(last);
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
    do
    {
        if (temp->data == key)
        {
            if (temp->next == temp)
            {
                head = NULL;
            }
            else
            {
                struct Node *prevNode = temp->prev;
                struct Node *nextNode = temp->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                if (temp == head)
                    head = nextNode;
            }
            printf("Deleted %d.\n", key);
            free(temp);
            return;
        }
        temp = temp->next;
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

// Display Forward
void displayForward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Forward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Display Backward
void displayBackward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head->prev;
    printf("Backward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\n--- Doubly Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete by Value\n");
        printf("7. Search\n8. Display Forward\n9. Display Backward\n10. Exit\n");
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
            displayForward();
            break;
        case 9:
            displayBackward();
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}