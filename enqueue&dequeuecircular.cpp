
#include <iostream>
using namespace std;

int arr[100];
int size = 100;

int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % size==front)
    {
        cout<<"Queue is full"<< endl;
        return;
    }

    if (front==-1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear =(rear + 1) % size;
    }

    arr[rear] = value;

    cout<<value<<"inserted" << endl;
}


void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << arr[front] << " deleted" << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}


void display()
{
    if (front==-1)
    {
        cout<<"Queue is empty" << endl;
        return;
    }

    int i=front;

    while (true)
    {
        cout <<arr[i]<< " ";

        if (i==rear)
            break;

        i =(i + 1) % size;
    }

    cout <<endl;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int value;

        cout << "Enter value: ";
        cin >> value;

        enqueue(value);
    }
dequeue();
    display();

    return 0;
}
