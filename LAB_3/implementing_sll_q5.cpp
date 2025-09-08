//singlylinkedlist.cpp
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
list.insertAtBeginning(45);
list.insertAtBeginning(55);
list.insertAtBeginning(65);

list.insertAtEnd(67);
list.insertAtEnd(77);
list.insertAtEnd(87);

list.display();

list.deleteFromBeginning();

list.deleteFromBeginning();

list.display();

list.deleteFromEnd();
list.deleteFromEnd();

list.display();

return 0;
}