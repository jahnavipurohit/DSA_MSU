//singlylinkedlist_menudriven.cpp
#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
int data; // Data in the node
Node* next; // Pointer to next node

// Constructor initializes the data and sets next to nullptr
Node(int val) {
data = val;
next = nullptr;
}
};

// LinkedList class to manage list operations
class LinkedList {
Node* head; // Pointer to the head of the list

public:

LinkedList() { head = nullptr; } // Constructor initializes
head to null

void insertAtBeginning(int val);
void insertAtEnd(int val);
void deleteFromBeginning();
void deleteFromEnd();
void display();
};

// Insert at beginning of list
void LinkedList::insertAtBeginning(int val) {
Node* newNode = new Node(val); // allocate new node with value
newNode->next = head; // link new node to current head
head = newNode; // update head to new node
}

// Insert at end of list
void LinkedList::insertAtEnd(int val) {
Node* newNode = new Node(val); // allocate new node

if (!head) {
head = newNode; // if list is empty
return;
}

Node* temp = head;
while (temp->next != nullptr) // traverse to end
temp = temp->next;

temp->next = newNode; // link last node to new node
}

// Delete first node
void LinkedList::deleteFromBeginning() {
if (!head) {
cout << "List is empty.\n";
return;
}

Node* temp = head;
head = head->next; // move head forward
delete temp; // delete old head
cout << "Deleted from beginning.\n";
}

// Delete last node
void LinkedList::deleteFromEnd() {
if (!head) {
cout << "List is empty.\n";
return;
}

if (!head->next) {
delete head;
head = nullptr;
cout << "Deleted last node.\n";
return;
}

Node* temp = head;
while (temp->next->next != nullptr) // go to second-last node
temp = temp->next;

delete temp->next; // delete last node

temp->next = nullptr; // update second-last node's next
cout << "Deleted from end.\n";
}

// Display the list
void LinkedList::display() {
if (!head) {
cout << "List is empty.\n";
return;
}

Node* temp = head;
cout << "List: ";
while (temp) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL\n";
}

// Main function with menu
int main() {
LinkedList list;
int choice, value;

while (true) {
cout << "\n--- Singly Linked List Menu ---\n";
cout << "1. Insert at Beginning\n";
cout << "2. Insert at End\n";
cout << "3. Delete from Beginning\n";
cout << "4. Delete from End\n";
cout << "5. Display\n";

cout << "6. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

// Switch case for operations
switch (choice) {
case 1:
cout << "Enter value to insert: ";
cin >> value;
list.insertAtBeginning(value);
break;

case 2:
cout << "Enter value to insert: ";
cin >> value;
list.insertAtEnd(value);
break;

case 3:
list.deleteFromBeginning();
break;

case 4:
list.deleteFromEnd();
break;

case 5:
list.display();
break;

case 6:
return 0;

default:
cout << "Invalid choice!\n";
}
}

return 0;
}