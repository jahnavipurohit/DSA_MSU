#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    int id;
    int burst_time;
    struct Process *next;
} Process;

Process *head = NULL;

// Function to create a new process node
Process* createProcess(int id, int burst_time) {
    Process *newNode = (Process*)malloc(sizeof(Process));
    newNode->id = id;
    newNode->burst_time = burst_time;
    newNode->next = NULL;
    return newNode;
}

// Add process to circular linked list
void addProcess(int id, int burst_time) {
    Process *newNode = createProcess(id, burst_time);
    if (head == NULL) {
        head = newNode;
        head->next = head; // circular
    } else {
        Process *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Process P%d added with burst time %d\n", id, burst_time);
}

// Execute Round Robin
void executeProcesses(int quantum) {
    if (head == NULL) {
        printf("No processes to execute.\n");
        return;
    }

    Process *curr = head;
    Process *prev = NULL;

    while (head != NULL) {
        printf("\nExecuting Process P%d (Remaining Burst Time: %d)\n", curr->id, curr->burst_time);
        
        if (curr->burst_time > quantum) {
            curr->burst_time -= quantum;
            printf("Process P%d executed for %d units, Remaining: %d\n", curr->id, quantum, curr->burst_time);
            prev = curr;
            curr = curr->next; // Move to next process
        } else {
            printf("Process P%d executed for %d units and completed.\n", curr->id, curr->burst_time);
            
            if (curr == curr->next) { // Only one process left
                free(curr);
                head = NULL;
                break;
            }

            // Remove the completed process
            Process *temp = curr;
            if (prev == NULL) { // removing head
                Process *last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                curr = head;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(temp);
        }
    }
    printf("\nAll processes completed.\n");
}

int main() {
    int n, i, burst, quantum;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        printf("Enter burst time for Process P%d: ", i);
        scanf("%d", &burst);
        addProcess(i, burst);
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);
    
    executeProcesses(quantum);

    return 0;
}