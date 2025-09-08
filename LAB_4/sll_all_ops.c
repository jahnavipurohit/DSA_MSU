#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Q1: Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Q2: Function prototypes */
struct Node* createNode(int value);
struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAtPosition(struct Node* head, int value, int pos); /* 0-based */
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteByValue(struct Node* head, int key);
bool searchElement(struct Node* head, int key);
void displayList(struct Node* head);

/* Q3: Implementations per algorithm */

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)calloc(1, sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); exit(1); }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 0) return insertAtBeginning(head, value);
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteByValue(struct Node* head, int key) {
    if (head == NULL) return NULL;
    if (head->data == key) {
        struct Node* tmp = head;
        head = head->next;
        printf("Deleted %d.\n", tmp->data);
        free(tmp);
        return head;
    }
    struct Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    printf("Deleted %d.\n", del->data);
    free(del);
    return head;
}

bool searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found %d at position %d.\n", key, pos);
            return true;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found.\n", key);
    return false;
}

void displayList(struct Node* head) {
    if (!head) { printf("List is empty.\n"); return; }
    printf("List: ");
    while (head) {
        printf("%d", head->data);
        head = head->next;
        if (head) printf(" -> ");
    }
    printf("\n");
}

/* Q4: Menu-driven main */
int main() {
    struct Node* head = NULL;
    int choice, val, pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete a Node (by value)\n");
        printf("7. Search an Element\n8. Display List\n9. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val);
                head = insertAtBeginning(head, val);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;
            case 3:
                printf("Enter value: "); scanf("%d", &val);
                printf("Enter 0-based position: "); scanf("%d", &pos);
                head = insertAtPosition(head, val, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter value to delete: "); scanf("%d", &val);
                head = deleteByValue(head, val);
                break;
            case 7:
                printf("Enter value to search: "); scanf("%d", &val);
                searchElement(head, val);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting.\n");
                /* free all nodes */
                while (head) head = deleteFromBeginning(head);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
