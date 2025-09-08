//singlylinkedlist.c
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

insertAtBeginning(45);
insertAtBeginning(55);
insertAtBeginning(65);

insertAtEnd(67);
insertAtEnd(77);
insertAtEnd(87);

display();

deleteFromBeginning();
deleteFromBeginning();

display();

deleteFromEnd();
deleteFromEnd();

display();

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