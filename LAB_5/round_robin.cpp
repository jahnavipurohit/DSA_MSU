#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int id;
    int burst_time;
    Node* next;

    Node(int pid, int bt);
};

// Node constructor
Node::Node(int pid, int bt) {
    id = pid;
    burst_time = bt;
    next = nullptr;
}

// Circular Linked List class for Round Robin
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList();
    void addProcess(int pid, int burst_time);
    void executeProcesses(int quantum);
    bool isEmpty();
    ~CircularLinkedList();
};

// Constructor
CircularLinkedList::CircularLinkedList() {
    head = nullptr;
}

// Check if empty
bool CircularLinkedList::isEmpty() {
    return head == nullptr;
}

// Add process to the end
void CircularLinkedList::addProcess(int pid, int burst_time) {
    Node* newNode = new Node(pid, burst_time);
    if (!head) {
        head = newNode;
        head->next = head; // Circular
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Process P" << pid << " added with burst time " << burst_time << "\n";
}

// Execute Round Robin
void CircularLinkedList::executeProcesses(int quantum) {
    if (!head) {
        cout << "No processes to execute.\n";
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (head != nullptr) {
        cout << "\nExecuting Process P" << curr->id
             << " (Remaining Burst Time: " << curr->burst_time << ")\n";

        if (curr->burst_time > quantum) {
            curr->burst_time -= quantum;
            cout << "Process P" << curr->id << " executed for " << quantum
                 << " units, Remaining: " << curr->burst_time << "\n";
            prev = curr;
            curr = curr->next;
        } else {
            cout << "Process P" << curr->id << " executed for "
                 << curr->burst_time << " units and completed.\n";

            if (curr == curr->next) { // last process
                delete curr;
                head = nullptr;
                break;
            }

            // Remove completed process
            if (prev == nullptr) { // removing head
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                delete curr;
                curr = head;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
    }
    cout << "\nAll processes completed.\n";
}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    if (!head) return;
    Node* temp = head;
    Node* nextNode;
    do {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);
}

int main() {
    CircularLinkedList cll;
    int n, burst, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter burst time for Process P" << i << ": ";
        cin >> burst;
        cll.addProcess(i, burst);
    }

    cout << "\nEnter Time Quantum: ";
    cin >> quantum;

    cll.executeProcesses(quantum);

    return 0;
}