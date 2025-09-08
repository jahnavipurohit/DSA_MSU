#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
struct Student {
int rollNo; // Unique identifier (PRN)
char name[50];
char phone[15];
char city[30];

float hscMarks;
struct Student* next;
};

// Global head pointer
struct Student* head = NULL;

// Function to create a new student node
struct Student* createNode() {
struct Student* newNode = (struct Student*)malloc(sizeof(struct
Student));
if (!newNode) {
printf("Memory allocation failed!\n");
exit(1);
}
printf("Enter Roll No (PRN): ");
scanf("%d", &newNode->rollNo);
printf("Enter Name: ");
scanf(" %[^\n]", newNode->name);
printf("Enter Phone No: ");
scanf(" %[^\n]", newNode->phone);
printf("Enter City: ");
scanf(" %[^\n]", newNode->city);
printf("Enter HSC Marks: ");
scanf("%f", &newNode->hscMarks);

newNode->next = NULL;
return newNode;
}

// Insert at the beginning
void insertAtBeginning() {
struct Student* newNode = createNode();

newNode->next = head;
head = newNode;
printf("Record inserted at beginning.\n");
}

// Insert at the end
void insertAtEnd() {
struct Student* newNode = createNode();
if (head == NULL) {
head = newNode;
} else {
struct Student* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
printf("Record inserted at end.\n");
}

// Delete from beginning
void deleteFromBeginning() {
if (head == NULL) {
printf("List is empty! No record to delete.\n");
return;
}
struct Student* temp = head;
head = head->next;
printf("Deleted record of Roll No: %d\n", temp->rollNo);
free(temp);
}

// Delete from end

void deleteFromEnd() {
if (head == NULL) {
printf("List is empty! No record to delete.\n");
return;
}

struct Student* temp = head;

// If only one node
if (head->next == NULL) {
printf("Deleted record of Roll No: %d\n", head->rollNo);
free(head);
head = NULL;
return;
}

// Traverse to second last node
while (temp->next->next != NULL)
temp = temp->next;

printf("Deleted record of Roll No: %d\n", temp->next->rollNo);
free(temp->next);
temp->next = NULL;
}

// Display all records
void displayRecords() {
if (head == NULL) {
printf("No records to display.\n");
return;
}
struct Student* temp = head;

printf("\nStudent Records:\n");
printf("--------------------------------------------------------
----\n");
while (temp != NULL) {
printf("Roll No: %d\n", temp->rollNo);
printf("Name : %s\n", temp->name);
printf("Phone : %s\n", temp->phone);
printf("City : %s\n", temp->city);
printf("HSC Marks: %.2f\n", temp->hscMarks);
printf("----------------------------------------------------
--------\n");
temp = temp->next;
}
}

// Count total records
void countRecords() {
int count = 0;
struct Student* temp = head;
while (temp != NULL) {
count++;
temp = temp->next;
}
printf("Total number of student records: %d\n", count);
}

// Search by Roll No (PRN)
void searchByPRN() {
if (head == NULL) {
printf("List is empty.\n");
return;
}

int key;
printf("Enter Roll No (PRN) to search: ");
scanf("%d", &key);

struct Student* temp = head;
while (temp != NULL) {
if (temp->rollNo == key) {
printf("Record Found:\n");
printf("Name : %s\n", temp->name);
printf("Phone : %s\n", temp->phone);
printf("City : %s\n", temp->city);
printf("HSC Marks: %.2f\n", temp->hscMarks);
return;
}
temp = temp->next;
}
printf("No record found with Roll No: %d\n", key);
}

// Menu function
void menu() {
int choice;
do {
printf("\n===== Student Records Menu =====\n");
printf("1. Insert at Beginning\n");
printf("2. Insert at End\n");
printf("3. Delete from Beginning\n");
printf("4. Delete from End\n");
printf("5. Display Records\n");
printf("6. Count Total Records\n");
printf("7. Search by Roll No (PRN)\n");
printf("0. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);
printf("\n");

switch (choice) {
case 1: insertAtBeginning(); break;
case 2: insertAtEnd(); break;
case 3: deleteFromBeginning(); break;
case 4: deleteFromEnd(); break;
case 5: displayRecords(); break;
case 6: countRecords(); break;
case 7: searchByPRN(); break;
case 0: printf("Exiting...\n"); break;
default: printf("Invalid choice! Try again.\n");
}
} while (choice != 0);
}

// Main function
int main() {
menu();
return 0;
}