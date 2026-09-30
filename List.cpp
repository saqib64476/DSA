#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


// ================= DISPLAY =================

void display(Node* head)
{
    Node* p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}


// ================= INSERT AT START =================

void insertAtStart(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}


// ================= INSERT AT END =================

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = newNode;
    }
}


// ================= INSERT AT SPECIFIC POSITION =================

void insertAtPosition(Node*& head, int value, int position)
{
    if (position == 1)
    {
        insertAtStart(head, value);
    }
    else
    {
        Node* newNode = new Node();

        newNode->data = value;

        Node* p = head;

        int i = 1;

        while (i < position - 1 && p != NULL)
        {
            p = p->next;
            i++;
        }

        if (p == NULL)
        {
            cout << "Invalid position" << endl;
            delete newNode;
        }
        else
        {
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}


// ================= DELETE AT START =================

void deleteAtStart(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node* p = head;

        head = head->next;

        delete p;
    }
}


// ================= DELETE AT END =================

void deleteAtEnd(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }

    else
    {
        Node* p = head;

        while (p->next->next != NULL)
        {
            p = p->next;
        }

        delete p->next;

        p->next = NULL;
    }
}


// ================= DELETE AT SPECIFIC POSITION =================

void deleteAtPosition(Node*& head, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    else if (position == 1)
    {
        deleteAtStart(head);
    }

    else
    {
        Node* p = head;

        int i = 1;

        while (i < position - 1 && p->next != NULL)
        {
            p = p->next;
            i++;
        }

        if (p->next == NULL)
        {
            cout << "Invalid position" << endl;
        }

        else
        {
            Node* temp = p->next;

            p->next = temp->next;

            delete temp;
        }
    }
}


// ================= REVERSE LIST =================

void reverseList(Node*& head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;

        current->next = previous;

        previous = current;

        current = nextNode;
    }

    head = previous;
}


// ================= DISPLAY REVERSE =================

void displayReverse(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    displayReverse(head->next);

    cout << head->data << " ";
}


// ================= REMOVE ALL OCCURRENCES =================

void removeAll(Node*& head, int value)
{
    // Remove from beginning
    while (head != NULL && head->data == value)
    {
        Node* temp = head;

        head = head->next;

        delete temp;
    }


    // Remove from remaining list
    Node* p = head;

    while (p != NULL && p->next != NULL)
    {
        if (p->next->data == value)
        {
            Node* temp = p->next;

            p->next = temp->next;

            delete temp;
        }
        else
        {
            p = p->next;
        }
    }
}


// ================= REMOVE DUPLICATES =================

void removeDuplicates(Node*& head)
{
    Node* p = head;

    while (p != NULL)
    {
        Node* temp = p;

        while (temp->next != NULL)
        {
            if (temp->next->data == p->data)
            {
                Node* duplicate = temp->next;

                temp->next = duplicate->next;

                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }

        p = p->next;
    }
}


// ================= MERGE TWO LISTS INTO THIRD LIST =================

void mergeLists(Node* head1, Node* head2, Node*& head3)
{
    // Copy first list
    Node* p = head1;

    while (p != NULL)
    {
        insertAtEnd(head3, p->data);

        p = p->next;
    }


    // Copy second list
    p = head2;

    while (p != NULL)
    {
        insertAtEnd(head3, p->data);

        p = p->next;
    }
}


// ================= MAIN =================

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;


    // -------- FIRST LIST --------

    insertAtEnd(head1, 10);
    insertAtEnd(head1, 20);
    insertAtEnd(head1, 30);
    insertAtEnd(head1, 20);
    insertAtEnd(head1, 40);

    cout << "List 1: ";
    display(head1);


    // -------- SECOND LIST --------

    insertAtEnd(head2, 50);
    insertAtEnd(head2, 30);
    insertAtEnd(head2, 60);
    insertAtEnd(head2, 50);

    cout << "List 2: ";
    display(head2);


    // -------- INSERT AT START --------

    insertAtStart(head1, 5);

    cout << "After inserting 5 at start: ";
    display(head1);


    // -------- INSERT AT END --------

    insertAtEnd(head1, 70);

    cout << "After inserting 70 at end: ";
    display(head1);


    // -------- INSERT AT POSITION --------

    insertAtPosition(head1, 25, 4);

    cout << "After inserting 25 at position 4: ";
    display(head1);


    // -------- DELETE AT START --------

    deleteAtStart(head1);

    cout << "After deleting from start: ";
    display(head1);


    // -------- DELETE AT END --------

    deleteAtEnd(head1);

    cout << "After deleting from end: ";
    display(head1);


    // -------- DELETE AT POSITION --------

    deleteAtPosition(head1, 3);

    cout << "After deleting position 3: ";
    display(head1);


    // -------- REMOVE ALL OCCURRENCES --------

    removeAll(head1, 20);

    cout << "After removing all 20s: ";
    display(head1);


    // -------- MERGE --------

    mergeLists(head1, head2, head3);

    cout << "Merged List 3: ";
    display(head3);


    // -------- REMOVE DUPLICATES --------

    removeDuplicates(head3);

    cout << "List 3 after removing duplicates: ";
    display(head3);


    // -------- REVERSE --------

    reverseList(head3);

    cout << "List 3 after reversing: ";
    display(head3);


    // -------- DISPLAY REVERSE --------

    cout << "List 3 in reverse display: ";
    displayReverse(head3);

    cout << endl;


    return 0;
}
