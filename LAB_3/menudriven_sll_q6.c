//singlylinkedlist_menudriven.c
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the singly linked list
struct Node {
int data; // data to store
struct Node* next; // pointer to the next node
};

// Global pointer to the head of the list
struct Node* head = NULL;

// Function declarations
void insertAtBeginning(int val);
void insertAtEnd(int val);
void deleteFromBeginning();

void deleteFromEnd();
void display();

int main() {
int choice, value;

while (1) {
printf("\n--- Singly Linked List Menu ---\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Delete from Beginning\n");
printf("4. Delete from End\n");
printf("5. Display\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

// Menu-driven interface
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
insertAtBeginning(value);
break;

case 2:
printf("Enter value to insert: ");
scanf("%d", &value);
insertAtEnd(value);
break;

case 3:

deleteFromBeginning();
break;

case 4:
deleteFromEnd();
break;

case 5:
display();
break;

case 6:
exit(0);

default:
printf("Invalid choice!\n");
}
}

return 0;
}

// Insert a new node at the beginning
void insertAtBeginning(int val) {
// Allocate memory for new node
struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
newNode->data = val; // set data
newNode->next = head; // new node points to current head
head = newNode; // head is updated to new node
}

// Insert a new node at the end

void insertAtEnd(int val) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
newNode->data = val;
newNode->next = NULL; // end node always points to NULL

// If list is empty, new node becomes head
if (head == NULL) {
head = newNode;
return;
}

// Otherwise, traverse to last node
struct Node* temp = head;
while (temp->next != NULL)
temp = temp->next;

temp->next = newNode; // last node points to new node
}

// Delete a node from the beginning
void deleteFromBeginning() {
if (head == NULL) {
printf("List is empty.\n");
return;
}

struct Node* temp = head; // store current head in temp
head = head->next; // move head to next node
free(temp); // delete old head
printf("Deleted from beginning.\n");
}

// Delete a node from the end
void deleteFromEnd() {
if (head == NULL) {
printf("List is empty.\n");
return;
}

// If there's only one node
if (head->next == NULL) {
free(head);
head = NULL;
printf("Deleted last node.\n");
return;
}

// Traverse to second-last node
struct Node* temp = head;
while (temp->next->next != NULL)
temp = temp->next;

free(temp->next); // delete last node
temp->next = NULL; // update next of second last to
NULL
printf("Deleted from end.\n");
}

// Traverse and display the linked list
void display() {
if (head == NULL) {
printf("List is empty.\n");
return;
}

struct Node* temp = head;
printf("List: ");
while (temp != NULL) {
printf("%d -> ", temp->data); // print node data
temp = temp->next; // move to next node
}
printf("NULL\n");
}