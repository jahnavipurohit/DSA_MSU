#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Q7: DLL Node */
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

/* Q8: Prototypes */
struct DNode* createDNode(int value);
struct DNode* insertAtBeginning_DLL(struct DNode* head, int value);
struct DNode* insertAtEnd_DLL(struct DNode* head, int value);
struct DNode* insertAtPosition_DLL(struct DNode* head, int value, int pos);
struct DNode* deleteFromBeginning_DLL(struct DNode* head);
struct DNode* deleteFromEnd_DLL(struct DNode* head);
struct DNode* deleteAtPosition_DLL(struct DNode* head, int pos);
bool search_DLL(struct DNode* head, int key);
void displayForward_DLL(struct DNode* head);
void displayBackward_DLL(struct DNode* head);

/* Q9/Q10: Implementations per algorithms */

struct DNode* createDNode(int value) {
    struct DNode* n = (struct DNode*)calloc(1, sizeof(struct DNode));
    if (!n) { printf("Memory allocation failed!\n"); exit(1); }
    n->data = value; n->prev = NULL; n->next = NULL;
    return n;
}

struct DNode* insertAtBeginning_DLL(struct DNode* head, int value) {
    struct DNode* n = createDNode(value);
    n->next = head; n->prev = NULL;
    if (head) head->prev = n;
    head = n; return head;
}

struct DNode* insertAtEnd_DLL(struct DNode* head, int value) {
    struct DNode* n = createDNode(value);
    if (!head) return n;
    struct DNode* t = head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
    return head;
}

struct DNode* insertAtPosition_DLL(struct DNode* head, int value, int pos) {
    if (pos == 0) return insertAtBeginning_DLL(head, value);
    struct DNode* n = createDNode(value);
    struct DNode* t = head;
    for (int i=0;i<pos-1;i++) {
        if (!t) { printf("Invalid position!\n"); free(n); return head; }
        t = t->next;
    }
    if (!t) { printf("Invalid position!\n"); free(n); return head; }
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
    return head;
}

struct DNode* deleteFromBeginning_DLL(struct DNode* head) {
    if (!head) return NULL;
    struct DNode* tmp = head;
    head = head->next;
    if (head) head->prev = NULL;
    printf("Deleted %d from beginning.\n", tmp->data);
    free(tmp);
    return head;
}

struct DNode* deleteFromEnd_DLL(struct DNode* head) {
    if (!head) return NULL;
    if (!head->next) { printf("Deleted %d from end.\n", head->data); free(head); return NULL; }
    struct DNode* t = head;
    while (t->next) t = t->next;
    printf("Deleted %d from end.\n", t->data);
    t->prev->next = NULL;
    free(t);
    return head;
}

struct DNode* deleteAtPosition_DLL(struct DNode* head, int pos) {
    if (!head) return NULL;
    if (pos == 0) return deleteFromBeginning_DLL(head);
    struct DNode* t = head;
    for (int i=0;i<pos;i++) {
        if (!t) { printf("Invalid position!\n"); return head; }
        t = t->next;
    }
    if (!t) { printf("Invalid position!\n"); return head; }
    t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    printf("Deleted %d at position %d.\n", t->data, pos);
    free(t);
    return head;
}

bool search_DLL(struct DNode* head, int key) {
    int pos=0;
    while (head) {
        if (head->data == key) { printf("Found %d at position %d.\n", key, pos); return true; }
        head = head->next; pos++;
    }
    printf("%d not found.\n", key);
    return false;
}

void displayForward_DLL(struct DNode* head) {
    if (!head) { printf("List is empty.\n"); return; }
    printf("Forward: ");
    while (head) { printf("%d", head->data); head=head->next; if (head) printf(" <-> "); }
    printf("\n");
}

void displayBackward_DLL(struct DNode* head) {
    if (!head) { printf("List is empty.\n"); return; }
    struct DNode* t=head; while (t->next) t=t->next;
    printf("Backward: ");
    while (t) { printf("%d", t->data); t=t->prev; if (t) printf(" <-> "); }
    printf("\n");
}

/* Q11: Menu-driven main */
int main() {
    struct DNode* head = NULL;
    int ch,val,pos;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n");
        printf("4.Delete from Beginning\n5.Delete from End\n6.Delete at Position\n");
        printf("7.Search\n8.Display Forward\n9.Display Backward\n10.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d",&ch)!=1) break;

        switch (ch) {
            case 1: printf("Value: "); scanf("%d",&val); head=insertAtBeginning_DLL(head,val); break;
            case 2: printf("Value: "); scanf("%d",&val); head=insertAtEnd_DLL(head,val); break;
            case 3: printf("Value: "); scanf("%d",&val); printf("Position (0-based): "); scanf("%d",&pos);
                    head=insertAtPosition_DLL(head,val,pos); break;
            case 4: head=deleteFromBeginning_DLL(head); break;
            case 5: head=deleteFromEnd_DLL(head); break;
            case 6: printf("Position (0-based): "); scanf("%d",&pos); head=deleteAtPosition_DLL(head,pos); break;
            case 7: printf("Key: "); scanf("%d",&val); search_DLL(head,val); break;
            case 8: displayForward_DLL(head); break;
            case 9: displayBackward_DLL(head); break;
            case 10:
                printf("Exiting.\n");
                while (head) head = deleteFromBeginning_DLL(head);
                return 0;
            default: printf("Invalid.\n");
        }
    }
    return 0;
}
