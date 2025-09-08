#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v): data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList(): head(nullptr) {}

    DNode* createNode(int v) { return new DNode(v); }

    void insertAtBeginning(int v) {
        DNode* n = createNode(v);
        n->next = head; n->prev = nullptr;
        if (head) head->prev = n;
        head = n;
    }

    void insertAtEnd(int v) {
        DNode* n = createNode(v);
        if (!head) { head = n; return; }
        DNode* t=head; while (t->next) t=t->next;
        t->next = n; n->prev = t;
    }

    void insertAtPosition(int v, int pos) { // 0-based
        if (pos==0) { insertAtBeginning(v); return; }
        DNode* n = createNode(v);
        DNode* t=head;
        for (int i=0;i<pos-1;i++) {
            if (!t) { cout<<"Invalid position!\n"; delete n; return; }
            t=t->next;
        }
        if (!t) { cout<<"Invalid position!\n"; delete n; return; }
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }

    void deleteFromBeginning() {
        if (!head) return;
        DNode* tmp=head; head=head->next;
        if (head) head->prev=nullptr;
        cout<<"Deleted "<<tmp->data<<" from beginning.\n";
        delete tmp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { cout<<"Deleted "<<head->data<<" from end.\n"; delete head; head=nullptr; return; }
        DNode* t=head; while (t->next) t=t->next;
        cout<<"Deleted "<<t->data<<" from end.\n";
        t->prev->next=nullptr; delete t;
    }

    void deleteAtPosition(int pos) {
        if (!head) return;
        if (pos==0) { deleteFromBeginning(); return; }
        DNode* t=head;
        for (int i=0;i<pos;i++) {
            if (!t) { cout<<"Invalid position!\n"; return; }
            t=t->next;
        }
        if (!t) { cout<<"Invalid position!\n"; return; }
        t->prev->next = t->next;
        if (t->next) t->next->prev = t->prev;
        cout<<"Deleted "<<t->data<<" at position "<<pos<<".\n";
        delete t;
    }

    bool search(int key) {
        int pos=0; DNode* t=head;
        while (t) { if (t->data==key) { cout<<"Found "<<key<<" at position "<<pos<<".\n"; return true; } t=t->next; pos++; }
        cout<<key<<" not found.\n"; return false;
    }

    void displayForward() const {
        if (!head) { cout<<"List is empty.\n"; return; }
        DNode* t=head;
        cout<<"Forward: ";
        while (t) { cout<<t->data; t=t->next; if (t) cout<<" <-> "; }
        cout<<"\n";
    }

    void displayBackward() const {
        if (!head) { cout<<"List is empty.\n"; return; }
        DNode* t=head; while (t->next) t=t->next;
        cout<<"Backward: ";
        while (t) { cout<<t->data; t=t->prev; if (t) cout<<" <-> "; }
        cout<<"\n";
    }

    ~DoublyLinkedList() { while (head) { DNode* t=head; head=head->next; delete t; } }
};

int main() {
    DoublyLinkedList list;
    int ch,v,pos;
    while (true) {
        cout<<"\n--- DLL Menu ---\n"
            <<"1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n"
            <<"4.Delete from Beginning\n5.Delete from End\n6.Delete at Position\n"
            <<"7.Search\n8.Display Forward\n9.Display Backward\n10.Exit\nEnter choice: ";
        if (!(cin>>ch)) break;
        switch (ch) {
            case 1: cout<<"Value: "; cin>>v; list.insertAtBeginning(v); break;
            case 2: cout<<"Value: "; cin>>v; list.insertAtEnd(v); break;
            case 3: cout<<"Value: "; cin>>v; cout<<"Position (0-based): "; cin>>pos; list.insertAtPosition(v,pos); break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: cout<<"Position (0-based): "; cin>>pos; list.deleteAtPosition(pos); break;
            case 7: cout<<"Key: "; cin>>v; list.search(v); break;
            case 8: list.displayForward(); break;
            case 9: list.displayBackward(); break;
            case 10: return 0;
            default: cout<<"Invalid.\n";
        }
    }
    return 0;
}
