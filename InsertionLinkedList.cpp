#include <iostream>
using namespace std;

// Node
struct Node {
    int data;
    Node* next;
};

// Display Linked List
void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Insert at Beginning
void insertBeginning(Node*& head, int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at End
void insertEnd(Node*& head, int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Middle / Specific Position
void insertMiddle(Node*& head, int value, int pos) {

    // If position is 0, insert at beginning
    if (pos == 0) {
        insertBeginning(head, value);
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;

    Node* temp = head;

    // Go to node before the required position
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


int main() {

    // Creating initial Linked List

    Node* head = new Node();
    head->data = 10;

    Node* second = new Node();
    second->data = 20;

    Node* third = new Node();
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = NULL;


    cout << "Original List: ";
    display(head);


    // =========================
    // INSERTION AT BEGINNING
    // =========================

    insertBeginning(head, 5);

    cout << "After Beginning Insertion: ";
    display(head);


    // =========================
    // INSERTION AT END
    // =========================

    insertEnd(head, 40);

    cout << "After End Insertion: ";
    display(head);


    // =========================
    // INSERTION AT MIDDLE
    // =========================

    insertMiddle(head, 25, 3);

    cout << "After Middle Insertion: ";
    display(head);


    return 0;
}
