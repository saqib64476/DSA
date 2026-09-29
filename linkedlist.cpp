#include <iostream>
using namespace std;

int main() {
   struct Node{
   int data;
   Node* next;
   };

   Node* head = new Node();
   Node* first = new Node();
   Node* second = new Node();


   head->data=10;
   head->next=first;
   first->data=20;
   first->next=second;
    second->data=30;
    second->next=NULL;
    Node* newNode = new Node();
    newNode->data=5;
    newNode->next=head;
    head=newNode;


Node* temp = head;
while(temp!= NULL){
    cout<<temp->data;
    cout<<" ";
   temp= temp->next;
}


    return 0;
}
