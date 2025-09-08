#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for a term in the polynomial
struct Node {
    int coeff;  // Coefficient
    int pow;    // Power
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to create a polynomial
void createPolynomial(struct Node** poly) {
    int n, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        insertTerm(poly, coeff, pow);
    }
}

// Function to display polynomial
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%d*x^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to evaluate polynomial for given x
double evaluatePolynomial(struct Node* poly, double x) {
    double result = 0.0;
    while (poly != NULL) {
        result += poly->coeff * pow(x, poly->pow);
        poly = poly->next;
    }
    return result;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertTerm(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow) {
            insertTerm(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            insertTerm(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    double x;

    printf("Create first polynomial:\n");
    createPolynomial(&poly1);
    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("\nCreate second polynomial:\n");
    createPolynomial(&poly2);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add polynomials
    sum = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(sum);

    // Evaluate
    printf("\nEnter value of x to evaluate first polynomial: ");
    scanf("%lf", &x);
    printf("Value of first polynomial at x=%.2lf: %.2lf\n", x, evaluatePolynomial(poly1, x));

    printf("\nEnter value of x to evaluate second polynomial: ");
    scanf("%lf", &x);
    printf("Value of second polynomial at x=%.2lf: %.2lf\n", x, evaluatePolynomial(poly2, x));

    return 0;
}