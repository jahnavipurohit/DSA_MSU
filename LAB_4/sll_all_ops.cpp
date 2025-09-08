#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList(): head(nullptr) {}

    Node* createNode(int v) { return new Node(v); }

    void insertAtBeginning(int v) {
        Node* n = createNode(v);
        n->next = head; head = n;
    }

    void insertAtEnd(int v) {
        Node* n = createNode(v);
        if (!head) { head = n; return; }
        Node* t = head; while (t->next) t = t->next;
        t->next = n;
    }

    void insertAtPosition(int v, int pos) { // 0-based
        if (pos == 0) { insertAtBeginning(v); return; }
        Node* n = createNode(v);
        Node* t = head;
        for (int i=0;i<pos-1;i++) {
            if (!t) { cout<<"Invalid position!\n"; delete n; return; }
            t = t->next;
        }
        if (!t) { cout<<"Invalid position!\n"; delete n; return; }
        n->next = t->next; t->next = n;
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* tmp = head; head = head->next;
        cout<<"Deleted "<<tmp->data<<" from beginning.\n";
        delete tmp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { cout<<"Deleted "<<head->data<<" from end.\n"; delete head; head=nullptr; return; }
        Node* t = head;
        while (t->next->next) t = t->next;
        cout<<"Deleted "<<t->next->data<<" from end.\n";
        delete t->next; t->next = nullptr;
    }

    void deleteByValue(int key) {
        if (!head) return;
        if (head->data == key) { Node* tmp=head; head=head->next; cout<<"Deleted "<<key<<".\n"; delete tmp; return; }
        Node* t=head;
        while (t->next && t->next->data!=key) t=t->next;
        if (!t->next) { cout<<"Value "<<key<<" not found.\n"; return; }
        Node* del=t->next; t->next=del->next; cout<<"Deleted "<<key<<".\n"; delete del;
    }

    bool search(int key) {
        Node* t=head; int pos=0;
        while (t) { if (t->data==key) { cout<<"Found "<<key<<" at position "<<pos<<".\n"; return true; } t=t->next; pos++; }
        cout<<key<<" not found.\n"; return false;
    }

    void display() const {
        if (!head) { cout<<"List is empty.\n"; return; }
        Node* t=head;
        while (t) { cout<<t->data; t=t->next; if (t) cout<<" -> "; }
        cout<<"\n";
    }

    ~SinglyLinkedList() { while (head) { Node* t=head; head=head->next; delete t; } }
};

int main() {
    SinglyLinkedList list;
    int ch,v,pos;
    while (true) {
        cout<<"\n--- SLL Menu ---\n"
            <<"1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n"
            <<"4.Delete from Beginning\n5.Delete from End\n6.Delete a Node\n"
            <<"7.Search\n8.Display\n9.Exit\nEnter choice: ";
        if (!(cin>>ch)) break;
        switch(ch){
            case 1: cout<<"Value: "; cin>>v; list.insertAtBeginning(v); break;
            case 2: cout<<"Value: "; cin>>v; list.insertAtEnd(v); break;
            case 3: cout<<"Value: "; cin>>v; cout<<"Position (0-based): "; cin>>pos; list.insertAtPosition(v,pos); break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: cout<<"Value to delete: "; cin>>v; list.deleteByValue(v); break;
            case 7: cout<<"Value to search: "; cin>>v; list.search(v); break;
            case 8: list.display(); break;
            case 9: return 0;
            default: cout<<"Invalid.\n";
        }
    }
    return 0;
}
