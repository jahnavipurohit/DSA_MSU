/* Doubly Circular Linked List in C++.
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

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList();
    ~DoublyCircularLinkedList();

    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void deleteFromBeginning();
    void deleteFromEnd();
    void displayForward();
    void displayBackward();
};

// Constructor
DoublyCircularLinkedList::DoublyCircularLinkedList() {
    head = nullptr;
}

// Destructor
DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    if (!head) return;
    Node* temp = head;
    do {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);
}

// Insert at beginning
void DoublyCircularLinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void DoublyCircularLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

// Delete from beginning
void DoublyCircularLinkedList::deleteFromBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* last = head->prev;
        Node* temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete temp;
    }
}

// Delete from end
void DoublyCircularLinkedList::deleteFromEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* last = head->prev;
        Node* secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        delete last;
    }
}

// Display forward
void DoublyCircularLinkedList::displayForward() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Display backward
void DoublyCircularLinkedList::displayBackward() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* last = head->prev;
    Node* temp = last;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != last);
    cout << endl;
}

// Menu Driven Main
int main() {
    DoublyCircularLinkedList list;
    int choice, val;

    do {
        cout << "\n--- Doubly Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            list.deleteFromBeginning();
            break;
        case 4:
            list.deleteFromEnd();
            break;
        case 5:
            list.displayForward();
            break;
        case 6:
            list.displayBackward();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}