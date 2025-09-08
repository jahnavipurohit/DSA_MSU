#include <iostream>
#include <cmath>
using namespace std;

// Node for singly linked list
class Node {
public:
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Polynomial class
class Polynomial {
private:
    Node* head;

public:
    Polynomial();
    ~Polynomial();

    void insertTerm(int coeff, int pow);
    void createPolynomial();
    void displayPolynomial() const;
    double evaluate(double x) const;
    Polynomial add(const Polynomial& other) const;
};

// Constructor
Polynomial::Polynomial() {
    head = nullptr;
}

// Destructor
Polynomial::~Polynomial() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert a term at the end
void Polynomial::insertTerm(int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Create polynomial
void Polynomial::createPolynomial() {
    int n, coeff, pow;
    cout << "Enter number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> pow;
        insertTerm(coeff, pow);
    }
}

// Display polynomial
void Polynomial::displayPolynomial() const {
    if (!head) {
        cout << "0";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->pow;
        temp = temp->next;
        if (temp) cout << " + ";
    }
    cout << endl;
}

// Evaluate polynomial
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    Node* temp = head;
    while (temp) {
        result += temp->coeff * pow(x, temp->pow);
        temp = temp->next;
    }
    return result;
}

// Add two polynomials
Polynomial Polynomial::add(const Polynomial& other) const {
    Polynomial result;
    Node* p1 = head;
    Node* p2 = other.head;

    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            result.insertTerm(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow) {
            result.insertTerm(p2->coeff, p2->pow);
            p2 = p2->next;
        }
        else {
            result.insertTerm(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1) {
        result.insertTerm(p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        result.insertTerm(p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    Polynomial poly1, poly2, sum;
    double x;

    cout << "Create first polynomial:\n";
    poly1.createPolynomial();
    cout << "First Polynomial: ";
    poly1.displayPolynomial();

    cout << "\nCreate second polynomial:\n";
    poly2.createPolynomial();
    cout << "Second Polynomial: ";
    poly2.displayPolynomial();

    // Add polynomials
    sum = poly1.add(poly2);
    cout << "\nSum of Polynomials: ";
    sum.displayPolynomial();

    // Evaluate polynomials
    cout << "\nEnter value of x to evaluate first polynomial: ";
    cin >> x;
    cout << "Value of first polynomial at x=" << x << " : " << poly1.evaluate(x) << endl;

    cout << "\nEnter value of x to evaluate second polynomial: ";
    cin >> x;
    cout << "Value of second polynomial at x=" << x << " : " << poly2.evaluate(x) << endl;

    return 0;
}