/*
Singly Circular Linked List in C with a menu-driven interface for performing all essential operations:

Essential Operations we'll implement:

    Insert at Beginning

    Insert at End

    Insert After a Node (by key)

    Delete from Beginning

    Delete from End

    Delete by Value

    Search for a Value

    Display List

    Exit

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertAfter(int key, int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key " << key << " not found.\n";
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
        }
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
            cout << "Deleted " << temp->data << " from end.\n";
            delete temp;
            return;
        }
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        cout << "Deleted " << temp->data << " from end.\n";
        delete temp;
    }

    void deleteByValue(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                cout << "Deleted " << key << ".\n";
                return;
            }
            Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            delete head;
            head = last->next;
            cout << "Deleted " << key << ".\n";
            return;
        }
        Node* prev = nullptr;
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                cout << "Deleted " << key << ".\n";
                return;
            }
        } while (temp != head);
        cout << "Value " << key << " not found.\n";
    }

    void search(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Value " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Value " << key << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, key;
    while (true) {
        cout << "\n--- Singly Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete by Value\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                cll.insertAfter(key, value);
                break;
            case 4:
                cll.deleteFromBeginning();
                break;
            case 5:
                cll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                cll.deleteByValue(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cll.search(value);
                break;
            case 8:
                cll.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}